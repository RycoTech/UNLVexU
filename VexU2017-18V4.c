#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    liftAngleRight, sensorPotentiometer)
#pragma config(Sensor, in2,    coneAngleLeft,  sensorPotentiometer)
#pragma config(Sensor, in3,    coneAngleRight, sensorPotentiometer)
#pragma config(Sensor, in4,    liftAngleLeft,  sensorPotentiometer)
#pragma config(Sensor, in5,    frontLeftLine,  sensorLineFollower)
#pragma config(Sensor, in6,    backRightLine,  sensorLineFollower)
#pragma config(Sensor, in7,    frontRightLine, sensorLineFollower)
#pragma config(Sensor, dgtl1,  extendLeft,     sensorDigitalOut)
#pragma config(Sensor, dgtl2,  extendRight,    sensorDigitalOut)
#pragma config(Sensor, dgtl3,  coneGate,       sensorDigitalOut)
#pragma config(Sensor, dgtl4,  mobleGoalLower, sensorTouch)
#pragma config(Sensor, dgtl5,  mobleGoalHigher, sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,            ,             tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           driveTrainRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           liftMobileLowerRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port4,           liftMobileHigherRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           liftConeRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           liftConeLeft,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           liftMobileHigherLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           driveTrainLeft, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           liftMobileLowerLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          coneIntake,    tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("Sensors")
#pragma DebuggerWindows("Motors")
#pragma DebuggerWindows("Locals")
#pragma DebuggerWindows("Globals")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int autonomousModeSelect = 0;


//Wait for Press--------------------------------------------------
void waitForPress()
{
  while(nLCDButtons == 0){}
  wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
  while(nLCDButtons != 0){}
  wait1Msec(5);
}
//----------------------------------------------------------------


