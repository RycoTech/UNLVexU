/* predefine by robotC IDE*/
#pragma config(Sensor, in1,    mobileLowerAngle, sensorPotentiometer)
#pragma config(Sensor, in2,    mobileHigherAngle, sensorPotentiometer)
#pragma config(Sensor, in3,    coneAngle,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  mobileLiftPneumatics, sensorDigitalOut)
#pragma config(Sensor, dgtl2,  coneLiftPneumatics, sensorDigitalOut)
#pragma config(Sensor, I2C_1,  leftDrive,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightDrive,     sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           driveBackLeft, tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port2,           driveFrontLeft, tmotorVex393HighSpeed_MC29, openLoop, driveLeft, encoderPort, I2C_4)
#pragma config(Motor,  port3,           liftMobileLowerLeft, tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           liftMobileHigherLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           liftConeLeft,  tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           liftConeRight, tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port7,           liftMobileHigherRight, tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port8,           liftMobileLowerRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           driveFrontRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port10,          driveBackRight, tmotorVex393HighSpeed_HBridge, openLoop, driveRight, encoderPort, I2C_2)

// debug
#pragma DebuggerWindows("Sensors")
#pragma DebuggerWindows("Motors")
#pragma DebuggerWindows("Locals")
#pragma DebuggerWindows("Globals")

#pragma platform(VEX2)
#pragma competitionControl(Competition)


/*Include library */
#include "Vex_Competition_Includes.c"
#include "driveFunctions.c"

/*Global variable */
bool mobileLowerIfTrue = true;


// main
void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


task autonomous()
{
	AutonomousCodePlaceholderForTesting();
}



task usercontrol()
{
	// User control code here, inside the loop
	bool mobileForward = true;

	while (true)
	{
		/*
		Drive
		Calls driveFunctions program to change motor speeds
		*/
		if(mobileForward){
			setMotorSpeed(vexRT[Ch2], vexRT[Ch3]);
		}
		else{
			setMotorSpeed(vexRT[Ch3], vexRT[Ch2]);
		}
		if(vexRT[Btn8D] == 1){
			mobileForward = false;
		}
		else if(vexRT[Btn8R] == 1){
			mobileForward = true;
		}

		/*
		Lift Program
		This controls the 3 lift systems
		They will be split into 2 sections, the Mobile Goal Lifts and the Cone Lift
		*/
		//Set Mobile Higher or Lower
		if(vexRT[Btn8U] == 1){
			mobileLowerIfTrue = true;
		}
		else if(vexRT[Btn8L] == 1){
			mobileLowerIfTrue = false;
		}
		//Mobile Goal Lift
		/*if(vexRT[Btn5U] == 1){
		//if(mobileLowerIfTrue && SensorValue[mobileLowerAngle] < 3600){

		//}
		else if(SensorValue[mobileHigherAngle] < 3600){
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;
		}
		motor[liftMobileLowerLeft] = 127;
		motor[liftMobileLowerRight] = 127;
		}
		else if(vexRT[Btn5D] == 1){
		if(mobileLowerIfTrue && SensorValue[mobileLowerAngle] > 360){
		motor[liftMobileLowerLeft] = -67;
		motor[liftMobileLowerRight] = -67;
		}
		else if(SensorValue[mobileHigherAngle] > 360){
		motor[liftMobileHigherLeft] = -67;
		motor[liftMobileHigherRight] = -67;
		}
		}
		else{
		motor[liftMobileLowerLeft] = 0;
		motor[liftMobileLowerRight] = 0;
		motor[liftMobileHigherLeft] = 0;
		motor[liftMobileHigherRight] = 0;
		}*/

		//low lift
		if(vexRT[Btn5U]){
			while(SensorValue[mobileLowerAngle] < 3100){
				//goes up
				motor[liftMobileLowerLeft] = 127;
				motor[liftMobileLowerRight] = 127;
			}
			}else if(vexRT[Btn5D]){
			while(SensorValue[mobileLowerAngle] > 2500){
				//goes down
				motor[liftMobileLowerLeft] = -127;
				motor[liftMobileLowerRight] = -127;
			}
			}else{
			motor[liftMobileLowerLeft] = 0;
			motor[liftMobileLowerRight] = 0;
		}// enc low lift



		//High lift
		if(vexRT[Btn6U]){
			//while(SensorValue[mobileHigherAngle] < 4100){
			//goes up
			motor[liftMobileHigherLeft] = 127;
			motor[liftMobileHigherRight] = 127;
			//}
			}else if(vexRT[Btn6D]){
			//while(SensorValue[mobileHigherAngle] > 700){
			//goes down
			motor[liftMobileHigherLeft] = -127;
			motor[liftMobileHigherRight] = -127;
			//	}
			}else{
			motor[liftMobileHigherLeft] = 0;
			motor[liftMobileHigherRight] = 0;
		}



		/*Cone Lift
		if(vexRT[Btn6U] == 1 && SensorValue[mobileHigherAngle] < 3600){
		motor[liftConeLeft] = 127;
		motor[liftConeRight] = 127;
		}
		else if(vexRT[Btn6D] == 1 && SensorValue[mobileHigherAngle] > 360){
		motor[liftConeLeft] = -127;
		motor[liftConeRight] = -127;
		}
		else{
		motor[liftConeLeft] = 0;
		motor[liftConeRight] = 0;
		}*/



		//Pneumatic Lift Systems
		if(vexRT[Btn7L] == 1){
			//Activates Mobile Lift Pneumatics
			SensorValue[mobileLiftPneumatics] = 1;
		}
		else if(vexRT[Btn7D] == 1){
			//Deactivates Mobile Lift Pneumatics
			SensorValue[mobileLiftPneumatics] = 0;
		}

		if(vexRT[Btn7U] == 1){
			//Activates Cone Lift Pneumatics
			SensorValue[coneLiftPneumatics] = 1;
		}
		else if(vexRT[Btn7R] == 1){
			//Deactivates Cone Lift Pneumatics
			SensorValue[coneLiftPneumatics] = 0;
		}
	} // end pneumatic lift systems
}// end main
