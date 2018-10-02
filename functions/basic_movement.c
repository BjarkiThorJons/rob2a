
/*----------------------------------------------------------------------------------------------------*\
|*                                   - My basic movement functions -                                  *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*                                                                                                    *|
|*    This file contains some basic movement functions :)                                     			  *|
|*                                                                                                    *|
|*
\*----------------------------------------------------------------------------------------------------*/

void pause(){
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(500);
}

void drive(int distance, int power, int resistance, bool direction){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
	int degrees = (360/32)*(distance-resistance);
	int di = (direction) ? (1) : (-1);
	while(SensorValue[rightEncoder]*di < degrees)
  	{
    	motor[rightMotor] = power*di;
    	motor[leftMotor] = power*di;
  	}
  pause();
}

void turn(int deg,bool direction){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  //ummal 27.7 robot um dekk 10.2
  //(27.7/10,2)*deg
  double diameter=27.6;
  double diameter_wheel=10.2;
  double turn_degrees=(diameter/diameter_wheel)*deg;
	int di = (direction) ? (1) : (-1);
	while(SensorValue[rightEncoder]*di < turn_degrees)
  	{
    	motor[rightMotor] = -67*di;
			motor[leftMotor]  = 67*di;
  	}
  pause();
}
