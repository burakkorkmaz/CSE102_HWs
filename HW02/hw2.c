/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW02_141044041_Burak_Kagan_Korkmaz_part1.c                               */ 
/*																			*/
/* ------------------------------------------								*/ 
/* Created on 26/02/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW02_141044041_Burak_Kagan_Korkmaz_part1.c contains an helper 	*/ 
/*    function and main function for the first part of the homework 2. 		*/ 
/*	  Main function does only calling function and helper function 			*/ 
/*    calculate student final grade by using weight and grade inputs.		*/
/*    																		*/
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*								Includes									*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/ 
/*							Function Prototypes			                    */
/*--------------------------------------------------------------------------*/
void calculateLastGrade();

/* Beginning of the Main fuction */
int main(){
	
	calculateLastGrade();		/*-----------------------------------------*/
								/*		For three different	students, 	   */
	calculateLastGrade();		/*		Function calls	3 times to  	   */
								/*		compute subject final grade.	   */
	calculateLastGrade();		/*-----------------------------------------*/


return 0;
}
/* End of Main function */



/* This helper function gets homework, exam weights and grades from user. Then, it computes student's final grade */
void calculateLastGrade(){

/* Declaration of Variables in function */
double midtermWeight, homeworkWeight, finalExamWeight;

double midtermGrade, homeworkGrade, finalExamGrade;

double midtermEffect, homeworkEffect, finalExamEffect;

double finalGrade;

/* Getting midterm, homework and final exam weight */
	printf ("Please enter the 1. midterm weight:")		;
	scanf ("%lf", &midtermWeight);

	printf ("Please enter the 1. homework weight:")		;
	scanf ("%lf", &homeworkWeight);

	printf ("Please enter the final exam weight:")		;
	scanf ("%lf", &finalExamWeight);


/* Getting midterm, homework and final exam grade */
	printf ("Please enter the 1. midterm grade:")		;
	scanf ("%lf", &midtermGrade);

	printf ("Please enter the 1. homework grade:")		;
	scanf ("%lf", &homeworkGrade);

	printf ("Please enter the final exam grade:")		;
	scanf ("%lf", &finalExamGrade);


	/* Computing grade effects; weights multiplies by grades 
		and divide by 100 for grade perception effect 	*/
	midtermEffect = (midtermWeight * midtermGrade / 100);

	homeworkEffect = (homeworkWeight * homeworkGrade / 100);

	finalExamEffect = (finalExamWeight * finalExamGrade / 100) ;

/* To calculate Student final grade, all grade perception effects are */
	finalGrade =  midtermEffect + homeworkEffect + finalExamEffect;

	printf("Your final grade is: %f\n", finalGrade)		;

}
/*---------------------------------------------------------------------------*/
/*             End of HW02_141044041_Burak_Kagan_Korkmaz_part1.c             */ 
/*---------------------------------------------------------------------------*/
