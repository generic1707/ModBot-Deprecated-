#include "Module.h"
#include "Claw.h"
#include "Joint.h"
#include "Arm.h"
#include "Touch.h"
#include "USSensor.h"
#include "Mp3Player.h"
#include "Comms.h"

void setup() {
  // put your setup code here, to run once:
  Module modules[6];
  Joint lowerJoint = Joint();
  Joint upperJoint = Joint();
  Arm arm = Arm();
  Joint Rotation = Joint();
  Claw claw = Claw();
  Touch touch = Touch();
  USSensor distanceSensor = USSensor();
  Mp3Player player = Mp3Player();
  Comms com = Comms(); // serialListen() i2cListen() setCommand(pointer func, string name, int argc) 

}

void loop() {
  // put your main code here, to run repeatedly:

}

void pickUp(){
  lowerJoint.rotate(90)
  upperJoint.rotate(90)
}

void putDown(){
  //rotate
  //release
}
