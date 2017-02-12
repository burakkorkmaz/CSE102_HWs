/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW04_141044041_Burak_Kagan_Korkmaz_part2.c                               */ 
/*																			*/
/* -------------------------------------------								*/ 
/* Created on 21/03/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW04_141044041_Burak_Kagan_Korkmaz_part2.c contains twelve helper */ 
/*    functions and main function for the homework IV. This program use  	*/ 
/*	  three parameters to print a ASCII art. First parameter is the number 	*/ 
/*    which user enter from 0 to 99999. Invalid numbers returned 0.  Second */
/*    parameter borderWidth getsborder thickness and last one shows that    */
/*    the character used while printing (In printNumber function). Also,    */
/*    this program has a helper function one by one for each number and     */
/*    Inputs are still received by a function.                              */ 
/*                                                                          */ 
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/ 
/*								Includes									*/
/*--------------------------------------------------------------------------*/

#include <stdio.h>

/*--------------------------------------------------------------------------*/ 
/*							Function Prototypes								*/
/*--------------------------------------------------------------------------*/
void getInputs(int* num, int* borderWidth, char* borderChar);
int printNumber(int num, int borderWidth, char borderChar);
/* Printing Numbers with helper functions */
void number1(int line, char borderChar);
void number2(int line, char borderChar);
void number3(int line, char borderChar);
void number4(int line, char borderChar);
void number5(int line, char borderChar);
void number6(int line, char borderChar);
void number7(int line, char borderChar);
void number8(int line, char borderChar);
void number9(int line, char borderChar);
void number0(int line, char borderChar);

int main(){

    int num, borderWidth;
    char borderChar;


    getInputs(&num, &borderWidth, &borderChar);
    printNumber(num, borderWidth, borderChar);

return 0;
}

/* User enter inputs here  */
void getInputs(int* num, int* borderWidth, char* borderChar){

  
    
        scanf("%d", num);
        scanf("%d", borderWidth);
        scanf(" %c", borderChar);
    
    
}
/* All work is done by this function. Seperation of Digit, Printing border 
    and printing right number. While printing numbers, printNumber calls some 
    helper functions */
int printNumber(int num, int borderWidth, char borderChar){
    
    int number;
    int counter;
    int i,j,k;
    int digit;
    int array[5];  /*  The number must be 5-digits */
    int line;
    int borderEdge; /* The lenght of border in one line */
        
    /* Checking Invalid Numbers */
    if(num < 0 || num > 99999)
    {
        return 0;
    }    
        
    number = num;  
    counter = 0;    /* Number of Digits */
    i=0;  
    while (number != 0){
        digit = number % 10 ;
        array[i] = digit;   /* Saving digits of the number to array */
        number /= 10 ; 
        ++i;  
        ++counter;
        
    }
    
    for(j = 0; j < borderWidth; ++j){
        k=1;
        borderEdge = (counter * 7) + (2 * borderWidth);
        while(k <= borderEdge){
            printf("%c", borderChar);
            ++k;
        }
        printf("\n");
    }
    
    
    for(line = 1; line <= 7; ++line){
        
        k=1;
        while(k <= borderWidth){
            printf("%c", borderChar);
            ++k;
        }
       
        for(i = 0; i < counter; ++i){
            digit = array[counter - i -1];
            switch(digit){
                case 0 : number0(line, borderChar); break;
                case 1 : number1(line, borderChar); break;
                case 2 : number2(line, borderChar); break;
                case 3 : number3(line, borderChar); break;
                case 4 : number4(line, borderChar); break;
                case 5 : number5(line, borderChar); break;
                case 6 : number6(line, borderChar); break;
                case 7 : number7(line, borderChar); break;
                case 8 : number8(line, borderChar); break;
                case 9 : number9(line, borderChar); break;
            }
        }

        k=1;
        
        while(k <= borderWidth){
            printf("%c", borderChar);
            ++k;
        }
        printf("\n");
    }
    
    for(j = 0; j < borderWidth; ++j){
        
        k=1;
        while(k <= borderEdge){
            printf("%c", borderChar);
            ++k;
        }
        printf("\n");
    }

return 1;
}


/*---------------------------------------------------------------------------*/
/*            Helper Functions Which is Identified Each Number              */ 
/*---------------------------------------------------------------------------*/

/*These functions print each line of number seperately */
void number1(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("   %c   ",  borderChar );  break;
        case 3 : printf("  %c%c   ", borderChar ,borderChar );  break;
        case 4 : printf("   %c   ",  borderChar );  break;
        case 5 : printf("   %c   ",  borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number2(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("    %c  ",  borderChar  );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("  %c    ",  borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number3(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("    %c  ",  borderChar  );  break;
        case 4 : printf("   %c%c  ",borderChar,borderChar); break;
        case 5 : printf("    %c  ",  borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number4(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c %c  ", borderChar,borderChar ); break;
        case 3 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("    %c  ",  borderChar );  break;
        case 6 : printf("    %c  ",  borderChar ); break;
        case 7 : printf("       ");  break;
    }

}

void number5(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("  %c    ",  borderChar  );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("    %c  ",  borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number6(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("  %c    ",  borderChar  );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("  %c %c  ",  borderChar,borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number7(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");   break;
        case 2 : printf("  %c%c%c  ", borderChar,borderChar, borderChar);break;
        case 3 : printf("    %c  ",   borderChar );  break;
        case 4 : printf("    %c  ",   borderChar );  break;
        case 5 : printf("    %c  ",   borderChar );  break;
        case 6 : printf("    %c  ",   borderChar );  break;
        case 7 : printf("       ");   break;
    }

}

void number8(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number9(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 4 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 5 : printf("    %c  ",  borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}

void number0(int line, char borderChar){

    switch(line){
        case 1 : printf("       ");  break;
        case 2 : printf("  %c%c%c  ",borderChar,borderChar,borderChar ); break;
        case 3 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 4 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 5 : printf("  %c %c  ", borderChar, borderChar );  break;
        case 6 : printf("  %c%c%c  ",borderChar ,borderChar ,borderChar);break;
        case 7 : printf("       ");  break;
    }

}
/*---------------------------------------------------------------------------*/
/*            End of HW04_141044041_Burak_Kagan_Korkmaz_part2.c              */ 
/*---------------------------------------------------------------------------*/
