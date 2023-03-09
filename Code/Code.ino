/* This demo shows how the Zumo can use its gyroscope to detect
when it is being rotated, and use the motors to resist that
rotation.

This code was tested on a Zumo with 4 NiMH batteries and two 75:1
HP micro metal gearmotors.  If you have different batteries or
motors, you might need to adjust the PID constants.

Be careful to not move the robot for a few seconds after starting
it while the gyro is being calibrated.  During the gyro
calibration, the yellow LED is on and the words "Gyro cal" are
shown on the display.

After the gyro calibration is done, press button A to start the
demo.  If you try to turn the Zumo, or put it on a surface that
is turning, it will drive its motors to counteract the turning.

This demo only uses the Z axis of the gyro, so it is possible to
pick up the Zumo, rotate it about its X and Y axes, and then put
it down facing in a new position. */

#include <Wire.h>
#include <Zumo32U4.h>

// This is the maximum speed the motors will be allowed to turn.
// A maxSpeed of 400 lets the motors go at top speed.  Decrease
// this value to impose a speed limit.
const int16_t maxSpeed = 400;

// Change next line to this if you are using the older Zumo 32U4
// with a black and green LCD display:
// Zumo32U4LCD display;

Zumo32U4Motors motors;
Zumo32U4IMU imu;
Zumo32U4OLED display;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Buzzer buzzer;

Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;

#include "TurnSensor.h"

int type = 0;
int direction =0;
bool run = true;
String running = "autoDrive";
String pointing = "front";
long totalFront = 0;
unsigned long frontStartTime;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];
bool useEmitters = true;
uint8_t selectedSensorIndex = 0;
bool detected = false;
int32_t angle;

String mode = "leftWall";


void loadCustomCharacters()
{
  static const char levels[] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63
  };
  display.loadCustomCharacter(levels + 0, 0);  // 1 bar
  display.loadCustomCharacter(levels + 1, 1);  // 2 bars
  display.loadCustomCharacter(levels + 2, 2);  // 3 bars
  display.loadCustomCharacter(levels + 3, 3);  // 4 bars
  display.loadCustomCharacter(levels + 4, 4);  // 5 bars
  display.loadCustomCharacter(levels + 5, 5);  // 6 bars
  display.loadCustomCharacter(levels + 6, 6);  // 7 bars
}

void printBar(uint8_t height)
{
  if (height > 8) { height = 8; }
  const char barChars[] = {' ', 0, 1, 2, 3, 4, 5, 6, (char)255};
  display.print(barChars[height]);
}

// Prints a line with all the sensor readings to the serial
// monitor.
void printReadingsToSerial()
{
  char buffer[80];
  sprintf(buffer, "%4d %4d %4d %4d %4d %c\n",
    lineSensorValues[0],
    lineSensorValues[1],
    lineSensorValues[2],
    lineSensorValues[3],
    lineSensorValues[4],
    useEmitters ? 'E' : 'e'
  );
  Serial.print(buffer);
}

void manualLeft(){
  motors.setRightSpeed(100);
  motors.setLeftSpeed(-100);
}

void manualRight(){
  motors.setRightSpeed(-100);
  motors.setLeftSpeed(100);
}

void manualGo(){
  motors.setRightSpeed(100);
  motors.setLeftSpeed(100);
}

void manualReverse(){
  motors.setRightSpeed(-100);
  motors.setLeftSpeed(-100);
}

void stop(){
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}

int32_t getAngle() {
  // turnAngle is a variable defined in TurnSensor.cpp
  // This fancy math converts the number into degrees turned since the
  // last sensor reset.
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}

void right90(){
  motors.setRightSpeed(-200);
  motors.setLeftSpeed(200); 
  delay(420);
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);  
}

void autoRight(){
  if(mode == "leftWall"){
    motors.setRightSpeed(-200);
    motors.setLeftSpeed(200); 
    delay(420);
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0); 
  }
  if(mode == "rightWall"){
    motors.setRightSpeed(-200);
    motors.setLeftSpeed(200); 
    delay(840);
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0); 
  }
}

void autoLeft(){
  if(mode == "rightWall"){
    motors.setRightSpeed(200);
    motors.setLeftSpeed(-200);
    delay(420);
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0);
  }
  if(mode == "leftWall"){
    motors.setRightSpeed(200);
    motors.setLeftSpeed(-200);
    delay(840);
    motors.setRightSpeed(0);
    motors.setLeftSpeed(0);
  }
}

void left(){
  motors.setRightSpeed(100);
  motors.setLeftSpeed(-20);

}

void right(){
  motors.setRightSpeed(-20);
  motors.setLeftSpeed(100);
}

void leftGo(){
  motors.setRightSpeed(38);
  motors.setLeftSpeed(50);
}

void rightGo(){
  motors.setRightSpeed(50);
  motors.setLeftSpeed(38);
}

bool leftOn(){
  if(lineSensorValues[0] >=1500 && lineSensorValues[0] <= 2000){
    return true;
  }else{
    return false;
  }
}

bool rightOn(){
  if(lineSensorValues[4] >= 1500 && lineSensorValues[4] <= 2000){
    return true;
  }else{
    return false;
  }
}

// --- Setup Method
void setup() {
  Serial1.begin(9600);
  lineSensors.initFiveSensors();
  proxSensors.initThreeSensors();
  loadCustomCharacters();

  turnSensorSetup();
  delay(500);
  turnSensorReset();
  running = "semiAuto";
}

