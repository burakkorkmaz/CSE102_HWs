/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW01_141044041_Burak_Kagan_Korkmaz_part2.c                               */ 
/*																			*/
/* ------------------------------------------								*/ 
/* Created on 20/02/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW01_141044041_Burak_Kagan_Korkmaz_part2.c contains a function	*/ 
/*    for the second part of the homework 1, which asks current date and  	*/ 
/*	  user's birthday to say that user lived how many days. Also, this 		*/ 
/*    function say that you were how old in another planet which time		*/
/*    periods are different like hour, day, months and year.				*/
/*--------------------------------------------------------------------------*/ 

/*--------------------------------------------------------------------------*/ 
/*                           	 Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/* Main Function */
int main(){
	int currentYear		; 	/*----------------------------------------------*/
	int currentMonth	; 	/*									 	        */
	int currentDay		;	/*		  This variables are needed for	        */
							/*		 	current date and birth date	        */
	int birthYear		; 	/*					inputs.				        */
	int birthMonth		; 	/*									 	        */
	int birthDay		;	/*----------------------------------------------*/

	int totalCurrentDays; 	/*----------------------------------------------*/
	int totalBirthDays	;	/*		  "Total" variables are to compute 		*/
	int yourLivedDays	;	/*		  that user lived how many days.	    */
							/*----------------------------------------------*/
	int planetHour		; 	/*		  		Getting time periods		    */
	int planetDay		;	/*		  		 of another planet	        	*/
	int planetMonth		;	/*----------------------------------------------*/

	int yourLivedHours		; 	/*------------------------------------------*/
	int planetLivedDays		; 	/*		  Computing how much time 			*/
	int planetLivedMonths	; 	/*		user lives in another planet		*/
	int planetLivedYears	; 	/*------------------------------------------*/

							/*----------------------------------------------*/
	int remainDays		; 	/*	Remainders during lived time computing	    */
	int remainMonths	;	/*----------------------------------------------*/

	/* Current date and Birthdate inputs */
	printf("Please enter the current date.\nYear: ");
	scanf("%d", &currentYear);
	
	printf("Month: ");
	scanf("%d", &currentMonth);

	printf("Day:");
	scanf("%d", &currentDay);

	printf("Please enter your birthdate.\nYear: ");
	scanf("%d", &birthYear);
	
	printf("Month:");
	scanf("%d", &birthMonth);

	printf("Day: ");
	scanf("%d", &birthDay);

	/*	This operations calculate total days for current and birth date     */
	totalCurrentDays = currentYear * 365 + currentMonth * 30 + currentDay;
	totalBirthDays = birthYear * 365 + birthMonth * 30 + birthDay;

	/* To compute user's lived days, birth days substract from current days */
	yourLivedDays = totalCurrentDays - totalBirthDays;
	printf("You have lived %d days.", yourLivedDays);
	
	/*	In another planet, time periods inputs	*/
	printf("\nPlease enter about the time of another planet: ");
	printf("\nHow many hour is a day? ");
	scanf("%d", &planetHour);

	printf("How many days is a month? ");
	scanf("%d", &planetDay);

	printf("How many months is a year? ");
	scanf("%d", &planetMonth);


	/*	Lived days in Earth convert to hours to 	*/
	/*   compute user's age in another planet.	    */
	yourLivedHours = yourLivedDays * 24 ;

	/*	To find age on the planet, lived hours divide by other time periods. */
	/*  Then, remainders are computed to get age of user for months or days. */
	planetLivedDays = yourLivedHours / planetHour;	

	planetLivedMonths = planetLivedDays / planetDay;
	remainDays = planetLivedDays % planetDay;

	planetLivedYears = planetLivedMonths / planetMonth;
	remainMonths = planetLivedMonths % planetMonth;

	/*	Representation about age of user and time in another planet */
	printf("If you lived in a planet where a day is ");
	printf("%d hours, a month %d days", planetHour, planetDay);
 	printf("and a year is %d months: you were ", planetMonth);
	printf("%d years, %d months and ", planetLivedYears, remainMonths);
	printf("%d days old.\n", remainDays);
	
	return 0;
}
/*---------------------------------------------------------------------------*/
/*             End of HW01_141044041_Burak_Kagan_Korkmaz_part2.c             */ 
/*---------------------------------------------------------------------------*/
