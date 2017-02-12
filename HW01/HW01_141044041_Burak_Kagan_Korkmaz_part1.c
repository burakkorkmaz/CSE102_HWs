/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW01_141044041_Burak_Kagan_Korkmaz_part1.c                               */ 
/*																			*/ 																
/* ------------------------------------------								*/ 
/* Created on 19/02/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW01_141044041_Burak_Kagan_Korkmaz_part1.c contains a function	*/ 
/*    for the first part of the homework 1, which is used for calculating   */ 
/*	  final grade of student by using homework and exam grade with weights.	*/ 
/*               			                                                */ 
/*              															*/ 
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*                           	 Includes                                   */
/*--------------------------------------------------------------------------*/ 
#include <stdio.h>

/*---------------------------------------------------------------------------*/
/*                       		Main Function                  				 */ 
/*---------------------------------------------------------------------------*/
int main()
{

	double midtermWeight1		; /*----------------------------------------*/
	double midtermWeight2		; /*									  	*/
	double midtermWeight3		; /*	All exams and homework weights	 	*/
	double homeworkWeight1		; /*		are entered by user.		 	*/
	double homeworkWeight2		; /*										*/
	double finalExamWeight		; /*----------------------------------------*/

	double midtermGrade1		; /*----------------------------------------*/
	double midtermGrade2		; /*									 	*/
	double midtermGrade3		; /*	All exams and homework grades	 	*/
	double homeworkGrade1		; /*	  are also entered by user.		 	*/
	double homeworkGrade2		; /*										*/
	double finalExamGrade		; /*----------------------------------------*/
	
	double finalGrade		; /* As a result of entered inputs it calculates */

	double midEffect1		;	/*-------------------------------------------*/
	double midEffect2		;	/*									 		 */
	double midEffect3		;	/*	  Each grade's effect is calculate.		 */
	double hwEffect1		;	/*								 		 	 */
	double hwEffect2		;	/*-------------------------------------------*/
	double finalExamEffect	;	/*		To save on column limit(80),  	 	 */
	double totalMidEffect	;	/* 		some variables are assemled.		 */
	double totalHwEffect 	;	/*-------------------------------------------*/

	/* Midterm, Homework and final exam grade weights*/

	printf ("Please enter the 1. midterm weight: ")		;
	scanf ("%lf", &midtermWeight1);

	printf ("Please enter the 2. midterm weight: ")	;
	scanf ("%lf", &midtermWeight2);

	printf ("Please enter the 3. midterm weight: ")	;
	scanf ("%lf", &midtermWeight3);

	printf ("Please enter the 1. homework weight: ")	;
	scanf ("%lf", &homeworkWeight1);

	printf ("Please enter the 2. homework weight: ")	;
	scanf ("%lf", &homeworkWeight2);

	printf ("Please enter the final exam weight: ")	;
	scanf ("%lf", &finalExamWeight);

	/* Midterm, Homework and final exam grades */

	printf ("Please enter the 1. midterm grade: ")	;
	scanf ("%lf", &midtermGrade1);

	printf ("Please enter the 1. midterm grade: ")	;
	scanf ("%lf", &midtermGrade2);

	printf ("Please enter the 1. midterm grade: ")	;
	scanf ("%lf", &midtermGrade3);

	printf ("Please enter the 1. homework grade: ")	;
	scanf ("%lf", &homeworkGrade1);

	printf ("Please enter the 2. homework grade: ")	;
	scanf ("%lf", &homeworkGrade2);

	printf ("Please enter the final exam grade: ")	;
	scanf ("%lf", &finalExamGrade);

	/* Calculation of Grade Perception*/ 
	midEffect1 = (midtermWeight1 * midtermGrade1 / 100);
	midEffect2 = (midtermWeight2 * midtermGrade2 / 100);
	midEffect3 = (midtermWeight3 * midtermGrade3 / 100);

	totalMidEffect = midEffect1 + midEffect2 + midEffect3;

hwEffect1 = (homeworkWeight1 * homeworkGrade1 / 100);
	hwEffect2 = (homeworkWeight2 * homeworkGrade2 / 100);

	totalHwEffect = hwEffect1 + hwEffect2;

	finalExamEffect = (finalExamWeight * finalExamGrade / 100) ;

	finalGrade =  totalMidEffect + totalHwEffect + finalExamEffect;


	printf("Your final grade is: %.2f", finalGrade)		;
	

	return 0;

}
/*---------------------------------------------------------------------------*/
/*             End of HW01_141044041_Burak_Kagan_Korkmaz_part1.c             */ 
/*---------------------------------------------------------------------------*/
