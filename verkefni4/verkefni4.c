#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#pragma config(Sensor, dgtl11,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl4,    Button,              sensorTouch)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Sensor, in8,    lightSensor,         sensorReflection)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                 					  - Verkefni 4 -                                          *|
|*                                                                                                    *|
|*										Robotinn keyrir endalaust  medan ekki er ytt a stopp takkana.										*|
|*					Beygir til haegri i hvert skipti sem thad er einhvad fyrir innan 35cm fjardlaegd.					*|
\*----------------------------------------------------------------------------------------------------*/
#include "../functions/basic_movement.c"

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main_task(){
	while(1==1){
		if (SensorValue(sonarSensor) > 35)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			motor[rightMotor] = 127;			// Motor on port2 is run at half (63) power forward
			motor[leftMotor]  = 127;			// Motor on port3 is run at half (63) power forward
		}
		else{
			pause();
			turn(90,true);
		}
	}

}
#include "../functions/tasks.c"
task main()
{
	StartTask(start_by_light);
	StartTask(start);
	while(1==1){
		}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
