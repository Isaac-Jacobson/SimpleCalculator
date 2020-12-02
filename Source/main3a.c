/*****************************************************************************
* Programmer: Isaac Jacobson
* Class: ECE 251; Lab Section 7
* Programming Assignment: Lab 3a - BMI Calculator w/ Functions!
*
* Date: 9/8/20
*
* Description: This program calculates the BMI of a person given their height
*			in feet+inches and weight in pounds.
*
* Relevant Formulas: BMI = ((weight in pounds)/(height in inches)^2)*703
*****************************************************************************/

#include <stdint.h>
#include "utils/uartstdio.h"
#include "ECE251_util.h"
#include "prob3a.h"

int main(void)
{
		// Set up system clock
		// Set up GPIO to output to LEDs
    SystemInit();

    // Initialize the UART.
    ConfigureUART(); 
		setup();
	  doTheThing();
    // We are finished. Since this is an embedded system, hang around
    while(1)
    {
       
    }
}

