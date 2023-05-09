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

Joint lowerJoint = Joint(3);
Joint upperJoint = Joint(2);
Joint rotation = Joint(5);
Arm arm = Arm(&lowerJoint, &upperJoint, &rotation, 5,5);

Claw claw = Claw(4);
Touch touch = Touch(6,false);
USSensor distanceSensor = USSensor(7,8);
Mp3Player player = Mp3Player(9,10,8);
Comms com = Comms(); // serialListen() i2cListen() setCommand(pointer func, int argc) 
struct command cmd1;
struct command cmd2;
struct command cmd3;


void setup() {
  cmd1.name = "w";
  cmd1.desc = "picks up a thing";
  cmd1.cmd1 = pickUp;
  cmd1.type = 1;
  cmd2.name = "s";
  cmd2.desc = "puts down a thing";
  cmd2.cmd1 = putDown;
  cmd2.type = 1;
  cmd3.name = "wave";
  cmd3.desc = "arm waves at a person, after command you write a number how many times does it wave";
  cmd3.cmd3 = wave;
  cmd3.type = 3;
  
  lowerJoint.setup();
  upperJoint.setup();
  rotation.setup();
  claw.setup();
  com.beginSerial();
  com.addCommand(cmd1);
  com.addCommand(cmd2);
  com.addCommand(cmd3);
}

void loop() {
  com.serialListen();
  if (distanceSensor.sense()<5){
    pickUp();
    delay(1000);
    putDown();
    delay(1000);
  }
  
  if (touch.isTouched()){
    if (player.isPlaying()){
      delay(500);
      player.stop();
    }else{
      delay(500);
      player.setVolume(8);
      player.play(1);
    }
  }
}

bool pickUp(){
  com.serialWrite("pick up");
  rotation.rotate(45);
  delay(300);
  lowerJoint.rotate(30);
  delay(300);
  upperJoint.rotate(20);
  delay(300);
  claw.open();
  delay(2000);
  claw.close();
  delay(300);
  lowerJoint.rotate(90);
  delay(300);
  upperJoint.rotate(90);
  delay(300);
  rotation.rotate(90);
  return true;
}

bool putDown(){
  com.serialWrite("put down");
  rotation.rotate(125);
  delay(300);
  lowerJoint.rotate(30);
  delay(300);
  upperJoint.rotate(30);
  delay(300);
  claw.open();
  delay(300);
  lowerJoint.rotate(90);
  delay(300);
  claw.close();
  delay(300);
  upperJoint.rotate(90);
  delay(300);
  rotation.rotate(90);
  return true;
}

bool wave(int x){
  rotation.rotate(150);
  for (int i = 0; i < x; i++){
    lowerJoint.rotate(70);
    delay(50);
    upperJoint.rotate(70);
    delay(300);
    lowerJoint.rotate(90);
    delay(50);
    lowerJoint.rotate(110);
    delay(30);
    upperJoint.rotate(90);
    delay(50);
    upperJoint.rotate(110);
    delay(300);
    lowerJoint.rotate(90);
    delay(50);
    upperJoint.rotate(90);
    delay(50);
  }
  rotation.rotate(45);
  delay(500);
  claw.open();
  delay(200);
  claw.close();
  delay(200);
  claw.open();
  delay(200);
  claw.close();
  delay(500);
  rotation.rotate(90);
  return true;
}
