/* *********************************************/
/*	Burak Kagan Korkmaz - 141044041 - HW11	   */
/*		12/05/2016							   */
/***********************************************/

/******INCLUDES*****/
#include <stdio.h>

/*****DEFINES*******/
#define MAX_DATA 10
#define MAX_STRUCT 1000
	/* type codes */
#define CHAR 1
#define INT 2
#define LONG 3
#define FLOAT 4
#define DOUBLE 5

/*******FUNCTION PROTOTYPES*******/

/*
 *	this function read from binary file a secret data in a struct if its type
 *  is found, type code (e.g. char --> 1) is written to array.
 * 		if the file not exist, RETURN -1;
 * 		otherwise RETURN 0; 
 */
int hwDecode(const char filename[], int arr_out[] );

/* helper sturct to find secret data types */
typedef struct{
	unsigned char v1;
	int v2;
	long long int v3;
	float v4;
	double v5;
}TestData;

int main(){
	int arr[MAX_DATA];
	int i;
	hwDecode("test.bin", arr );
	
	for(i=0; i<10; ++i)
	{
		printf(">%d<\n", arr[i]); 
	}
	return 0;
}

int hwDecode(const char filename[], int arr_out[] ){
	
	FILE *bp;
	int i;
	int fileSize;
	int structSize;
	TestData test;
	int bytes;
	int counter;
	
	
	
	/* setting array elements by -1 for the beginning  */
	for(i=0; i < MAX_DATA; ++i)
	{
		arr_out[i] = -1;
	}
	
	bp = fopen(filename, "rb");
	/*  if file not exist return -1 */
	if(bp == NULL)
	{
		return -1;
	}
	
	
	fseek(bp,0, SEEK_END);
	fileSize = ftell(bp);
	structSize = fileSize / MAX_STRUCT;
	printf("%d\n", structSize);
	rewind(bp);
	
	counter = 0;
	bytes = 0;
				 /* structSize - avg size(double) */
	while(bytes < (structSize - sizeof(double)) && counter < MAX_DATA)
	{ 
		/* assume double first element*/
		fread(&test.v5, sizeof(double), 1, bp);
		if(test.v5 != 0.0)	/* FOUND */
		{
			arr_out[counter] = DOUBLE;
			bytes += sizeof(double);
		}
		else	/* NOT FOUND */
		{
			/* return previous location with fseek */
			fseek(bp, -1 * sizeof(double), SEEK_CUR);
			/* assume long long int the element */
			fread(&test.v3, sizeof(long long int), 1, bp);
			if(test.v3 != 0)	/* FOUND */
			{
				arr_out[counter] = LONG;
				bytes += sizeof(long long int);
			}
			else	/* NOT FOUND */
			{
				/* return previous location with fseek */
				fseek(bp, -1 * sizeof(long long int), SEEK_CUR);
				/* assume float the element */
				fread(&test.v4, sizeof(float), 1, bp);
				if(test.v4 != 0.0)	/* FOUND */
				{
					arr_out[counter] = FLOAT;
					bytes += sizeof(float);
				}
				else	/* NOT FOUND */
				{
					/* return previous location with fseek */
					fseek(bp, -1 * sizeof(float), SEEK_CUR);
					/* assume int the element */
					fread(&test.v2, sizeof(int), 1, bp);
					if(test.v2 != 0)	/* FOUND */
					{
						arr_out[counter] = INT;
						bytes += sizeof(int);
					}
					else
					{
						/* return previous location with fseek */
						fseek(bp, -1 * sizeof(float), SEEK_CUR);
						/* if this element is not int,it has to be only Char */
						fread(&test.v1, sizeof(char), 1, bp);
						arr_out[counter] = CHAR;
						bytes += sizeof(char);
					}
				}
			}
		}
		/*next element*/	
		counter++;	
	}		
	
	
	fclose(bp);
	
	return 0;

}

/* END OF HW11_141044041_BURAK_KAGAN_KORKMAZ.c FILE */
