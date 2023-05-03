#include <Arm.h>
#include <BatteryControl.h>
#include <Claw.h>
#include <Comms.h>
#include <Joint.h>
#include <Module.h>
#include <Mp3Player.h>
#include <Touch.h>
#include <USSensor.h>
#include <Wheel.h>

Joint lowerJoint = Joint(2);
Joint upperJoint = Joint(3);
//Arm arm = Arm(&lowerJoint, &upperJoint, 5,5);
Joint rotation = Joint(4);
Claw claw = Claw(5);
Touch touch = Touch(6,false);
USSensor distanceSensor = USSensor(7,8);
Mp3Player player = Mp3Player(9,10,8);
Comms com = Comms(); // serialListen() i2cListen() setCommand(pointer func, int argc) 
//struct command cmd1;
//struct command cmd2;
bool oneTime = true;

void setup() {
  com.beginSerial();
  // cmd1.name = "w";
  // cmd1.cmd1 = pickUp;
  // cmd1.type = 1;
  // cmd1.name = "s";
  // cmd1.cmd1 = putDown;
  // cmd1.type = 1;
  // com.addCommand(cmd1);
  // com.addCommand(cmd2);
  lowerJoint.setup();
  upperJoint.setup();
  //rotation.setup();
  
  
}

void loop() {
  //com.serialListen();
  if (distanceSensor.sense()<5){
    pickUp();
    delay(1000);
    putDown();
    delay(1000);
  }
  
  if (oneTime){
    player.setVolume(8);
    player.play(1);
    oneTime = false;
  }
}

bool pickUp(){
  lowerJoint.rotate(60);
  upperJoint.rotate(60);
  com.serialWrite("pick up");
  return true;
}

bool putDown(){
  lowerJoint.rotate(90);
  upperJoint.rotate(90);
  com.serialWrite("put down");
  return true;
}

bool smthng(int x){
  return true;
}
