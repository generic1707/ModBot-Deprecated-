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

Joint lowerJoint = Joint(1);
Joint upperJoint = Joint(2);
Arm arm = Arm(&lowerJoint, &upperJoint, 5,5);
Joint Rotation = Joint(3);
Claw claw = Claw(4);
Touch touch = Touch(5,false);
USSensor distanceSensor = USSensor(6,7);
Mp3Player player = Mp3Player(8,9,10);
Comms com = Comms(); // serialListen() i2cListen() setCommand(pointer func, string name, int argc) 

void setup() {
  // put your setup code here, to run once:
  struct command cmd1;
  struct command cmd2;
  Serial.begin(9600);
  cmd1.name = "w";
  cmd1.cmd1 = pickUp;
  cmd1.type = 1;
  cmd1.name = "s";
  cmd1.cmd1 = putDown;
  cmd1.type = 1;
  com.addCommand(cmd1);
  com.addCommand(cmd2);

}

void loop() {
  com.serialListen();
}

bool pickUp(){
  lowerJoint.rotate(60);
  upperJoint.rotate(60);
  return true;
}

bool putDown(){
  lowerJoint.rotate(90);
  upperJoint.rotate(90);
  return true;
}

bool smthng(int x){
  return true;
}
