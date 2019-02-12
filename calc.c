#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define STRINGSIZE  10

void instructions (void);
void getoperand1 (void);
int getoperator (void);
int getoperand2 (void);
void dooperation (void);
void addition (void);
void subtraction (void);
void mutiplication (void);
void division (void);
void memoryclear(void);
void clear(void);
int numcheck(char *s);
void termination(void);



double  num1, num2, memstore;
char operator[STRINGSIZE];

int main(void)
{
	instructions(); /* Display instructions */
	while (1){//Run loop until clear is entered: Once entered program will restart from operand 1
		getoperand1();/*Fuction: to get first operand*/
		while (1) { //Run loop until clear is entered: Once entered program will restart from operand 1
			if(getoperator() == 1) {/*Function: to get operator*/
				break;
			}
			if(getoperand2() == 1) {; /*Function: to get second operand */
				break;
			}
			dooperation (); /*Function: to perform calculation as required */
		}
	}

	return(0);

}

// Function to display instructions
void
instructions (void)
{
	printf("\n\tWelcome to the Calculator\n");
	printf("\tIn this calculator you are required to enter an Operand followed by an Operator and then a secondary Operand\n");
	printf("\tThe calculator is able to perform basic functions such as Addition, Subtraction, Multiplication, and Division\n");
	printf("\tThe calculator also has a basic memory function such as Memory store(MS), Memory Add(M+), Memory Recall(M+), and Memory Clear(MC)\n");
	printf("\tThe calculator's memory fuctions are not case sensitive\n");
	printf("\tYou may press 'X' or 'x' at any time to terminate the program\n");
	printf("\tPlease note the calculator will only display upto 6 digits after a decimal place.\n");
}
//Function to get the first operand
void getoperand1 (void)
{
	char input[STRINGSIZE];
	int ret, needsOperand;
	needsOperand = 1;
	while(needsOperand == 1){//loop to check for valid entry (number or command)

		printf("\nEnter operand: ");
		scanf("%s", input);
		ret = numcheck(input);
		//Obtain number for operand 1
		if ( ret == 1){//If 1 is returned then program will store number in num2 (operand 2) and proceed forward
			sscanf(input, "%lf", &num1);
			needsOperand = 0;//stops loop when valid number is entered
		}
		//to recall memory
		else if ((strcmp(input, "MR")==0) || (strcmp(input,"Mr")== 0) || (strcmp(input, "mR")== 0) || (strcmp(input , "mr")==0)){
			printf("M -> %.6lf\n", memstore);
			num1 = memstore;
			needsOperand = 0;//stops loop when valid number is entered (in this case memory recall)
		}
		//to clear memory
		else if ((strcmp(input, "MC")==0) || (strcmp(input,"Mc")== 0) || (strcmp(input, "mC")== 0) || (strcmp(input , "mc")==0)){
			memoryclear();
		}
		//to clear the values of num1 and num2 (operands 1& 2)
	 	else if ((strcmp(input, "C")==0) || (strcmp(input,"c")== 0)){
                	clear();
		}
		//to terminate program
		else if ((strcmp(input, "X")== 0) || (strcmp(input, "x")== 0)){
			termination();
		}
		//Default for invalid input
		else{
			printf("Sorry, %s, is not a valid operand. Please input a valid operand \n",input);
		}
	}
}

// this function returns 1 if the user input a 'clear' command; otherwise this should return 0.
int getoperator (void)
{
	int needsOperator = 1;
	double memold;
	while (needsOperator == 1 )//loop to check for valid entry (number or command)
	{
		while (getchar() !='\n');//eats new line character
		printf("\n\tEnter operator:  ");
		scanf("%s", operator);
		//to terminate program
		if ((strcmp(operator, "X")== 0) || (strcmp(operator, "x")== 0)){
			termination();
		}
		//to store number as memory
		else if ((strcmp(operator, "MS")== 0) || (strcmp(operator, "Ms")== 0) || (strcmp(operator, "mS")== 0) || (strcmp(operator, "ms")== 0)){
			memstore = num1;
			printf("%.6lf -> M", memstore);
		}
		//to add memory to opperand 1
		else if ((strcmp(operator, "M+")==0) || (strcmp(operator, "m+")== 0)){
			memold = memstore;
			memstore = memstore + num1;
			printf("\n%.6lf +(%.6lf) = %.6lf -> M", num1, memold, memstore);
		}
		//to clear memory
		else if ((strcmp(operator, "MC")==0) || (strcmp(operator,"Mc")== 0) || (strcmp(operator, "mC")== 0) || (strcmp(operator , "mc")==0)){
                	memoryclear();
		}
		//to clear the values of num1 and num2 (operands 1& 2)
		else if ((strcmp(operator, "C")==0) || (strcmp(operator,"c")== 0)){
               		clear();
			return(1);
        	}
		//Check for valid operator
		else if ((strcmp(operator, "+")==0) ||(strcmp(operator, "-")== 0) || (strcmp(operator, "/")== 0) || (strcmp(operator, "*")==0 )){
			needsOperator = 0; /*break loop when valid operator is entered(+ - * /)*/
		}
		//Default for invalid input
		else {
			printf("Sorry, %s, is not a valid operator. Please input a valid operator \n",operator);
		}
	}
	return(0);
}

