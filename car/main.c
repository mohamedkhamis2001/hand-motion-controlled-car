#include "MdioHeader.h"
#include "HL293DHeader.h"
#include "MUARTHeader.h"
#include "LCDHeader.h"
#include "string.h"

#define FORWARD_BIT 7
#define BACKWARD_BIT 6
#define RIGHT_BIT 5
#define LEFT_BIT 4


int main()
{ 
  //initiation
  L293D_Init();
  LcdInit(LCD2Line);
  SetCursorSettings(LCDON, LCDON);
  SetUARTConfig(MUART_PARITY_DISABLED, MUART_ONE_STOP_BIT, MUART_8BIT, MUART_BUAD9600);
  
  //lighting the LEDs
  SetPinDir(PC,pin2,OUTPUT);
  SetPinDir(PC,pin7,OUTPUT);
  SetPinDir(PD,pin3,OUTPUT);
  SetPinValue(PC,pin2,HIGH);
  SetPinValue(PC,pin7,HIGH);
  SetPinValue(PD,pin3,HIGH);
  
  u8 LCD_Display = 0;
  u8 MovementData;
  u8 speed;
  
  while(1)
  { 
    
    MovementData = 0;
    MovementData = SerialReadFrame();
    speed = (MovementData & 0b00000111)*25;


    //Idel
    if ((MovementData == speed) || (speed==0) )
    {
      //displaying movement direction
      if(LCD_Display != 5)
      {
      ClearLcd();
      WriteLcd((u8*)"Idle");
      LCD_Display = 5;
      }
      
      //LEDs
      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,LOW);

      //motor movement
      L293D_SetMotorDir(MOTOR_A,STOP);
      L293D_SetMotorDir(MOTOR_B,STOP);
      L293D_SetMotorSpeed(0);
    
    }


    //forward
    else if((GET_BIT(MovementData, FORWARD_BIT) == 1) && speed != 0)
    {
      if(LCD_Display != 1)
      {
        ClearLcd();
        WriteLcd((u8*)"forward");
        LCD_Display = 1;
      }   

      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,HIGH);
      SetPinValue(PD,pin3,LOW);

      
      L293D_SetMotorDir(MOTOR_A,FORWARD);
      L293D_SetMotorDir(MOTOR_B,FORWARD);
      L293D_SetMotorSpeed(speed);
    

    }

    //backward
    else if((GET_BIT(MovementData, BACKWARD_BIT) == 1) && speed != 0)
    { 
      if(LCD_Display != 2)
      {
        ClearLcd();
        WriteLcd((u8*)"Backward");
        LCD_Display = 2;
      }


      SetPinValue(PC,pin2,HIGH);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,HIGH);

      
      L293D_SetMotorDir(MOTOR_A,BACKWARD);
      L293D_SetMotorDir(MOTOR_B,BACKWARD);
      L293D_SetMotorSpeed(speed);
    
    }

    //right
    else if((GET_BIT(MovementData, RIGHT_BIT) == 1) && speed != 0)
    {
      
      if(LCD_Display != 3)
      {
        ClearLcd();
        WriteLcd((u8*)"right");
        LCD_Display = 3;
      }


      SetPinValue(PC,pin2,HIGH);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,LOW);


      L293D_SetMotorDir(MOTOR_A,FORWARD);
      L293D_SetMotorDir(MOTOR_B,BACKWARD);
      L293D_SetMotorSpeed(speed);
    
    }

    //left
    else if((GET_BIT(MovementData, LEFT_BIT) == 1) && speed != 0)
    {
      if(LCD_Display != 4)
      {
        ClearLcd();
        WriteLcd((u8*)"left");
        LCD_Display = 4;
      }


      SetPinValue(PC,pin2,LOW);
      SetPinValue(PC,pin7,LOW);
      SetPinValue(PD,pin3,HIGH);

      
      L293D_SetMotorDir(MOTOR_A,BACKWARD);
      L293D_SetMotorDir(MOTOR_B,FORWARD);
      L293D_SetMotorSpeed(speed);
    
    }
    else
    {
    }
  }

  return 0;
}