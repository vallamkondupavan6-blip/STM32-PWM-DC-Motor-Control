# STM32 PWM DC Motor Control

A reference/demo implementation showing PWM-based DC motor speed control using an STM32F407VG.

> **Project Status:** Reference implementation for STM32F407VG PWM motor control. Hardware validation is pending.

## Features

- PWM generation using STM32 timer peripheral
- Variable motor speed control through duty cycle
- GPIO-based motor enable/control
- Simple speed command interface
- Embedded C using STM32 HAL

## System Architecture

```text
             STM32F407VG
                  |
             Timer PWM
                  |
                  v
            Motor Driver
                  |
                  v
              DC Motor
```

## Speed control

The PWM duty cycle determines the average voltage delivered to the motor driver:

```text
25%  -> Low speed
50%  -> Medium speed
75%  -> High speed
100% -> Maximum command
```

Actual motor speed depends on the motor, driver, supply voltage, load, and mechanical conditions.

## Suggested hardware

- STM32F407VG development board
- DC motor
- H-bridge/motor driver module
- External motor supply
- Common ground between controller and driver

**Do not power a DC motor directly from an STM32 GPIO pin. Use an appropriate motor driver.**

## Example commands

```text
SPEED 25
SPEED 50
SPEED 75
SPEED 100
STOP
```

## Technologies

- Embedded C
- STM32F407VG
- STM32 HAL
- Timers
- PWM
- GPIO
- Motor-driver interfacing

## How it works

A timer peripheral generates a PWM signal. The firmware changes the timer compare value to modify the duty cycle. The PWM signal is connected to the enable/speed-control input of a motor driver.

For a timer period represented by `ARR`, the approximate duty cycle is:

```text
Duty Cycle (%) = CCR / ARR × 100
```

where `CCR` is the timer compare value.

## STM32CubeIDE integration

Configure a timer channel for PWM output in STM32CubeIDE. Start PWM after peripheral initialization:

```c
HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
```

Then change the duty cycle with:

```c
__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, compare_value);
```

Adjust the timer/channel and GPIO settings to match the target board and motor driver.

## Future improvements

- Quadrature encoder feedback
- Closed-loop speed control
- PID controller
- Direction control
- Over-current protection
- FreeRTOS motor-control task
