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

#include "prob3a.h"
#include <stdint.h>
#include <stdio.h>
#include "utils/uartstdio.h"

void doTheThing(){
	int numOne = 0;
	int numTwo = 0;
	char operation;
	char current = '0';
	char quit = '\0';
	char equals = '\0';
	do{
		current = UARTgetc();
		if(current == 'Q'){
					quit = current;
					break;
		}else{
			do{
				numOne = char2int(current);
				operation = UARTgetc();
				numTwo = getNum();
				equals = UARTgetc();
				if(equals != '='){
					UARTprintf("\nBad input, try again!\n");
					doTheThing();
				}
			}while(numOne < -1 || numOne > 10 || numTwo < -1 || numTwo > 10);
		}
			wait(10);
			displayAnswer(calculate(numOne, numTwo, operation));
		}while(quit != 'Q');
		end();
}

int getNum(){
	char num = '\0';
	do{
		num = UARTgetc();
	}while(isDigit(num) == 0);
	
	return char2int(num);
}
int toNum(int num[]){
	int digits = 0;
	int index = 0;
	while(isDigit(num[index] == 1)){
		digits++;
		index++;
	}
	if(digits == 1){
		return num[0];
	}else if(digits == 2){
		return (num[0] * 10) + num[1];
	}else if(digits == 3){
		return (num[0] * 100) + (num[1] * 10) + num[2];
	}
	return 0;
}

int isDigit(char c){
	if(c >= '0' && c <= '9'){
		return 1;
	}
	return 0;
}

double calculate(int numOne, int numTwo, char operation){
	double answer = 0;
	if(operation == '+'){
		answer = (double) (numOne + numTwo);
	}else if(operation == '-'){
		answer = (double) (numOne - numTwo);
	}else if(operation == '*'){
		answer = (double) (numOne * numTwo);
	}else if(operation == '/'){
		answer = (double) numOne / (double) numTwo;
	}else if(operation == '%'){
		answer =(double) (numOne % numTwo);
	}else{
		UARTprintf("\nBad input, try again!\n");
		doTheThing();
	}
	return answer;
}

void setup(){
	UARTprintf("Welcome to the Calculator\n");
}

void end(){
	UARTprintf("\nThanks for coming!\n");
	while(1){
    }
}

void wait(int n){
	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3500000; j++){
			k += 1;
		}
	}
}

int char2int (char digit){
		return (digit - 48);
}


void displayAnswer (double answer){
		char buffer[20]; // buffer to hold converted bmi to string
		sprintf(buffer, "%f", answer); // convert from double to string
		UARTprintf("%s\n", buffer); // print out BMI over UART
}
