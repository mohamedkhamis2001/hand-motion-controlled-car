/*
title: DIO Driver header
author: Mohamed Khamis
version: 0
date: 13/12/2022
*/

#ifndef _MDIO_HEADER_H
#define _MDIO_HEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"

#define INPUT 0x00
#define OUTPUT 0xff
#define LOW 0x00
#define HIGH 0xff

#define PA 0
#define PB 1
#define PC 2
#define PD 3  

typedef enum pins
{
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7,
}pins;

void SetPortDir(u8 PortName,u8 PortDir);
void SetPortValue(u8 PortName,u8 PortValue);
u8 ReadPortValue(u8 PortName);
void SetPinDir(u8 PortName,u8 PinNum,u8 PinDir);
void SetPinValue(u8 PortName,u8 PinNum,u8 PinValue);
u8 ReadPinValue(u8 PinName,u8 PinNum);




#endif