#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "main.h"
#include <stdint.h>

void MotorControl_Init(TIM_HandleTypeDef *htim);
void MotorControl_SetDuty(uint8_t duty_percent);
void MotorControl_Stop(void);

#endif
