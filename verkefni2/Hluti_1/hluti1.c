#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 2 hluti 1 -                                         	*|
|*                                  ROBOTC on VEX 2.0 CORTEX                                      		*|
|*                                                                                                    *|
|*  Thetta forrit laetur robotinn keyra 0,5m afram med tima og svo bakkar hann 0,5m. Svo er thetta		*|
|*  endurtekid og vegalengdin haekud um 0,5m thar til robotin keyrir 2,5m.                            *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

int power=127;
int drive_time=3000;


void drive_forward(int drive_time, int counter){
	motor[rightMotor] = power;
	motor[leftMotor]  = power;
	wait1Msec(drive_time*counter);
}

void drive_reverse(int drive_time, int counter){
	motor[rightMotor] = -power;
	motor[leftMotor]  = -power;
	wait1Msec(drive_time*counter);
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main(){
	wait1Msec(2000);
	//drive_forward(970,1);
	//drive_reverse(970,1);
	for(int i=1;1<5;i++){
		drive_forward(970,i);
		drive_reverse(970,i);
		}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
