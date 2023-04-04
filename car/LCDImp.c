/*
    title: LCD Driver imp
    author: Omar Essam
*/

#include "LCDHeader.h"

void LcdInit(u8 SetNumOfLines)
{   
    _delay_ms(100);
    //data bits from LSB to MSB 
    SetPinDir(PA, pin4, OUTPUT);
    SetPinDir(PA, pin5, OUTPUT);
    SetPinDir(PA, pin6, OUTPUT);
    SetPinDir(PA, pin7, OUTPUT);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);

    //Rs
    SetPinDir(PB, pin1, OUTPUT);
    //RW
    SetPinDir(PB, pin2, OUTPUT);
    //EN
    SetPinDir(PB, pin3, OUTPUT);

    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    SetPinValue(PB, pin3, LOW);
    
    // init
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, HIGH);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);

    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);

    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, SetNumOfLines);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    ClearLcd();
    ReturnHomeLcd();
   
    return;
}
void ClearLcd()
{
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, HIGH);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    return;
}
void ReturnHomeLcd()
{   
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, HIGH);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    return;
}
void SetCursorSettings(u8 SetCursorONorOFF,u8 SetCursorBlink)
{
    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, SetCursorBlink == LCDON ? HIGH : LOW);
    SetPinValue(PA, pin5, SetCursorONorOFF == LCDON ? HIGH : LOW);
    SetPinValue(PA, pin6, HIGH);
    SetPinValue(PA, pin7, HIGH);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
   _delay_ms(5);

    return;
}
void ShiftCursorDisplay(u8 SetShiftCursorDisplay, u8 ShiftLeftorRight)
{
    SetPinValue(PA, pin4, HIGH);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, LOW);
    SetPinValue(PA, pin7, LOW);
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);

    SetPinValue(PA, pin4, LOW);
    SetPinValue(PA, pin5, LOW);
    SetPinValue(PA, pin6, ShiftLeftorRight);   // choose direction left or right
    SetPinValue(PA, pin7, SetShiftCursorDisplay); // choose which to shift cursor or display
   
    SetPinValue(PB, pin1, LOW);
    SetPinValue(PB, pin2, LOW);
    _delay_ms(1);
    SetPinValue(PB, pin3, HIGH);
    _delay_ms(1);
    SetPinValue(PB, pin3, LOW);
    _delay_ms(1);
    _delay_ms(5);
    
    return;
}
void SetPosition(u8 SetLine,u8 SetCharacter)
{
    switch (SetLine)
    {
    case LCD1Line:
        SetCharacter = SetCharacter > 0xf ? 0xf : SetCharacter; //line 1
        break;
    case LCD2Line:
        SetCharacter = SetCharacter > 0xf ? 0x4f : SetCharacter + 0x40; // line 2
        break;
    default:
        break;
    }
        SetPinValue(PA, pin4, GET_BIT(SetCharacter ,4) ?  HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(SetCharacter ,5) ?  HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(SetCharacter ,6) ?  HIGH : LOW);
        SetPinValue(PA, pin7, HIGH);
    
        SetPinValue(PB, pin1, LOW);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);

        SetPinValue(PA, pin4,GET_BIT(SetCharacter ,0) ?  HIGH : LOW );
        SetPinValue(PA, pin5,GET_BIT(SetCharacter ,1) ?  HIGH : LOW );
        SetPinValue(PA, pin6,GET_BIT(SetCharacter ,2) ?  HIGH : LOW );
        SetPinValue(PA, pin7,GET_BIT(SetCharacter ,3) ?  HIGH : LOW );
    
        SetPinValue(PB, pin1, LOW);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);
        _delay_ms(5);
        return;
}
void WriteLcd(u8* String)
{
    u8 count = 0 ;
    while (String[count] != '\0')
    {   
        if(String[count] == '\n')
        {
            SetPosition(LCD2Line,0);
        }
        else
        {
        SetPinValue(PA, pin4, GET_BIT(String[count], 4) ? HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(String[count], 5) ? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(String[count], 6) ? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(String[count], 7) ? HIGH : LOW);
    
        SetPinValue(PB, pin1, HIGH);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1);

        SetPinValue(PA, pin4, GET_BIT(String[count], 0) ? HIGH : LOW);
        SetPinValue(PA, pin5, GET_BIT(String[count], 1) ? HIGH : LOW);
        SetPinValue(PA, pin6, GET_BIT(String[count], 2) ? HIGH : LOW);
        SetPinValue(PA, pin7, GET_BIT(String[count], 3) ? HIGH : LOW);
    
        SetPinValue(PB, pin1, HIGH);
        SetPinValue(PB, pin2, LOW);
        _delay_ms(1);
        SetPinValue(PB, pin3, HIGH);
        _delay_ms(1);
        SetPinValue(PB, pin3, LOW);
        _delay_ms(1); 
        } 
        count++;
    }
    
    return;
}

