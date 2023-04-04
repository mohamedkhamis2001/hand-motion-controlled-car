#include "MdioHeader.h"
#include "MUARTHeader.h"
#include "MADCHeader.h"
#include "LCDHeader.h"
#include "util/delay.h"


#define FORWARD_BIT 7
#define BACKWARD_BIT 6
#define RIGHT_BIT 5
#define LEFT_BIT 4



int main()
{   
   //initialization
   ADCInit();
   SetUARTConfig(MUART_PARITY_DISABLED, MUART_ONE_STOP_BIT, MUART_8BIT, MUART_BUAD9600);
   SetPinDir(PC,pin0,OUTPUT);
   
   u16 f1,f2,f3,f4,f5;       // flex sensors 
   u8 MovementData;


    while (1)
    {
        ADC_getDigitalValue(adc0 , &f1);      //pinky
        ADC_getDigitalValue(adc1 , &f2);      //ring 
        ADC_getDigitalValue(adc2 , &f3);      //middle
        ADC_getDigitalValue(adc3 , &f4);      //index
        ADC_getDigitalValue(adc4 , &f5);      //thumb
              
        MovementData = 0;

        //thumb finger (f5) is for setting speed level
        if(f5 <= 558 && f5 > 516) //speed 1
        {
           MovementData = 1; 
        }
        else if(f5 <= 516 && f5 > 475) //speed 2
        {
           MovementData = 2; 
        }
        else if(f5 <= 475 && f5 > 433) //speed 3
        {
           MovementData = 3; 
        }
        else if(f5 <= 433 && f5 > 392) //speed 4
        {
           MovementData = 4; 
        }

        

        
        //(f1, f2, f3, f4) are the direction sensors
        
        //Idel
        if((f1 > 593) && (f2 > 593) && (f3 > 593) && (f4 > 565)) 
        {   
            CLEAR_NIBBLE_HIGH(MovementData);
            SerialWriterFrame(MovementData);
        }
        
        //Forward
        else if((f1 > 570) && (f2 < 550) && (f3 < 550) && (f4 > 565))
        {   
            SET_BIT(MovementData, FORWARD_BIT);
            SerialWriterFrame(MovementData);
        }
        
        //Backward
        else if((f1 < 520) && (f2 < 520) && (f3 < 520) && (f4 < 520))
        {   
            SET_BIT(MovementData, BACKWARD_BIT);
            SerialWriterFrame(MovementData);
        }

        //Right
        else if((f1 < 550) && (f2 < 513) && (f3 < 513) && (f4 > 565))
        {   
            SET_BIT(MovementData, RIGHT_BIT);
            SerialWriterFrame(MovementData);
        }

        //Left
        else if((f1 > 540) && (f2 > 545) && (f3 < 530) && (f4 < 450))
        {   
            SET_BIT(MovementData, LEFT_BIT);
            SerialWriterFrame(MovementData);
        }                    
    
    }


    return 0;
}
