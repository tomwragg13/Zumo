import processing.serial.*;
import g4p_controls.*;

Serial connexion;;

int bgcol = 15;

public void setup() {
  String portName = Serial.list()[0];
  connexion = new Serial(this, portName, 9600);
  size(630, 300);
  createGUI();
}

public void draw() {
  background(200, 200, 200);
  
  while (connexion.available() > 0){
    String msg = connexion.readStringUntil('\n');
    if(msg!= null){
      textarea1.appendText("\n" + msg);
    }
  }

}
