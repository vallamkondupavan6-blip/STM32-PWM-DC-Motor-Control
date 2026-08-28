#include "motor_control.h"

static TIM_HandleTypeDef *motor_timer = NULL;

#define MOTOR_CHANNEL TIM_CHANNEL_1

void MotorControl_Init(TIM_HandleTypeDef *htim)
{
    motor_timer = htim;
    HAL_TIM_PWM_Start(motor_timer, MOTOR_CHANNEL);
    MotorControl_Stop();
}

void MotorControl_SetDuty(uint8_t duty_percent)
{
    uint32_t period;
    uint32_t compare;

    if (motor_timer == NULL)
        return;

    if (duty_percent > 100)
        duty_percent = 100;

    period = __HAL_TIM_GET_AUTORELOAD(motor_timer);

    compare = ((period + 1U) * duty_percent) / 100U;

    if (compare > period)
        compare = period;

    __HAL_TIM_SET_COMPARE(motor_timer, MOTOR_CHANNEL, compare);
}

void MotorControl_Stop(void)
{
    MotorControl_SetDuty(0);
}
