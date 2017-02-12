/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW03_141044041_Burak_Kagan_Korkmaz.c                                     */ 
/*																			*/
/* -------------------------------------------								*/ 
/* Created on 04/03/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW03_141044041_Burak_Kagan_Korkmaz_part1.c contains three helper 	*/ 
/*    function and main function for the homework 3. This program says  	*/ 
/*	  whether a positive number, which user entered	is an odd or factorial 	*/ 
/*    or narcissistic number.	In main function, a positive integer is 	*/
/*    received from user and visible part of program is done here.(printf)  */
/*    One of other three function  computes the parity(odd or even) of      */
/*    number. Second one computes that user's number is factorial number or */
/*    not and the last one computes the number is whether a narcissistic    */
/*    number or not.                                                        */
/*                                                                          */
/* Notes                                                                    */
/* -----                                                                    */
/*      Let's keep a positive number and number of digis of this number     */
/*      will be "n". If our number is sum of nth power of each of the       */
/*      digits are equal itself, this number is Narcissistic Number".       */
/*      For example, 371 --> have 3 digits                                  */
/*                       --> 3^3 + 7^3 + 1^3                                */
/*                          = 81 + 343 + 1      = 371 (it's equal itself)   */
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*								Includes									*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   /* pow(x,y) function */

/*--------------------------------------------------------------------------*/ 
/*								Defines							    		*/
/*--------------------------------------------------------------------------*/
#define ODDNUMBER '1'
#define FACTORIAL '2'
#define NARCISST '3'

#define TRUE 1
#define FALSE 0

#define YES 'y'
#define NO 'n'

/*--------------------------------------------------------------------------*/ 
/*							Function Prototypes			                    */
/*--------------------------------------------------------------------------*/
int oddNumber(int positive);
int factorialNumber(int positive);
int narcissisticNumber(int positive);

/*--------------------------------------------------------------------------*/ 
/*							    Main Function 			                    */
/*--------------------------------------------------------------------------*/
int main(){

/* Declaration of variables */
int positive; 
char property;
char answer; 

	printf("********************************************************\n");
	printf("*                      WELCOME!                        *\n");
	printf("*    This program checks whether the given number      *\n");
	printf("*   is an odd, a factorial or a narcissistic number    *\n");
	printf("*                                                      *\n");
	printf("********************************************************\n");

	
    
    do{

        printf("\nPlease enter a positive integer : ");
        scanf("%d",&positive);
	        
        if (!(positive > 0)){       /* Negativity Control */
	        printf("The entered number is not positive.\n");
	     
        }
        else {   /* Asking the property of number to user  */
	        printf("Which property would you like to check?\n");
	        printf("1)Odd number\n2)Factorial number\n");
	        printf("3)Narcissistic number\n");
	        do{
	            printf("Please enter(1/2/3): ");
	            scanf(" %c", &property);
	        }      
	        while (property != ODDNUMBER && property != FACTORIAL 
	                                     && property != NARCISST);
	    
	        
            if (property == ODDNUMBER){     /* User entered 1 */
                
                if (oddNumber(positive) == TRUE){
	                printf("%d is an odd number !\n", positive);
	         
                }
                else{
	                
	                printf("%d is not an odd number !\n", positive);
	                
	             
                }
            }
            else if (property == FACTORIAL){    /* User entered 2 */
                
                if (factorialNumber(positive) == TRUE){
                
                    printf("%d is a factorial number !\n", positive);
            
                }
                else{
	               
	                printf("%d is not a factorial number !\n", positive);
	                
                }
            }
            else if (property == NARCISST){     /* User entered 3 */
                
                if (narcissisticNumber(positive) == TRUE){
                    printf("%d is a narcisstic number !\n", positive);
                  
                }
                else{
                    
                    printf("%d is not a narcisstic number !\n", positive);
                   
                }
            }
        }    
        /* Checking continuity process */
	        printf("Do you want to continue (y/n)? ");
	        scanf(" %c", &answer);
        
        /* When you enter a character expect 'y' or 'n', it is ask again */
        while (answer != YES && answer != NO){
            printf("Do you want to continue (y/n)? ");
	        scanf(" %c", &answer);
        }
       
        if (answer == NO){
            printf("Good Bye!\n");
        }
       
    
    } while(answer == YES);
    
return 0;
}
/*--------------------------------------------------------------------------*/ 
/*						   End of Main Function			                    */
/*--------------------------------------------------------------------------*/



/* This function detects whether the positive number is odd or not thereby
 finding remainder from dividing 2 and return true or false. */
int oddNumber(int positive){

	if (positive %2 == 1){
		return TRUE;
	}
	else{
		return FALSE;				
	}
}

/* This function detects whether the positive number is factorial or not. 
It uses loop for this operation and returns true or false. */
int factorialNumber(int positive){
	int i;	
	int num = 1;

	for (i=1; num <= positive; ++i){
		num *= i;
		
		if(positive == num)
			return TRUE;
	}

		return FALSE;
	
}

/* This function detects whether the positive number is narcissistic or not. 
It uses two while loops for this operation. One of while loops determines 
number of digits. Another one gets digits of the number and takes its power 
of digits. Lastly, the function returns true or false. */
int narcissisticNumber(int positive){
	
	/* Variables */
	int backup = positive;  /* positive backing up for save variety of number*/
	int counter = 0;
	int mod;
	int result = 0;
	

/* Counter identify number of digit of integer */
	while (backup > 0){
		backup /= 10;
		++counter;
	}

	backup = positive;  /* positive copying again (initialization) */
	
	while(backup > 0){
		mod = backup % 10;          /* Get last digit */
		result += pow(mod,counter);    /* Add powers of mod to result */
		backup = backup / 10;   /* Next digit is shifted to right */
    }
     
    if(positive == result){
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/
/*                  End of HW03_141044041_Burak_Kagan_Korkmaz.c              */ 
/*---------------------------------------------------------------------------*/
