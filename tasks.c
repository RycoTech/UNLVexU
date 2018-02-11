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

task rightEncoderTest(){

	waitUntil(SensorValue[rightEncoder] == rightEncoderTarget);
	motor[driveTrainRight] = 0;
	rightEncoderReached = true;
}


task leftEncoderTest(){

	waitUntil(SensorValue[leftEncoder] == leftEncoderTarget);
	motor[driveTrainLeft] = 0;
	leftEncoderReched = true;
}

void setEncoders(int leftTarget, int rightTarget){
		bool rightEncoderReached = false;
		bool leftEncoderReched = false;
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;
		rightEncoderTarget = rightTarget;
		leftEncoderTarget = leftTarget;
		startTask(rightEncoderTest);
		startTask(leftEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightEncoderTest);
		stopTask(leftEncoderTest);
		return;
}
