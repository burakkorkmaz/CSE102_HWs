/*
 * 	HW10_141044041_BURAK_KAGAN_KORKMAZ.c
 *
 *	02/05/2016
 *
 */


/* INCLUDES */
#include <stdio.h>
#include <string.h>

/* DEFINES	*/
#define MAX_ENTRY 20
#define MAX_CHAR 30

/* STRUCT DECLARATIONS */
typedef struct
{
	int id[MAX_ENTRY];
	char name[MAX_ENTRY][MAX_CHAR];
	char surname[MAX_ENTRY][MAX_CHAR];
}Student;

typedef struct
{
	char degree[MAX_ENTRY][MAX_CHAR];
	int id[MAX_ENTRY];
	char name[MAX_ENTRY][MAX_CHAR];
	char surname[MAX_ENTRY][MAX_CHAR];
}Lecturer;

typedef struct
{
	int code[MAX_ENTRY];
	char name[MAX_ENTRY][MAX_CHAR];
	int lecturerID[MAX_ENTRY];
}Lecture;

typedef struct
{
	char className[MAX_ENTRY][MAX_CHAR];
	char day[MAX_ENTRY][MAX_CHAR];
	int startTime[MAX_ENTRY];
	int duration[MAX_ENTRY];
	int lectureCode[MAX_ENTRY];
}Schedule;

typedef struct
{
	int studentID[MAX_ENTRY];/*////*/
	int lectureCode[MAX_ENTRY];/*////*/
}TakenCourse;

/*  FUNCTION PROTOTYPES */

/*
 *	given entry are searched in an array. If it found, return its index
 */
int findEntryIndex(int searchIn[], int target, int size);

/*
 *	given entry are searched in an array. If it found how many times,
 *  return it (counter).
 */
int howManyEntry(int searchIn[], int target, int size);

int main(){
	/* File pointers */
	FILE *binptr;
	FILE *txtptr;
	/* Declaration of the Struct variables */
	Student std;
	Lecturer teacher;
	Lecture lesson;
	Schedule plan;
	TakenCourse course;
	
	int i;
	int j;
	int index;	/* for findEntryIndex function */
	int counter; /* for howManyEntry function */
	/* loop condition variables */
	int lcv;	/* Student */
	int lcv2;	/* Lecturer */
	int lcv3;	/* Lecture */
	int lcv4;	/* Schedule */
	int lcv5;	/* TakenCourse */
	
	/*	Open and read the binary file	*/
	binptr = fopen("input.dat", "rb");
	
	if(binptr == NULL)
	{
		printf("The file is NOT EXIST");
	}
	else
	{
			/* Student */
		fread(&lcv, sizeof(int), 1, binptr);
		for(i=0; i < lcv; ++i)
		{
			fread(&std.id[i], sizeof(int), 1, binptr);
			fread(&std.name[i], sizeof(char), MAX_CHAR, binptr);
			fread(&std.surname[i], sizeof(char), MAX_CHAR, binptr);
		}
	
			/* Lecturer */
		fread(&lcv2, sizeof(int), 1, binptr);
		for(i=0; i < lcv2; ++i)
		{
/* NOTE: in binary file, max character limit of degree array has taken 32 */
			fread(&teacher.degree[i], sizeof(char), MAX_CHAR+2, binptr);
			fread(&teacher.id[i], sizeof(int), 1, binptr);
			fread(&teacher.name[i], sizeof(char), MAX_CHAR, binptr);
			fread(&teacher.surname[i], sizeof(char), MAX_CHAR, binptr);
		}
	
			/* Lecture */
		fread(&lcv3, sizeof(int), 1, binptr);
		for(i=0; i < lcv3; ++i)
		{
/* NOTE: in binary file, max character limit of NAME array has taken 32 */
			fread(&lesson.code[i], sizeof(int), 1, binptr);
			fread(&lesson.name[i], sizeof(char), MAX_CHAR+2, binptr);
			fread(&lesson.lecturerID[i], sizeof(int), 1, binptr);
		}
			/* Schedule */
		fread(&lcv4, sizeof(int), 1, binptr);
		for(i=0; i < lcv4; ++i)
		{
			fread(&plan.className[i], sizeof(char), MAX_CHAR, binptr);
			fread(&plan.day[i], sizeof(char), MAX_CHAR, binptr);
			fread(&plan.startTime[i], sizeof(int), 1, binptr);
			fread(&plan.duration[i], sizeof(int), 1, binptr);
			fread(&plan.lectureCode[i], sizeof(int), 1, binptr);
		}
	
			/* taken Courses */
		fread(&lcv5, sizeof(int), 1, binptr);
		for(i=0; i < lcv5; ++i)
		{
			fread(&course.studentID[i], sizeof(int), 1, binptr);
			fread(&course.lectureCode[i], sizeof(int), 1, binptr);
		}
		fclose(binptr);
	
	/* writing to output file from txt */
		txtptr = fopen("output.txt", "w");
	
		fprintf(txtptr, "Lecture-Lecturer\n");
		for(i=0; i < lcv3; ++i)
		{
			/* determine lecturer ID index */
			index = findEntryIndex(&teacher.id[0], lesson.lecturerID[i], lcv2);
			
			/* writing to text file */
			fprintf(txtptr, "%s %s %s %d\n", lesson.name[i], 
				teacher.name[index], teacher.surname[index],
				howManyEntry(&course.lectureCode[0], lesson.code[i], lcv5));
		}
		fprintf(txtptr, "\nStudent-Lecture\n");
		for(i=0; i < lcv; ++i)
		{
			fprintf(txtptr, "%d %s %s %d\n", std.id[i], 
				std.name[i], std.surname[i],
				howManyEntry(course.studentID, std.id[i], lcv5));
		}
		

		
		fprintf(txtptr, "\nStudent-Day\n");
		for(i=0; i < lcv; ++i)
		{
			fprintf(txtptr, "%d %s %s ", std.id[i],std.name[i],std.surname[i]);
			
			/* relation between student and schedule */
			/* finding student id index */
			index = findEntryIndex(&course.studentID[0], std.id[i], lcv5);
			
			/* determine how many course has taken by a student*/
			counter = howManyEntry(&course.studentID[0], std.id[i], lcv5);
			
			for(j=index; j < lcv5; ++j)	/* writing course days to file */
			{
				/* print course day with comma */
				if(course.studentID[j]==std.id[i])	
				{
					
					index = findEntryIndex(&plan.lectureCode[0], 
						course.lectureCode[j], lcv3);
					
					fprintf(txtptr, "%s", plan.day[index]);
				
					if(counter > 1)
					{
						fprintf(txtptr, ", ");
						--counter;
					}
				}	
			}
			fprintf(txtptr, "\n");
		}
		fclose(txtptr);
		
	}
	return 0;
}
/*  HELPER FUNCTIONS */
int findEntryIndex(int searchIn[], int target, int size){
	int i;
	
	for(i = 0;  i < size; ++i)
	{
		
		if(searchIn[i] == target)
		{	
			return i;
		}
	}
	printf("ERROR: The Entry NOT FOUND\n");
	return -1;
}

int howManyEntry(int searchIn[], int target, int size){
	int i;
	int number = 0;
	
	for(i = 0;  i < size; ++i)
	{
		
		if(searchIn[i] == target)
		{
			number++;
		}
	}


	return number;
}

/*	End of HW10_141044041_BURAK_KAGAN_KORKMAZ.c	file */
