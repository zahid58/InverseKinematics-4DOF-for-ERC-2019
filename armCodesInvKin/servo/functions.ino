
void gotocords(int x,int y, int z,int phi){
    String out = x + "," + y + "," + z + "," + phi "\n";
    printTitles(); // just prints angles titles; function in helper //for debugging purposes.
    
    //fabrik2D.solve2(160, 30, 0, -M_PI/2.5, 0, lengths); //x,y,z,toolAngle
    fabrik2D.solve2(x,y,z,phi,lengths);

    int baseAngle = round(fabrik2D.getBaseAngle()* 57296 / 1000.0);
    int shoulderAngle = round(fabrik2D.getAngle(0)* 57296 / 1000.0);
    int elbowAngle = round(fabrik2D.getAngle(1)* 57296 / 1000.0);
    elbowAngle = 90 + elbowAngle;
    int wristAngle = round(fabrik2D.getAngle(2)* 57296 / 1000.0);
    wristAngle = 90 + wristAngle;

    //Putting Limits. // set according to your motor setup.
    baseAngle = min(150, max(5, baseAngle ));
    shoulderAngle = min(150, max(5, shoulderAngle ));
    elbowAngle = min(150, max(5, elbowAngle ));
    wristAngle = min(150, max(5, wristAngle ));

    //send the angles to the motors
    gotoangles(baseAngle, shoulderAngle, elbowAngle, wristAngle);

    //print for debugging purposes.
    Serial.print(fabrik2D.getBaseAngle()* 57296 / 1000); 
    Serial.print("\t");
    Serial.print(fabrik2D.getAngle(0)* 57296 / 1000);
    Serial.print("\t");
    Serial.print(fabrik2D.getAngle(1)* 57296 / 1000);
    Serial.print("\t");
    Serial.println(fabrik2D.getAngle(2)* 57296 / 1000);
}




void gotoangles(int theta1,int theta2,int theta3,int theta4){
  
  if (!isnan(theta1)) { //If Angle is a valid number.

    int CurrentAngle = readBaseAngle();

    if (theta1 > CurrentAngle) {
      Serial.print(CurrentAngle);
      Serial.print(" < ");
      Serial.println(theta1);
      for (i = CurrentAngle; i < theta1; i = i + 1) //if Angle_B > CurrentAngle.
      {

       moveBase(i);
        delay(20);
      }//end for CurrentAngle.

    }//end if Angle_B > CurrentAngle.

    else
    {
      Serial.print(CurrentAngle);
      Serial.print(" > ");
      Serial.println(theta1);
      for (i = CurrentAngle; i > theta1 ; i = i - 1) //if Angle_B < CurrentAngle.
      {

        moveBase(i);
        delay(20);
      }//end for CurrentAngle.
    }//end else.

  } //end if !isnan.
  //-------------------------------------
  if (!isnan(theta2)) { //If Angle is a valid number.

    CurrentAngle = readShoulderAngle();

    if (theta2 > CurrentAngle) {
      Serial.print(CurrentAngle);
      Serial.print(" < ");
      Serial.println(theta2);
      for (i = CurrentAngle; i < theta2; i = i + 1) //if Angle > CurrentAngle.
      {

       moveShoulder(i);
        delay(20);
      }//end for CurrentAngle.

    }//end if Angle > CurrentAngle.

    else
    {
      Serial.print(CurrentAngle);
      Serial.print(" > ");
      Serial.println(theta2);
      for (i = CurrentAngle; i > theta2; i = i - 1) //if Angle < CurrentAngle.
      {

        moveShoulder();
        delay(20);
      }//end for CurrentAngle.
    }//end else.

  } //end if !isnan.
  //------------------------------------------
  if (!isnan(theta3)) { //If Angle is a valid number.

    CurrentAngle = readElbowAngle();
    if (theta3 > CurrentAngle) {
      Serial.print(CurrentAngle);
      Serial.print(" < ");
      Serial.println(theta3);
      for (i = CurrentAngle; i < theta3 ; i = i + 1) //if Angle_B > CurrentAngle.
      {

       moveElbow(i);
        delay(20);
      }//end for CurrentAngle.

    }//end if Angle > CurrentAngle.

    else
    {
      Serial.print(CurrentAngle);
      Serial.print(" > ");
      Serial.println(theta3);
      for (i = CurrentAngle; i > theta3; i = i - 1) //if Angle < CurrentAngle.
      {

        moveElbow(i);
        delay(20);
      }//end for CurrentAngle.
    }//end else.

  } //end if !isnan.
  //----------------------------------
  if (!isnan(theta4)) { //If Angle is a valid number.

    CurrentAngle = readWristAngle();
    if (theta4 > CurrentAngle) {
      Serial.print(CurrentAngle);
      Serial.print(" < ");
      Serial.println(theta4);
      for (i = CurrentAngle; i < theta4; i = i + 1) //if Angle > CurrentAngle.
      {

        moveWrist(i);
        delay(20);
      }//end for CurrentAngle.

    }//end if Angle > CurrentAngle.

    else
    {
      Serial.print(CurrentAngle);
      Serial.print(" > ");
      Serial.println(theta4);
      for (i = CurrentAngle; i > theta4; i = i - 1) //if Angle < CurrentAngle.
      {

        wrist.write(i);
        delay(20);
      }//end for CurrentAngle.
    }//end else.

  } //end if !isnan.
}





void parseData() {
/*
  // split the data into its parts
    
  char * strtokIndx; // this is used by strtok() as an index
  
  strtokIndx = strtok(receivedChars,",");      // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
  
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  integerFromPC = atoi(strtokIndx);     // convert this part to an integer
  
  //strtokIndx = strtok(NULL, ",");
  strtokIndx = strtok(NULL, NULL); 
  floatFromPC = atof(strtokIndx);     // convert this part to a float
*/
}
