/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW04_141044041_Burak_Kagan_Korkmaz_part1.c                               */ 
/*																			*/
/* -------------------------------------------								*/ 
/* Created on 21/03/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW03_141044041_Burak_Kagan_Korkmaz_part1.c contains three helper 	*/ 
/*    function and main function for the homework 4. This program compute  	*/ 
/*	  varieties of sine and cosine as long as user enter a degree and n,  	*/ 
/*    which is first n term of the serie. When user enter 'E' or 'e',       */
/*    the program will be shut down. All of these proceses are done by the  */
/*    helper functions. Main function only calls helper functions.          */
/*                                                                          */
/*                                                                          */
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*								Includes									*/
/*--------------------------------------------------------------------------*/

#include <stdio.h>

/*--------------------------------------------------------------------------*/ 
/*								Defines								    	*/
/*--------------------------------------------------------------------------*/
#define pi 3.14
#define FALSE 0 

/*--------------------------------------------------------------------------*/ 
/*							Function Prototypes								*/
/*--------------------------------------------------------------------------*/
void getInputs(int* degree, int* n, int* exit);
double cosine(int degree, int n);
double sine(int degree, int n);


int main(){ 


    int degree;
    int n;
    int exit;
   
  
    do{
        getInputs(&degree, &n, &exit);
        
        if(exit != 1){
            sine(degree, n);
            cosine(degree, n);
        }
    }while(exit == 0);
return 0;
}


/* GetInputs function get degree and n via pointers from user. If user enter 
   'e' or 'E' character, the function assign 1 to exit variable and quit form
   the program   */
void getInputs(int* degree, int* n, int* exit){

    char input;
 
    *exit = 0;
    
    if(scanf("%d", degree) == FALSE){   /* Checking whether input is integer*/
        scanf("%c", &input); 
        if(input == 'e' || input =='E')
            *exit = 1;
    }
    
    else
        scanf("%d", n);
        
}


/* This function first convert the degree to radian (=x) and then computes sign
    and factorial, 2nth power of x by using n times sum of 
    [(-1)^n * x^2n / (2n)!]. Finally, find the value of cosine  */
double cosine(int degree, int n){
   
    double radian; 
    double sign;        /* (-1)^n */
    double factorial;   /* (2n)!  */
    double exponent;    /* x^(2n) */
    double term;    /* nth term of the series */
    double result = 0;
    
    /* Loop Condition Variables */
    int i;
    int j;
    int k; 
    int l;  
    
    
    degree %= 360;  /* Angle must not pass 360 degree */
    
    radian = degree * pi / 180;
    
    m=0;    /* Each term number. From the '0' to 'n' */  
    while (m <= n){
    
        sign = 1;   /* reseting sign value */
        for ( i=0; i<m; ++i) {      
            sign *= -1;
        }
        
        factorial = 1;
        for(j=1; j <= (2*m); ++j){  
            factorial *= j;
        }
        
        exponent = 1;
        for(k=1; k <= (2*m); ++k){      
            exponent *= radian;
        }
        
        term = sign * exponent / factorial;     /* the formule */
        
        result += term;     /* Like the serie, all terms are added */ 
        
        ++m;
    }    
    
    printf("cos(%d) where n is %d = %.4f\n", degree, n, result);
    
return result;
}

/* Similarly to Cosine function, this function first convert the degree to 
    radian (=x) and then computes sign and factorial, (2n+1)th power of x by 
    using n times   sum of [(-1)^n * x^2n+1 / (2n+1)!]. Finally, find the 
    value of sine  */
double sine(int degree, int n){
    double radian; 
    double sign;        /* (-1)^n */
    double factorial;   /* (2n+1)!  */
    double exponent;    /* x^(2n) */
    double term;
    double result = 0;
    
    /* Loop Condition Variables */
    int i;
    int j;
    int k;
    int m;
    
    
    degree %= 360;      /* Angle must not pass 360 degree */
    
    radian = degree * pi / 180;
    
    m=0;
    while (m <= n){
        
        sign = 1; /* reseting sign value */
        for ( i=0; i<m; ++i) {
            sign *= -1;
            
        }
            
        factorial = 1;
        for(j=1; j <= (2*m)+1; ++j){
            factorial *= j;
        }
        
        exponent = 1;
        for(k=1; k <= (2*m)+1; ++k){
            exponent *= radian;
        }
        
            
        term = sign * exponent / factorial;
             
        result += term;
            
        ++m; /* increasing term number */
    }    
    
    printf("sin(%d) where n is %d = %.4f\n", degree, n, result);

return result;    
}


/*---------------------------------------------------------------------------*/
/*            End of HW04_141044041_Burak_Kagan_Korkmaz_part1.c              */ 
/*---------------------------------------------------------------------------*/
