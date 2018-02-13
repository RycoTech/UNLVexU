bool leftLineReached = false;
bool rightLineReached = false;
int rightEncoderTarget = 0;
int leftEncoderTarget = 0;
bool rightEncoderReached = false;
bool leftEncoderReched = false;


task lineLeftTest(){
while(true){
  	if(SensorValue[frontLeftLine] < 2000){
 			motor[driveTrainLeft] = 0;
 			leftLineReached = true;
 			break;
		}
	}
}


task lineRightTest(){

	while(true){
  	if(SensorValue[frontRightLine] < 2000){
 			motor[driveTrainRight] = 0;
 			rightLineReached = true;
 			break;
		}
	}
}

task rightForwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] < rightEncoderTarget);
	motor[driveTrainRight] = 0;
	rightEncoderReached = true;
}

task rightBackwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] > rightEncoderTarget);
	motor[driveTrainRight] = 0;
	rightEncoderReached = true;
}


task leftForwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] < leftEncoderTarget);
	motor[driveTrainLeft] = 0;
	leftEncoderReched = true;
}

task leftBackwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] > leftEncoderTarget);
	motor[driveTrainLeft] = 0;
	leftEncoderReched = true;
}



void turnLeft(int leftTarget, int rightTarget){
		displayLCDCenteredString(1, "turning");

		//reset encoder results flag
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoders
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		leftEncoderTarget = leftTarget;
		rightEncoderTarget = rightTarget;


		//set motors in the proper direction
		motor[driveTrainLeft] = -127;
		motor[driveTrainRight] = 127;


		//startEncoders for testing
		startTask(leftBackwardEncoderTest);
		startTask(rightForwardEncoderTest);

		//when the encoders return the results, then stop the tasks, and end the function
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightBackwardEncoderTest);
		stopTask(leftForwardEncoderTest);
		return;
}

void turnRight(int leftTarget, int rightTarget){

		//reset encoder results
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoder values
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		leftEncoderTarget = leftTarget;
		rightEncoderTarget = rightTarget;


		//set motors in proper direction
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = -127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(leftForwardEncoderTest);
		startTask(rightBackwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightForwardEncoderTest);
		stopTask(leftBackwardEncoderTest);
		return;
}

void strait(int leftTarget, int rightTarget){
		//reset encoder results
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoder values
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		rightEncoderTarget = rightTarget;
		leftEncoderTarget = leftTarget;

		//set motors in proper direction
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = 127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(rightForwardEncoderTest);
		startTask(leftForwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightForwardEncoderTest);
		stopTask(leftForwardEncoderTest);
		return;
}
