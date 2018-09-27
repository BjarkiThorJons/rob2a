#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

int power=127;
int resistance=12;

void drive_forward(int distance, int power, int resistance){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
	int degrees = (360/32)*(distance-resistance);
	while(SensorValue[rightEncoder] < degrees)
  	{
    	motor[rightMotor] = power;
    	motor[leftMotor] = power;
  	}
}

void turn(){
	//code comming soon
}

void pause(){
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500);
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);
	int distance = 50
	writeDebugStreamLine("%d",distance);
	drive_forward(distance,power,12);
	pause();
	pause();

	// Turn Right at full power for 0.75 seconds
	motor[rightMotor] = -127;		  // Motor on port2 is run at full (-127) power reverse
	motor[leftMotor]  = 127;			// Motor on port3 is run at full (127) power forward

	// Turn Left at full power for 0.75 seconds
	motor[rightMotor] = 127;			// Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (-127) power reverse
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
