#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                  ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                        *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
\*-----------------------------------------------------------------------------------------------4246-*/

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
