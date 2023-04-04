/*
    title: LCD Driver header
    author: Omar Essam
*/
#ifndef _LCD_HEADER_H
#define _LCD_HEADER_H

#include "L_stdu.h"
#include "L_bitmath.h"
#include "MdioHeader.h"
#include <util/delay.h>

#define LCD1Line LOW
#define LCD2Line HIGH
#define LCDON HIGH
#define LCDOFF LOW
#define CURSOR LOW
#define DISPLAY HIGH
#define LEFT LOW
#define RIGHT HIGH


void LcdInit(u8 SetNumOfLines);
void ClearLcd();
void ReturnHomeLcd();
void SetCursorSettings(u8 SetCursorLCDONorOFF,u8 SetCursorBlink);
void ShiftCursorDisplay(u8 SetShiftCursorDisplay, u8 ShiftLeftorRight);
void SetPosition(u8 SetLine,u8 SetCharacter);
void WriteLcd(u8* String);
#endif