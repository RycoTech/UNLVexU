
void setMotorSpeed(int rightSide, int leftSide){
	motor[driveBackLeft] = leftSide;
	motor[driveFrontLeft] = leftSide;
	motor[driveBackRight] = rightSide;
	motor[driveFrontRight] = rightSide;
}
