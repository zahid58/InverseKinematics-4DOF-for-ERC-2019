#include <Servo.h>
#include<math.h>
#include <FABRIK2D.h>

int lengths[] = {105, 95, 50}; // 3DOF arm where shoulder to elbow is 105mm, elbow to wrist is 95mm and wrist to end effector(endpoint) is 50mm.
Fabrik2D fabrik2D(4, lengths); // This arm has 4 joints; one in the origin, the elbow, the wrist and the end effector(which is the gripper's end point)


Servo base, shoulder, elbow, wrist;
String inputString;
int i;
int CurrentAngle;

//length of the links are defined below


bool stringComplete = false;

#define PI 3.1416

void setup() {


  fabrik2D.setTolerance(1); //you can set a tolerance in fabrik2D
  
  Serial.begin(9600);
  
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  base.attach(8);
  shoulder.attach(9);
  elbow.attach(10);
  wrist.attach(11);
  
  //Initialize servos to home position
  resetServos(); // arm points straight upwards when every servo angle is set to 90 degrees.

  //for testing purposes
  //gotoangles(theta1,theta2,theta3,theta4);
  //gotoangles(34,45,56,67);
  //gotocordinates(x,y,z,phi);
  //gotocordinates(-14,3,10,140);
}


void loop() {
while(Serial.available())
{
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '\n')
    {
      handle_incoming(inputString);
      Serial.println(inputString);
      inputString = "";
    }
  }
}


void handle_incoming(String inputString)
{
  char receivedChars[inputString.length()];
  for(int i=0;i<inputString.length();i++){
    receivedChars[i] = inputString[i];
  }
  
  char * strtokIndx; // this is used by strtok() as an index
  
  strtokIndx = strtok(receivedChars,",");      // get the first part - the string
  int x = atoi(strtokIndx); // copy it to messageFromPC
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  int y = atoi(strtokIndx);
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  int z = atoi(strtokIndx); 
  strtokIndx = strtok(NULL, '\n'); // this continues where the previous call left off
  int phi = atoi(strtokIndx);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  Serial.println(phi);
  //gotoangles(theta0,theta1,theta2,theta4);

  //phi is the "tool angle"
  gotocord(x,y,z,phi);
}



double deg2rad(int deg)
{
 // deg = rad * 57296 / 1000;
  double rad = deg * 1000 / 57296;
  return rad;
}
double rad2deg(int rad){
  double deg = rad * 57296 / 1000;
  return deg;
  //rad = deg * 1000 / 57296
}


void resetServos(){
  
  base.write(90);
  delay(200);
  
  shoulder.write(90);
  delay(200);

  elbow.write(90);
  delay(200);

  wrist.write(90);
  delay(200);
  
}
