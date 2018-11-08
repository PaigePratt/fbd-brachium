/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

typedef void (*command)(int*); //argument count, arguments

void set_motor_volts(int* commands);

void set_servo_pos(int* commands);

void get_sensor_val(int* commands);

/* [] END OF FILE */
