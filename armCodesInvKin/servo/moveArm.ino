//Here You write the code to move your arm Angles. You might have different kinds of motors. Moving them might need different type of code.

void moveBase(int angle){
  base.write(angle);  
}


void moveShoulder(int angle){
  shoulder.write(angle);
}


void moveElbow(int angle){
  elbow.write(angle);
}


void moveWrist(int angle){
  wrist.write(angle);
}


//Here you write code to read the current angle. You might have different type of feedback system for each motor. so each function may be different.

int readBaseAngle(){
  base.read();
}


int readShoulderAngle(){
  shoulder.read();
}


int readElbowAngle(){
  elbow.read();
}


int readWristAngle(){
  wrist.read();
}
