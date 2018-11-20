#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_cm)
#pragma config(Sensor, in4,    lineFollowerLEFT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerRIGHT,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerCENTER,    sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop,reversed)
#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl4,    Button,              sensorTouch)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Sensor, in8,    lightSensor,         sensorReflection)
#pragma config(Sensor, in1, potentiometer, sensorPotentiometer)

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 2 hluti 3 -                                         	*|
|*                                  ROBOTC on VEX 2.0 CORTEX                                      		*|
|*                                                                                                    *|
|*  Thetta forrit laetur robotinn keyra akvedna leid.                                                 *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

#include "../functions/basic_movement.c"
const double resistance=0;

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
		arm(1700,1);
	//wait1Msec(2000);
	//int distance = 200;
	//follow_line_dist(distance,resistance,true);
	//search_line(true);
	//follow_line_dist(50,resistance,true);
	//1700 3700
	//turn(20,true);
	//search_line(true);
	//follow_line_dist(250,resistance,true);

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
