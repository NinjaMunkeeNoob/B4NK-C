#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task auto(){
	int x = 0;
	while (x < 70){
		motor[leftMotor] = x;
		motor[rightMotor] = x;
		x += 1;
		sleep(10);
	}
		motor[leftMotor] = 72;
		motor[rightMotor] = 70;  // Drives to first cone
		sleep(3600);
		motor[leftMotor] = 12;    //drives around first cone
		motor[rightMotor] = 127;
		sleep(5950);
		motor[leftMotor] = 70;
		motor[rightMotor] = 70;  // to second cone
		sleep(2400);
		motor[leftMotor] = 12;
		motor[rightMotor] = 125;  // around second cone
		sleep(5200);
		motor[leftMotor] = 70;  // to third
		motor[rightMotor] = 70;
		sleep(1600);
		motor[leftMotor] = 10;  // around third
		motor[rightMotor] = 100;
		sleep(7500);
		motor[leftMotor] = 127; // to end
		motor[rightMotor] = 127;
		sleep(1000000000);
}

task user(){

	while(1 == 1)
	{
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

// Raise, lower or do not move arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = 127;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = -127;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = 127;  		//...close the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -127; 		//...open the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}
	}
}

task main () {


	while(true){
		startTask(user);
		if(vexRT[Btn8D] == 1){
			startTask(auto);
		}
		if(vexRT[Btn8R] == 1){
			stopTask(auto);
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
