/*
    title: HL293D Driver Header
    author: Omar Essam
*/
#ifndef _HL293D_HEADER_H
#define _HL293D_HEADER_H

    #include"L_stdu.h"
    #include "avr/io.h"

    #define FORWARD 0
    #define BACKWARD 1
    #define STOP 4
    #define MOTOR_A 0
    #define MOTOR_B 1


    void L293D_Init();
    void L293D_SetMotorDir(u8 SelectMotor,u8 MotorMode);
    void L293D_SetMotorSpeed( u8 SetMotorSpeed);

#endif
