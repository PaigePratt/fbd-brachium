#pragma config(Sensor, dgtl1,  encoder1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  elbowEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           shoulder,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          elbow,         tmotorVex393_HBridge, openLoop)

task main()
{
	wait1Msec(1000);

	SensorValue[encoder1] = 0;
	while(true)
	{
		motor[shoulder] = vexRT[Ch3];
		motor[elbow] = vexRT[Ch2];
		writeDebugStreamLine("Encoder value is: %d", SensorValue[encoder1]);
		wait10Msec(1);
	}
}
