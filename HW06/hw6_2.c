/*--------------------------------------------------------------------------*/ 
/*                                                                          */ 
/* HW06_141044041_Burak_Kagan_Korkmaz_part2.c                               */ 
/*																			*/ 																
/* ------------------------------------------								*/ 
/* Created on 07/04/2016 by Burak_Kagan_Korkmaz								*/ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------																*/ 
/*    The HW06_141044041_Burak_Kagan_Korkmaz_part2.c contains a helper		*/ 
/*    function for the second part of the homework 6.			   			*/ 
/*	  																		*/ 
/*               			                                                */ 
/*              															*/ 
/*--------------------------------------------------------------------------*/ 
#include <stdio.h>
#include <string.h>
/*--------------------------------------------------------------------------*/ 
/*                          Helper Function                                 */
/*--------------------------------------------------------------------------*/
/* This function find 1st 2nd 3rd ... letter of searching word in sentece or 
 * character string and return string from first letter of found word.
 *  if found RETURN adress of first index of the word in string. return 
 *  if not found or not provide conditions --> return NULL
 */
char* matcher(char* haystack, char* needle);

int main(){
	
	
	char *ptr = matcher("lorem ipsum dolor sit amet.", "lorem");
	
	printf("%d %d %d\n%p %p %p\n", *(ptr), *(ptr+1), *(ptr+2),
	ptr, ptr+1,ptr+2);

	return 0;
}

char *matcher(char* haystack, char* needle){
	/* variable declarations*/
	int i;
	int j;
	int copy;
	int found = 0;
	int count;
	
	if(strlen(haystack) < strlen(needle) &&  strlen(needle) > 0 )
	{
		return 0;
	}
	
	for (i = 0;
	 	!(found) && haystack[i] != '\0' ;
	 	++i)
	{
		if(haystack[i] == needle[0] )
		{
			copy = i; /* back up index in loop */
		
			for(j = 0, count = 0;
				j < strlen(needle) +1;
				j += 2, copy += 2)
			{
				if(needle[j] == haystack[copy])
				{
					
					count++;
				}
				/* Number of matched letters is half of string lenght */
				if((count == (strlen(needle) + 1) / 2 ))
				{
						
					found = 1;
				}
			}
		}
	}
	
	if(found)
	{
				
		return (&haystack[i-1]); 
	}
 	
 	return NULL;
}
/*---------------------------------------------------------------------------*/
/*             End of HW06_141044041_Burak_Kagan_Korkmaz_part2.c             */ 
/*---------------------------------------------------------------------------*/
