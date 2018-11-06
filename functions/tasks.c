
task start_by_light(){
	int tel = 1;
	while(1==1){
		if(SensorValue(lightSensor) < 400 && tel==1)
		{
			StartTask(main_task);
			tel = 0;
			//StartTask(main);
		}
		else if(SensorValue(lightSensor) > 400)
		{
			StopTask(main_task);
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			motor[armMotor] = 0;
			motor[clawMotor] = 0;
			tel = 1;
			//StartTask(main);
		}
	}
}
task start(){
	while(1==1){
		if(vexRT[Btn7D] == 1)
		{
			StartTask(main_task);
			//StartTask(main);
		}
		else if(vexRT[Btn8D] == 1||SensorValue(Button)==1)
		{
			StopTask(main_task);
			StopTask(start_by_light);
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			motor[armMotor] = 0;
			motor[clawMotor] = 0;
		}
			//StartTask(main);
	}
}
