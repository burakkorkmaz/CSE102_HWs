/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW02_141044041_Burak_Kagan_Korkmaz_part2.c                               */ 
/*																			*/
/* ------------------------------------------								*/ 
/* Created on 26/02/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW02_141044041_Burak_Kagan_Korkmaz_part2.c contains six helper	*/ 
/*    functions and main function for the second part of the homework 2. 	*/ 
/*	  These six	functions compute area and perimeter of some geometric 		*/ 
/*    shapes likeRectangle, Square and Cirle. At the same time, Edge  		*/
/*    Lenghts or Radius datas will be recieved from user and showed the 	*/
/*	  results in Main function.												*/
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*								Includes									*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/ 
/*								Defines										*/
/*--------------------------------------------------------------------------*/
#define PI 3.14

/*--------------------------------------------------------------------------*/ 
/*							Function Prototypes			                    */
/*--------------------------------------------------------------------------*/

int areaOfRectangle(int width, int height);
int perimeterOfRectangle(int width, int height);

int areaOfSqure(int edgeLength);
int perimeterOfSquare(int edgeLength);

double areaOfCircle(double radius);
double perimeterOfCircle(double radius);

/* Main Function */
int main(){
	
	int width, height;		/* Width and Height of Recgtangle like a and b */
	int edgeLength;		/* An edge lenght of Square as "a" */
	double radius;		/* The half of diameter in Circle */

	/* Asking inputs for Rectangle */
	printf("Please enter the width of the rectangle:");
	scanf("%d",&width);
	
	printf("Please enter the heigth of the rectangle:");
	scanf("%d",&height);

	/* Showing results via function calls for rectangle */
	printf("The area of the rectangle is: %d\n",
				areaOfRectangle(width, height));
		
	printf("The perimeter of the rectangle is: %d\n",
				perimeterOfRectangle(width, height));
	
	/* Asking the input for Square */
	printf("Please enter the width of the square:");
	scanf("%d",&edgeLength);
	
	/* Showing results via function calls for Square */
	printf("The area of the square is: %d\n", areaOfSqure(edgeLength));
	
	printf("The perimeter of the square is: %d\n",
				perimeterOfSquare(edgeLength));
	
	/* Asking the input for Circle */
	printf("Please enter the radius of the circle:");
	scanf("%lf",&radius);
	
	/* Showing results via functions call for Circle */
	printf("The area of the circle is: %.2f\n", areaOfCircle(radius));
	
	printf("The perimeter of the circle is: %.2f\n", 
				perimeterOfCircle(radius));

return (0);
}
/* End of Main Function */



/* This function multiply height by width (a*b) to compute area of Rectangle */
int areaOfRectangle(int width, int height)
{
	
return (width * height);

}

/* This function adds height to width and multiplies by two  [(a+b)*2] to find 
the sum of four edges of rectangle */
int perimeterOfRectangle(int width, int height)
{

	return ((width + height) * 2);

}

/* This function computes edge lenght 
to second power (a^2) for area of Square */
int areaOfSquare(int edgeLength)
{

	return (edgeLength * edgeLength);

}

/* This function multiplies edge lenght by 4 because 
all edge lenghts are equal (a * 4) for perimeter of Square */
int perimeterOfSquare(int edgeLength)
{	

	return (edgeLength * 4);

}

/* This function multiplies pi by radius squared (pi*r^2) for circle's area */
double areaOfCircle(double radius)
{

	return (PI * radius * radius);
}

/* This function multiplies pi by radius 
and by two (2*pi*r) for circle's perimeter */
double perimeterOfCircle(double radius)
{

	return (2 * PI * radius);
}

	
/*---------------------------------------------------------------------------*/
/*             End of HW02_141044041_Burak_Kagan_Korkmaz_part2.c             */ 
/*---------------------------------------------------------------------------*/
