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

typedef void (*controlFunction)(short*);

typedef struct {
    char* data;
    short* args;
    controlFunction fn;
} controlCommand;

/* [] END OF FILE */
