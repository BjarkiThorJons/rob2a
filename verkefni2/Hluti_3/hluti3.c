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

void turn_right(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  //ummal 27.7 robot um dekk 10.2
	int turn_degrees=244;
	while(SensorValue[rightEncoder] < turn_degrees)
  	{
    	motor[rightMotor] = -67;		  // Motor on port2 is run at full (-127) power reverse
			motor[leftMotor]  = 67;			// Motor on port3 is run at full (127) power forward
  	}
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
	int distance = 30;
	//drive_forward(distance,power,resistance);
	pause();
	turn_right();
	pause();
	drive_forward(distance,power,resistance);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
