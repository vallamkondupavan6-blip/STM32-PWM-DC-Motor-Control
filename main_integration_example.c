/* Integration example
 *
 * Include:
 *     #include "motor_control.h"
 *
 * After MX_TIM3_Init():
 *
 *     MotorControl_Init(&htim3);
 *
 * Example:
 *
 *     MotorControl_SetDuty(50);   // 50% PWM command
 *     HAL_Delay(2000);
 *     MotorControl_SetDuty(75);   // 75% PWM command
 *     HAL_Delay(2000);
 *     MotorControl_Stop();
 *
 * Configure TIM3 Channel 1 for PWM in STM32CubeIDE.
 * Adjust the timer/channel to match your hardware.
 */
