/*
*These function support programmer to interact with cortex executer
*
*/

#define radius
#define circumference = radius *2 * PI;
/*
*This function set the speed of the 2 motorB
*@parameter  int rightSide
*					   int leftSide
*/
void setMotorSpeed(int rightSide, int leftSide){
	motor[driveBackLeft] = leftSide;
	motor[driveFrontLeft] = leftSide;
	motor[driveBackRight] = rightSide;
	motor[driveFrontRight] = rightSide;
}


/* this robot use 2 encoder to track distance traveled
*foward() function move the bot forward
*@parameter float dist // requested distance to go
*						int speed  // speed while moving to requested distance
*Note: #define diameter _NUMBER_  before using the function
*built in function used in this program. nMotorEncoder[] ; nMotorEncoderTarget[]
*/
void forward(float dist,int speed){

	float rotation = dist / circumference;  // convert to number of rotation
	float degreeToTurn = rotation * 360 ;// connvert rotation to degree.

	//initialize all encoder value at 0
	nMotorEncoder[driveFrontleft] = 0;
	nMotorEncoder[driveFrontRight] = 0;

	// set motor move to requested distance.( set to requested tick)
	nMotorEncoderTarget[driveFrontLeft] = degreeToTurn;
	nMotorEncoderTarget[driveFrontRight]= degreeToturn;

	// move
	motor[driveBackLeft] = speed;
	motor[driveFrontLeft] = speed;
	motor[driveBackRight] = speed;
	motor[driveFrontRight] = speed;

	// check when encoder counter is finish
	while(nMotorRunState[driveFrontLeft] != runStateIdle &&
				nMotorRunState[driveFrontRight] != runStateIdle){
					wait1Msec(1);
				}

	// turn off motor when done
	motor[driveBackLeft] = 0;
	motor[driveFrontLeft] = 0;
	motor[driveBackRight] = 0;
	motor[driveFrontRight] = 0;
}// end forward


/*
* Robot will rotate when execute this function
*@parameter int degree // rotate in CCW if positive input, CW if negative input
*						int speed  // rate while rotating (-100, 100)
*this function will ensure the rotation angle by computing the cnage in distance
* of roration. as well as double checking with the gyroscope
* remember to #define radius before using this function
* built in function used : nMotorEncoder[], nMotorTarget[]
*
* THIS FUNCTION IS STILL A WORK ON PROCESS
* STILL NEED TO FIGURE OUT A WAY TO DOUBLE CHECK THE TURNING ANGLE
*	WITH THE GYROSCOPE
*/
void rotate(int degree, int speed){
	// declare variable
	float distanceOfRotation, rotation, degreeToTurn;
	#define ONE_RADIAN PI/180

	// compute
	distanceOfRotation = (degree*ONE_RADIAN)*radius ;
	rotation = distanceOfRotation / circumference;  // convert to number of rotation
	degreeToTurn = rotation * 360 ;// connvert rotation to degree.

	//initialize all encoder value at 0
	nMotorEncoder[driveFrontleft] = 0;
	nMotorEncoder[driveFrontRight] = 0;

	// set motor move to requested distance.( set to requested tick)
	// turn CCW if speed input > 0
	if(speed > 0){
	// set degree to turn
	nMotorEncoderTarget[driveFrontRight]= degreeToturn;
	nMotorEncoderTarget[driveFrontLeft] = -degreeToTurn;

	// set motor
	motor[driveBackRight] = -speed;
	motor[driveFrontRight] = speed;
	motor[driveBackLeft] = -speed;
	motor[driveFrontLeft] = speed;

	}else{// turn CW if speed input < 0
	//set degree to turn
	nMotorEncoderTarget[driveFrontRight]= -degreeToturn;
	nMotorEncoderTarget[driveFrontLeft] = degreeToTurn;

	// set motor

	motor[driveBackRight] = speed;
	motor[driveFrontRight] = -speed;
	motor[driveBackLeft] = speed;
	motor[driveFrontLeft] = -speed;
	}

	// check when encoder counter is finish
	while(nMotorRunState[driveFrontLeft] != runStateIdle &&
				nMotorRunState[driveFrontRight] != runStateIdle){
					wait1Msec(1);
	}

	// turn off motor when done
	motor[driveBackLeft] = 0;
	motor[driveFrontLeft] = 0;
	motor[driveBackRight] = 0;
	motor[driveFrontRight] = 0;

}// end rotate()
