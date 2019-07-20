# InverseKinematicsERC19
using FABRIK2D arduino library for applying 4-DOF inverse kinematics in Robotic Arm made using servo motors.
# References - Fabrik2D
https://github.com/henriksod/Fabrik2DArduino

Read the ReadMe of Fabrik2D.
# some instructions
The main code is in armCodesInvKin/servo/servo.ino Run it with Arduino.
But don't forget to install Fabrik2D library beforehand. (if you don't know how search google - how to add a library in arduino)
in serial monitor, you are supposed to provide "x,y,z,tool_angle" hit enter. It will show you angles and move the arm accordingly.

![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide2.JPG)
![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide3.JPG)
![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide4.JPG)
![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide5.JPG)
![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide6.JPG)
when we apply angles (90,90,90,90) they point straight up. When we apply angles we got for (100,100,0,-72)[x,y,z,tool_angle]  which are (0,91,27,0) we reach somewhere close to (100,100,0)(x,y,z). The offset is because of setting the motors incorrectly and excessive load on the servo motors.
![](https://github.com/iut-160041010/InverseKinematicsERC19/blob/master/Applying%20Inverse%20Kinematics/Slide7.JPG)




Ignore "GUI CONTROL FOR ARM". work in progress.
