/*
title: DIO Driver implementation
author: Mohamed Khamis
version: 0
date: 13/12/2022
*/
#include "MdioHeader.h"
#include "MdioPrivate.h"



void SetPortDir(u8 PortName,u8 PortDir)
{
    switch (PortName)
    {
    case PA:
        PortDir = PortDir == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTA->ddr) : PortDir;
        PortDir = PortDir == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTA->ddr) : PortDir ;
        PortDir = PortDir == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTA->ddr) : PortDir;
        PortDir = PortDir == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTA->ddr) : PortDir ;
        PORTA->ddr=PortDir;
         if(PortDir==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTA->ddr);
            SET_BYTE(PORTA->port);
        }
        if(PortDir==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTA->ddr);
            SET_NIBBLE_LOW(PORTA->port);
        }
         if(PortDir==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTA->ddr);
            SET_NIBBLE_HIGH(PORTA->port);
        }
        break;
    case PB:
        PortDir = PortDir == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTB->ddr) : PortDir;
        PortDir = PortDir == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTB->ddr) : PortDir ;
        PortDir = PortDir == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTB->ddr) : PortDir;
        PortDir = PortDir == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTB->ddr) : PortDir ;
        PORTB->ddr=PortDir;
         if(PortDir==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTB->ddr);
            SET_BYTE(PORTB->port);
        }
        if(PortDir==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTB->ddr);
            SET_NIBBLE_LOW(PORTB->port);
        }
         if(PortDir==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTB->ddr);
            SET_NIBBLE_HIGH(PORTB->port);
        }
        break;
    case PC:
        PortDir = PortDir == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTC->ddr) : PortDir;
        PortDir = PortDir == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTC->ddr) : PortDir ;
        PortDir = PortDir == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTC->ddr) : PortDir;
        PortDir = PortDir == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTC->ddr) : PortDir ;
        PORTC->ddr=PortDir;
        if(PortDir==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTC->ddr);
            SET_BYTE(PORTC->port);
        }
        if(PortDir==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTC->ddr);
            SET_NIBBLE_LOW(PORTC->port);
        }
        if(PortDir==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTC->ddr);
            SET_NIBBLE_HIGH(PORTC->port);
        }
        break;
    case PD:
        PortDir = PortDir == LOWER_NIPPLE_INPUT ? CLEAR_NIBBLE_LOW(PORTD->ddr) : PortDir;
        PortDir = PortDir == LOWER_NIPPLE_OUTPUT ? SET_NIBBLE_LOW(PORTD->ddr) : PortDir ;
        PortDir = PortDir == HIGHER_NIPPLE_INPUT ? CLEAR_NIBBLE_HIGH(PORTD->ddr) : PortDir;
        PortDir = PortDir == HIGHER_NIPPLE_OUTPUT ? SET_NIBBLE_HIGH(PORTD->ddr) : PortDir ;
        PORTD->ddr=PortDir;
         if(PortDir==INPUT_PULLUP)
        {   
            CLEAR_BYTE(PORTD->ddr);
            SET_BYTE(PORTD->port);
        }
        if(PortDir==LOWER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_LOW(PORTD->ddr);
            SET_NIBBLE_LOW(PORTD->port);
        }
         if(PortDir==HIGHER_NIPPLE_INPUT_PULLUP)
        {   
            CLEAR_NIBBLE_HIGH(PORTD->ddr);
            SET_NIBBLE_HIGH(PORTD->port);
        }
        break;
    default:
        break;
    }
    return;
}
void SetPortValue(u8 PortName,u8 ARGPortValueU8)
{
    switch (PortName)
    {
    case PA:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTA->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTA->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTA->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTA->port) : ARGPortValueU8;
        PORTA->port=ARGPortValueU8;
        break;
    case PB:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTB->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTB->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTB->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTB->port) : ARGPortValueU8;
        PORTB->port=ARGPortValueU8;
        break;
    case PC:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTC->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTC->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTC->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTC->port) : ARGPortValueU8;
        PORTC->port=ARGPortValueU8;
        break;
    case PD:
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_LOW ? CLEAR_NIBBLE_LOW(PORTD->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == LOWER_NIPPLE_HIGH ? SET_NIBBLE_LOW(PORTD->port) : ARGPortValueU8 ;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_LOW ? CLEAR_NIBBLE_HIGH(PORTD->port) : ARGPortValueU8;
        ARGPortValueU8 = ARGPortValueU8 == HIGHER_NIPPLE_HIGH ? SET_NIBBLE_HIGH(PORTD->port) : ARGPortValueU8;
        PORTD->port=ARGPortValueU8;
        break;
    default:
        break;
    }
    return;
}
u8 ReadPortValue(u8 PortName)
{
    switch (PortName)
    {
    case PA:
        return PORTA->pin;
        break;
    case PB:
        return PORTB->pin;
        break;
    case PC:
        return PORTC->pin;
        break;
    case PD:
        return PORTD->pin;
        break;
    default:
        break;
    }
    return 0;
}
void SetPinDir(u8 PortName,u8 ARGPinNumU8,u8 ARGPinDirU8)
{
    switch(ARGPinDirU8){
        case INPUT:
            switch (PortName)
            {
            case PA:
                CLEAR_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
        case OUTPUT:
            switch (PortName)
            {
            case PA:
                SET_BIT(PORTA->ddr,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->ddr,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->ddr,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->ddr,ARGPinNumU8);
                break;
            default:
                break;
            }
    }  
    return;   
}
void SetPinValue(u8 PortName,u8 ARGPinNumU8,u8 ARGPinValueU8)
{
    switch(ARGPinValueU8){
        case LOW:
            switch (PortName)
            {
            case PA:
                CLEAR_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                CLEAR_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                CLEAR_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                CLEAR_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
        case HIGH:
            switch (PortName)
            {
            case PA:
                SET_BIT(PORTA->port,ARGPinNumU8);
                break;
            case PB:
                SET_BIT(PORTB->port,ARGPinNumU8);
                break;
            case PC:
                SET_BIT(PORTC->port,ARGPinNumU8);
                break;
            case PD:
                SET_BIT(PORTD->port,ARGPinNumU8);
                break;
            default:
                break;
            }
            break;
    }

   return;         
}
u8 ReadPinValue(u8 PortName,u8 ARGPinNumU8)
{
    switch (PortName)
    {
    case PA:
        return GET_BIT(PORTA->pin,ARGPinNumU8);
        break;
    case PB:
        return GET_BIT(PORTB->pin,ARGPinNumU8);
        break;
    case PC:
       return GET_BIT(PORTC->pin,ARGPinNumU8);
        break;
    case PD:
       return GET_BIT(PORTD->pin,ARGPinNumU8);
        break;
    default:
        break;
    }
    return 0;
}
void TogglePort(u8 PortName)
{
    switch (PortName)
    {
    case PA:
        TOGGLE_BYTE(PORTA -> port);
        break;
    case PB:
        TOGGLE_BYTE(PORTB -> port);
        break;
    case PC:
        TOGGLE_BYTE(PORTC -> port);
        break;
    case PD:
        TOGGLE_BYTE(PORTD -> port);
        break;    
    default:
        break;
    }
}
void TogglePin(u8 PortName, u8 ARGPinNumU8)
{
    switch (PortName)
    {
    case PA:
        TOGGLE_BIT(PORTA -> port, ARGPinNumU8);
        break;
    case PB:
        TOGGLE_BIT(PORTB -> port, ARGPinNumU8);
        break;
    case PC:
        TOGGLE_BIT(PORTC -> port, ARGPinNumU8);
        break;
    case PD:
        TOGGLE_BIT(PORTD -> port, ARGPinNumU8);
        break;    
    default:
        break;
    }
}