// this function returns 1 if the user input a 'clear' command; otherwise this should return 0.
int getoperand2 (void)
{
	char input[STRINGSIZE];
        int ret, needsOperand;
	needsOperand = 1;
	while (needsOperand ==1) {//loop to check for valid entry (number or command)

        	printf("\nEnter operand: ");
        	scanf("%s", input);
        	ret = numcheck(input);//identify what numcheck returned and run if statement accordingly
		//obtain number for operand2
        	if ( ret == 1){ //If 1 is returned then program will store number in num2 (operand 2) and proceed forward
                	sscanf(input, "%lf", &num2);
			needsOperand = 0;//stops loop when valid command is entered (in this case memory recal$
        	}
		//to recall memory
        	else if ((strcmp(input, "MR")==0) || (strcmp(input,"Mr")== 0) || (strcmp(input, "mR")== 0) || (strcmp(input , "mr")==0)){
                	printf("M -> %.6lf\n", memstore);
                	num2 = memstore;
			needsOperand = 0;//stops loop when valid command is entered (in this case memory recall)
        	}
		//To clear memory
		else if ((strcmp(input, "MC")==0) || (strcmp(input,"Mc")== 0) || (strcmp(input, "mC")== 0) || (strcmp(input , "mc")==0)){
                	memoryclear();
		}
		//To clear the values of operands 1 and 2
		else if ((strcmp(input, "C")==0) || (strcmp(input,"c")== 0)){
                        clear();
                        return(1);//returns 1 if "c" or "C" is entered other wise returns 0
                }
		//to terminate program
		else if ((strcmp(input, "X")== 0) || (strcmp(input, "x")== 0)){
                        termination();
		}
		//Default to invalid input
        	else{
			printf("Sorry, %s, is not a valid operand. Please input a valid operand \n",input);
		}
	}
	return(0);
}
//Function to call operator functions as required
void
dooperation (void)
{
	if (strcmp (operator, "+")== 0) {//case addition : call addition function
		addition ();
	}
	if  (strcmp (operator, "-")== 0) {//case subtraction : call subtraction function
		subtraction ();
	}
	if (strcmp (operator, "*")== 0){//case mutiplication : call mutiplication function
		mutiplication ();
	}
	if (strcmp (operator, "/")==0){//case division : call division function
		division ();
	}
}
//Function to perform addition
void
addition (void)
{
	printf("%.6lf + %.6lf = %.6lf", num1, num2, num1 + num2);
        num1 = num1 + num2;
}
//Function to perform subtraction
void
subtraction (void)
{
	printf("%.6lf - %.6lf = %.6lf", num1, num2, num1 - num2);
        num1 = num1 - num2;
}
//Function to perform mutiplication
void
mutiplication (void)
{
	printf("%.6lf * %.6lf = %.6lf", num1, num2, num1 * num2);
        num1 = num1 * num2;
}
//Function to perform division
void
division (void)
{
	while (num2 == 0){ //to error check for 0
        	printf("\nCan't divide by 0. Please re-enter  divisor");
		printf("\nEnter operand");
		scanf("%lf", &num2);
        }
	printf("%.6lf / %.6lf = %.6lf", num1, num2, num1 / num2);
        num1 = num1 / num2;
}
//Function checks to see if a number or a commad was entered
int numcheck (char *s)
{
	double number;
	char extracharacters;

	if (sscanf(s, "%lf %c", &number, &extracharacters) ==1){//scan input for number or letter
		return(1);//return 1 if number is entered
	}
	else
	{
		return(0);//return 0 if a command is entered
	}

}
//Function to clear memory
void memoryclear (void)
{
	printf("Memory cleared");
	memstore = 0;

}
//Function to clear operands 1 and 2
void clear(void)
{
	num1 = 0;
	num2 = 0;
	printf("Results cleared");
}
//Termination function
void termination(void)
{
 	printf("Good Bye\n");
        exit(1);

}


