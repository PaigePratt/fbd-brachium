#pragma config(Sensor, dgtl1,  encoder1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  elbowEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           shoulder,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          elbow,         tmotorVex393_HBridge, openLoop)

//CONSTANTS
#define TICKS_PER_REV 512;
#define TICKER_PER_DEGREE = TICKS_PER_REV / 360;
#define ELBOW_LENGTH = 0; //tbd
#define SHOULDER_LENGTH = 0; //tdb

task main()
{


}
