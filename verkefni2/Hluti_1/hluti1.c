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
int drive_time=950;


void drive_forward(int drive_time, int counter){
	motor[rightMotor] = power;
	motor[leftMotor]  = power;
	wait1Msec(drive_time*counter);;
}

void drive_reverse(int drive_time, int counter){
	motor[rightMotor] = -power;
	motor[leftMotor]  = -power;
	wait1Msec(drive_time*counter);

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
	for(int i=1;i<5;i++){
		drive_forward(drive_time,i);
		pause();
		drive_reverse(drive_time,i);
		pause();
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