// --- Main program loop
void loop() {
  int target;
  char input;

  //switch case to select mode/mode varitation
  if (Serial1.available() > 0) {
    input = Serial1.read();
        switch(input)
        {
        case 'w':
            running = "manualTurn";
            target = 0;
            pointing = "front";
            break;
        case 'e':
            running = "manualTurn";
            target = -45;
            pointing = "frontRight";
            break;
        case 'd':
            running = "manualTurn";
            target = -90;
            pointing = "right";
            break;
        case 'c':
            running = "manualTurn";
            target = -135;
            pointing = "backRight";
            break;
        case 'x':
            running = "manualTurn";
            target = 180;
            pointing = "back";
            break;
        case 'z':
            running = "manualTurn";
            target = 135;
            pointing = "backLeft";
            break;
        case 'a':
            running = "manualTurn";
            target = 90;
            pointing = "left";
            break;
        case 'q':
            running = "manualTurn";
            target = 45;
            pointing = "frontLeft";
            break;
        case 'r':
            running = "manualDrive";
            direction = 1;
            break;
        case 't':
            running = "manualDrive";
            direction = 3;
            break;
        case 'b':
            running = "manualDrive";
            direction = 4;
            break;
        case 'v':
            running = "manualDrive";
            direction = 2;
            break;
        case 'f':
            running = "manualDrive";
            direction = 0;
            break;
        case 'y':
            running = "manualDrive";
            direction = 5;
            break;
        case 'n':
            running = "manualDrive";
            direction = 6;
            break;
        case 'p':
            running = "autoDrive";
            break;
        case 'o':
            running = "semiAuto";
            break;
        case 'l':
            autoRight();
            Serial1.print("Right");
            Serial1.print('\n');
            turnSensorReset();
            mode = "leftWall";
            break;
        case 'k':
            autoLeft();
            Serial1.print("Left");
            Serial1.print('\n');
            turnSensorReset();
            mode = "rightWall";
            break;

        
    } 
  }

  if(running == "manualTurn"){
    
    turnSensorUpdate();
    int32_t angle = getAngle();
    int distance = target-angle;

    if(abs(distance) <=3){
      motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
    }
    else{
      if(distance>180 || distance<0){
        manualRight();
      }
      if(distance<=180 && distance>0){
        manualLeft();
      }
    }
  }
  if(running == "manualDrive"){
    if(direction == 1){
      if(run){
        manualGo();
        delay(250);
        run = false;
      }else{
        stop();
      }
    }
    if(direction == 2){
      if(run){
        manualReverse();
        delay(250);
        run = false;
      }else{
        stop();
      }
    }
    if(direction == 3){
      if(run){
        manualGo();
        delay(2000);
        run = false;
      }else{
        stop();
      }
    }
    if(direction == 4){
      if(run){
        manualReverse();
        delay(2000);
        run = false;
      }else{
        stop();
      }
    }
    if(direction == 0){
      stop();
      run = true;
    }
    if(direction == 5){
      manualGo();      
    }
    if(direction == 6){
      manualReverse();   
    }
  }
  if(running == "autoDrive"){
    turnSensorUpdate();
    angle = getAngle();

    static uint16_t lastSampleTime = 0;
    if ((uint16_t)(millis() - lastSampleTime) >= 100){
        lastSampleTime = millis();
        lineSensors.read(lineSensorValues, useEmitters ? QTR_EMITTERS_ON : QTR_EMITTERS_OFF);
    }

    ledYellow(1);
    proxSensors.read();

    if((proxSensors.countsRightWithLeftLeds() >= 1 || proxSensors.countsRightWithLeftLeds() >= 1) && detected == false){
      buzzer.playNote(NOTE_A(4), 2000, 15);
      detected = true;
      Serial1.print("Detected");
      Serial1.print('\n');

      delay(100);
      buzzer.stopPlaying();         
    }

    if(leftOn() && rightOn()){
      right90();
      Serial1.print("Right");
      Serial1.print('\n');
      detected = false;
      turnSensorReset();
    }
    if(leftOn() && !rightOn()){
      leftGo();
    }
    if(!rightOn() && !leftOn()){
      left();
      if(angle == 80){
        turnSensorReset();      
        detected = false;
        Serial1.print("Left");
        Serial1.print('\n');      
      }
    }  
  }
  if(running == "semiAuto"){
    turnSensorUpdate();
    angle = getAngle();

    static uint16_t lastSampleTime = 0;
    if ((uint16_t)(millis() - lastSampleTime) >= 100){
        lastSampleTime = millis();
        lineSensors.read(lineSensorValues, useEmitters ? QTR_EMITTERS_ON : QTR_EMITTERS_OFF);
    }

    if(mode == "leftWall"){
      if(!leftOn() && !rightOn()){
        left();
        if(angle == 80){
          turnSensorReset();
          Serial1.print("Left");  
          Serial1.print('\n');        
        }        
      }
      if(leftOn() && !rightOn()){
        leftGo();
      }
      if(leftOn() && rightOn()){
        stop();
      }   
    }
    if(mode == "rightWall"){
      if(!leftOn() && !rightOn()){
        right();
        if(angle == -80){
          turnSensorReset();
          Serial1.print("Right");
          Serial1.print('\n');
        }
      }
      if(!leftOn() && rightOn()){
        rightGo();
      }
      if(leftOn() && rightOn()){
        stop();
      }
    }
  }
}
