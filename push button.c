#pragma config(Sensor, dgtl1,  touchSensor,    sensorTouch)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                        - Wait for Push 1 -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward at half speed until the bumper sensor is         *|
|*  pressed.  There is a two second pause at the beginning of the program.                            *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital Port 6      touchSensor         VEX Bumper Switch     Front mounted, facing forward.    *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	bool isHit = false;
	wait1Msec(2000);						            // Robot waits for 2000 milliseconds before executing program

	while(true){

		if(SensorValue(touchSensor) == 1 && isHit == false){		// Loop while robot's bumper/touch sensor isn't pressed in
			isHit	= true;
			PlaySoundFile("scream.wav");
		}
		else if(isHit == false && SensorValue(touchSensor) == 0){
			motor[leftMotor] = 70;
			motor[rightMotor] = 70;
		}
		else{}

		if(isHit == true){
			motor[leftMotor] = -40;
			motor[rightMotor] = -40;
			sleep(2000);
			motor[leftMotor] = -40;
			motor[rightMotor] = 40;
			sleep(3000);
			isHit = false;
		}

		PlaySoundFile("start.wav");
		PlaySoundFile("melody.wav");
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
