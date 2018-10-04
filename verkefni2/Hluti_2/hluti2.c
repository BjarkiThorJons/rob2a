#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 2 hluti 2 -                                         	*|
|*                                  ROBOTC on VEX 2.0 CORTEX                                      		*|
|*                                                                                                    *|
|*  Thetta forrit laetur robotinn keyra 0,5m afram med encoderunum og svo bakkar hann 0,5m. Svo er 		*|
|*  thetta endurtekid og vegalengdin haekud um 0,5m thar til robotin keyrir 2,5m.                     *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

int power=127;
int distance_change=50;
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

void drive_reverse(int distance, int power, int resistance){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
	int degrees = (360/32)*(distance-resistance);
	while(SensorValue[leftEncoder] < degrees)
  	{
    	motor[rightMotor] = -power;
    	motor[leftMotor] = -power;
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
	int distance = 0
	for(int i=1;i<5;i++){
		distance+=distance_change;
		writeDebugStreamLine("%d",distance);
		drive_forward(distance,power,12);
		pause();
		drive_reverse(distance,power,12);
		pause();

	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
