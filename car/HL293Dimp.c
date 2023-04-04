/*
    title: HL293D Driver implementation.
    author: Omar Essam
*/

#include "HL293DHeader.h"



void L293D_Init()
{
    DDRC=0xFF;
    DDRD |= (1<<PD4);
  	DDRD |= (1<<PD5);
	TCCR1A = (1<<COM1A1) + (1<<WGM11) + (1<<COM1B1); 
  	TCCR1B = (1<<WGM13) + (1<<WGM12) + (1<<CS10);
  	ICR1 = 0xffff;
    OCR1A =0;
	OCR1B =0;	 
}

void L293D_SetMotorDir(u8 SelectMotor,u8 MotorMode)
{

    switch (SelectMotor)
    {
    case MOTOR_A:
   
        switch (MotorMode)
         {
            case FORWARD:

                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                PORTC_io |=(1<<PC3)+(0<<PC4);
            
                break;      
            case BACKWARD:
               
                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                PORTC_io |=(0<<PC3)+(1<<PC4);
               
                break;   
            case STOP:
                PORTC_io &=(~(1<<PC3))+(~(1<<PC4));
                break;

            default:
                break;
            }
    
    case MOTOR_B:
   
        switch (MotorMode)
         {
         case FORWARD:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             PORTC_io |=(1<<PC5)+(0<<PC6);
             break;      
         case BACKWARD:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             PORTC_io |=(0<<PC5)+(1<<PC6);
             break;       
         case STOP:
             PORTC_io &=(~(1<<PC5))+(~(1<<PC6));
             break;
         default:
             break;
         }

        break;
    
    default:
        break;
    }   
    
    
 
}

void L293D_SetMotorSpeed(u8 SetMotorSpeed) //(0:100)
{
    u16 Speed = SetMotorSpeed*655.0;
    OCR1A = Speed;
    OCR1B = Speed;
}