//bool mobileLowerIfTrue = true;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
		bDisplayCompetitionStatusOnLcd = false;
	while(bIfiRobotDisabled){
		//Clear LCD
  clearLCDLine(0);
  clearLCDLine(1);
  //Declare count variable to keep track of our choice
  int count = 0;
  //Loop while center button is not pressed
  while(nLCDButtons != centerButton)
  {
    //Switch case that allows the user to choose from 4 different options
    switch(count){
    case 0:
      //Display first choice
      displayLCDCenteredString(0, "Autonomous 1");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();
      //Increment or decrement "count" based on button press
      if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count = 3;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count++;
      }
      break;
    case 1:
      //Display second choice
      displayLCDCenteredString(0, "Autonomous 2");
      displayLCDCenteredString(1, "<     Enter    >");
      waitForPress();
      //Increment or decrement "count" based on button press
      if(nLCDButtons == leftButton)
      {
        waitForRelease();
        count--;
      }
      else if(nLCDButtons == rightButton)
      {
        waitForRelease();
        count++;
      }
      break;
    default:
      count = 0;
      break;
    }
  }
  //Clear LCD
  clearLCDLine(0);
  clearLCDLine(1);

	 //Switch Case that actually runs the user choice
  switch(count){
  case 0:
    //If count = 0, run the code correspoinding with choice 1
    displayLCDCenteredString(0, "Autonomous 1");
    displayLCDCenteredString(1, "Selected!");
    wait1Msec(2000);                  // Robot waits for 2000 milliseconds

    //give user choice to th auton task

    autonomousModeSelect = 0;

    break;
  case 1:
    //If count = 1, run the code correspoinding with choice 2
    displayLCDCenteredString(0, "Autonomous 2");
    displayLCDCenteredString(1, "Selected!");
    wait1Msec(2000);                  // Robot waits for 2000 milliseconds

    //give user choice to the auton task

   	autonomousModeSelect = 1;

    wait1Msec(3000);                 // Robot runs previous code for 3000 milliseconds before moving on
    break;
  default:
    displayLCDCenteredString(0, "No valid choice");
    displayLCDCenteredString(1, "was made!");
    break;
  }

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

	resetMotorEncoder(driveTrainLeft);
	resetMotorEncoder(driveTrainRight);
}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	//motor[port8] = 127;
	//motor[port2] = 127;

	waitUntil(SensorValue[mobleGoalHigher] == 1);
	motor[port8] = 0;
	motor[port2] = 0;
	motor[liftMobileHigherLeft] = 127;
	motor[liftMobileHigherRight] = 127;
	wait(500);
	motor[liftMobileHigherLeft] = 0;
	motor[liftMobileHigherRight] = 0;
	allMotorsOff();



}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{


//logic variables
SensorValue[extendLeft] = 1;
SensorValue[extendRight] = 1;


bool coneGate = false;
bool mobileForward = true;
int highLiftPosition = 1;





	// User control code here, inside the loop

	while (true)
	{

		/*
		Drive
		Calls driveFunctions program to change motor speeds
		*/
		if(mobileForward){
				motor[port8] = vexRT[Ch3];
				motor[port2] = vexRT[Ch2];
		}
		else{

				motor[port8] = -(vexRT[Ch2]);
				motor[port2] = -(vexRT[Ch3]);
		}




		if(vexRT[Btn7R] == 1 && mobileForward == true){
			mobileForward = false;
		}
		else if(vexRT[Btn7R] == 1 && mobileForward == false){
			mobileForward = true;
		}



		//low lift
		if(vexRT[Btn8U]){
				//goes up

			motor[liftMobileLowerLeft] = 127;
			motor[liftMobileLowerRight] = 127;

			/* potential code for moving lower moble goal up (NEEDS TARGET)
			setMotorTarget(liftMobileLowerLeft, nEncoderCountTarget, 127, true);
    	setMotorTarget(liftMobileLowerRight, nEncoderCountTarget, 127, true);
			moveMotorTarget(liftMobileLowerLeft, nEncoderCountTarget, 127, true);
    	moveMotorTarget(liftMobileLowerRight, nEncoderCountTarget, 127, true);
    	*/

			}else if(vexRT[Btn8R]){
				//goes down

				motor[liftMobileLowerLeft] = -127;
				motor[liftMobileLowerRight] = -127;


			/* potential code for moving lower moble goal down (NEEDS TARGET)
			setMotorTarget(liftMobileLowerLeft, nEncoderCountTarget, -127, true);
    	setMotorTarget(liftMobileLowerRight, nEncoderCountTarget, -127, true);
			moveMotorTarget(liftMobileLowerLeft, nEncoderCountTarget, -127, true);
    	moveMotorTarget(liftMobileLowerRight, nEncoderCountTarget, -127, true);
    	*/


			}else{
			motor[liftMobileLowerLeft] = 0;
			motor[liftMobileLowerRight] = 0;
		}



		//High lift  (NEEDS SENSOR VALUES)
		if(vexRT[Btn7U]){
			//goes up
			motor[liftMobileHigherLeft] = 127;
			motor[liftMobileHigherRight] = 127;
			highLiftPosition = 3;

			//
			//}else if(vexRT[Btn7L]){
			//motor[liftMobileHigherLeft] = 127;
			//motor[liftMobileHigherRight] = 127;
			highLiftPosition = 2;
			//}
			}else if(vexRT[Btn7D]){
			//goes down
			motor[liftMobileHigherLeft] = -127;
			motor[liftMobileHigherRight] = -127;
			}else {
			motor[liftMobileHigherLeft] = 0;
			motor[liftMobileHigherRight] = 0;
			highLiftPosition = 1;
		}




		if(vexRT[Btn8D] == 1 && coneGate == false){
			//Activates Cone Lift Pneumatics
			SensorValue[coneGate] = 1;
			coneGate = true;
		}
		else if(vexRT[Btn8D] == 1 && coneGate == true){
			//Deactivates Cone Lift Pneumatics
			SensorValue[coneGate] = 0;
			coneGate = false;
		}

		//Cone lift

		if(vexRT[Btn5D]){
			motor[liftConeLeft] = 127;
			motor[liftConeRight] = 127;

		}else if(vexRT[Btn5U]){
			motor[liftConeLeft]  = -127;
			motor[liftConeRight] = -127;
		}else{
			motor[liftConeLeft]  = 0;
			motor[liftConeRight] = 0;
		}

		//cone intake

		if(vexRT[Btn6U]){
			motor[coneIntake] = 127;

		}else if(vexRT[Btn6D]){
			motor[coneIntake]  = -127;
		}else{
			motor[coneIntake]  = 0;
		}
	}
}
