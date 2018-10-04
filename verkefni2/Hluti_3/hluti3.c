#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 2 hluti 3 -                                         	*|
|*                                  ROBOTC on VEX 2.0 CORTEX                                      		*|
|*                                                                                                    *|
|*  Thetta forrit laetur robotinn keyra akvedna leid.                                                 *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

#include "../../functions/basic_movement.c"

int power=127;
int resistance=12;
int deg=90;


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);
	int distance = 50;
	drive(distance,power,resistance,true);
	turn(deg,false);
	for ( int x=0; x<2; x++ ) {
   	drive(distance,power,resistance,true);
		turn(deg,true);
	}
	drive(distance,power,resistance,true);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
