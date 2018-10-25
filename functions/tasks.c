task start(){
	while(1==1){
		if(vexRT[Btn7D] == 1)
		{
			StartTask(main_task);
			//StartTask(main);
		}
		if(vexRT[Btn8D] == 1||SensorValue(Button)==1)
		{
			StopTask(main_task);
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			motor[armMotor] = 0;
			motor[clawMotor] = 0;
			//StartTask(main);
		}
	}
}
