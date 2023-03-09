/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */

public void textarea1_change1(GTextArea source, GEvent event) { //_CODE_:textarea1:653858:
  println("textarea1 - GTextArea >> GEvent." + event + " @ " + millis());
} //_CODE_:textarea1:653858:

public void textfield1_change1(GTextField source, GEvent event) { //_CODE_:textfield1:568846:
  //println("textfield1 - GTextField >> GEvent." + event + " @ " + millis());
  String inputs = textfield1.getText();
  char instruction = inputs.charAt(inputs.length() - 1);
  connexion.write(instruction);
  
} //_CODE_:textfield1:568846:

public void button2_click1(GButton source, GEvent event) { //_CODE_:button2:308221:
  //println("button2 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("a");
  textarea1.appendText("\n Face Left");
} //_CODE_:button2:308221:

public void button3_click1(GButton source, GEvent event) { //_CODE_:button3:604378:
  //println("button3 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("d");
  textarea1.appendText("\n Face Right");
} //_CODE_:button3:604378:

public void button4_click1(GButton source, GEvent event) { //_CODE_:button4:348760:
  //println("button4 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("w");
  textarea1.appendText("\n Face Forward");
} //_CODE_:button4:348760:

public void button5_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("x");
  textarea1.appendText("\n Face Backwards");
} //_CODE_:button5:984108:

public void button6_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("c");
  textarea1.appendText("\n Face Back Right");
} //_CODE_:button5:984108:

public void button7_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("z");
  textarea1.appendText("\n Face Back Left");
} //_CODE_:button5:984108:

public void button8_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("e");
  textarea1.appendText("\n Face Forward Right");
} //_CODE_:button5:984108:

public void button9_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("q");
  textarea1.appendText("\n Face Forward Left");
} //_CODE_:button5:984108:

public void button10_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("r");
  connexion.write("f");
  textarea1.appendText("\n Drive Forward 0.035m");
} //_CODE_:button5:984108:

public void button11_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("f");
  textarea1.appendText("\n Stop");
} //_CODE_:button5:984108:

public void button12_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("v");
  connexion.write("f");
  textarea1.appendText("\n Reverse 0.035m");
} //_CODE_:button5:984108:

public void button13_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("b");
  connexion.write("f");
  textarea1.appendText("\n Long Reverse 0.28m");
} //_CODE_:button5:984108:

public void button14_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("t");
  connexion.write("f");
  textarea1.appendText("\n Long Drive 0.28m");
} //_CODE_:button5:984108:

public void button15_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("y");
  textarea1.appendText("\n Forward");
} //_CODE_:button5:984108:

public void button16_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("n");
  textarea1.appendText("\n Backwards");
} //_CODE_:button5:984108:

public void button17_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("p");
} //_CODE_:button5:984108:

public void button18_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("o");
} //_CODE_:button5:984108:

public void button19_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("k");
} //_CODE_:button5:984108:

public void button20_click1(GButton source, GEvent event) { //_CODE_:button5:984108:
  //println("button5 - GButton >> GEvent." + event + " @ " + millis());
  connexion.write("l");
} //_CODE_:button5:984108:

// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  surface.setTitle("Sketch Window");
  textfield1 = new GTextField(this, 90, 100, 240, 30, G4P.SCROLLBARS_NONE);
  textfield1.setText("");
  textfield1.setLocalColorScheme(GCScheme.PURPLE_SCHEME);
  textfield1.setOpaque(true);
  textfield1.addEventHandler(this, "textfield1_change1");
  button2 = new GButton(this, 90, 40, 80, 30);
  button2.setText("Left");
  button2.setTextBold();
  button2.addEventHandler(this, "button2_click1");
  button3 = new GButton(this, 250, 40, 80, 30);
  button3.setText("Right");
  button3.setTextBold();
  button3.addEventHandler(this, "button3_click1");
  button4 = new GButton(this, 170, 10, 80, 30);
  button4.setText("Forward");
  button4.setTextBold();
  button4.addEventHandler(this, "button4_click1");
  button5 = new GButton(this, 170, 70, 80, 30);
  button5.setText("Back");
  button5.setTextBold();
  button5.addEventHandler(this, "button5_click1");
  button6 = new GButton(this, 250, 70, 80, 30);
  button6.setText("Back, Right");
  button6.setTextBold();
  button6.addEventHandler(this, "button6_click1");
  button7 = new GButton(this, 90, 70, 80, 30);
  button7.setText("Back, Left");
  button7.setTextBold();
  button7.addEventHandler(this, "button7_click1");
  button8 = new GButton(this, 250, 10, 80, 30);
  button8.setText("Forward, Right");
  button8.setTextBold();
  button8.addEventHandler(this, "button8_click1");
  button9 = new GButton(this, 90, 10, 80, 30);
  button9.setText("Forward, Left");
  button9.setTextBold();
  button9.addEventHandler(this, "button9_click1");
  button10 = new GButton(this, 250, 170, 80, 30);
  button10.setText("Drive");
  button10.setTextBold();
  button10.addEventHandler(this, "button10_click1");
  button11 = new GButton(this, 170, 170, 80, 30);
  button11.setText("Stop");
  button11.setTextBold();
  button11.addEventHandler(this, "button11_click1");
  button12 = new GButton(this, 90, 170, 80, 30);
  button12.setText("Reverse");
  button12.setTextBold();
  button12.addEventHandler(this, "button12_click1");
  button13 = new GButton(this, 10, 170, 80, 30);
  button13.setText("Long Reverse");
  button13.setTextBold();
  button13.addEventHandler(this, "button13_click1");
  button14 = new GButton(this, 330, 170, 80, 30);
  button14.setText("Long Drive");
  button14.setTextBold();
  button14.addEventHandler(this, "button14_click1");
  textarea1 = new GTextArea(this, 420, 10, 200, 280, G4P.SCROLLBARS_BOTH | G4P.SCROLLBARS_AUTOHIDE);
  textarea1.setLocalColorScheme(GCScheme.PURPLE_SCHEME);
  textarea1.setOpaque(true);
  textarea1.addEventHandler(this, "textarea1_change1");
  button15 = new GButton(this, 170, 140, 80, 30);
  button15.setText("Forward");
  button15.setTextBold();
  button15.addEventHandler(this, "button15_click1");
  button16 = new GButton(this, 170, 200, 80, 30);
  button16.setText("Backwards");
  button16.setTextBold();
  button16.addEventHandler(this, "button16_click1");
  button17 = new GButton(this, 290, 215, 80, 30);
  button17.setText("Auto Mode");
  button17.setTextBold();
  button17.addEventHandler(this, "button17_click1");
  button18 = new GButton(this, 50, 215, 80, 30);
  button18.setText("Semi Auto");
  button18.setTextBold();
  button18.addEventHandler(this, "button18_click1");
  button19 = new GButton(this, 10, 245, 80, 30);
  button19.setText("Left");
  button19.setTextBold();
  button19.addEventHandler(this, "button19_click1");
  button20 = new GButton(this, 90, 245, 80, 30);
  button20.setText("Right");
  button20.setTextBold();
  button20.addEventHandler(this, "button20_click1");
}

// Variable declarations 
// autogenerated do not edit
GTextArea textarea1; 
GTextField textfield1; 
GButton button2; 
GButton button3; 
GButton button4; 
GButton button5; 
GButton button6; 
GButton button7;
GButton button8;
GButton button9;
GButton button10;
GButton button11;
GButton button12;
GButton button13;
GButton button14;
GButton button15;
GButton button16;
GButton button17;
GButton button18;
GButton button19;
GButton button20;
