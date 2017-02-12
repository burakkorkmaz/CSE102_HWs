/*
 *	Burak Kagan Korkmaz	- 	141044041
 *	 HW09.c	
 *	26/04/2016
 */

/*
 *	INCLUDES
 */
#include <stdio.h>
#include <string.h>
/*
 *	DEFINES
 */
#define MAX_COUNRTY 100
#define MAX_CHARACTER 25
#define MAX_NEIGHBOUR 10
#define TRUE 1
#define FALSE 0

/*
 *	Countries Struct  Type
 */
typedef struct{
	char name[MAX_CHARACTER];
	int population;
	int area;
	int army;
	char neighbour[MAX_NEIGHBOUR][MAX_CHARACTER];
	int numberOfNei;
}Country;


/*
 *	Add a  new country to struct 
 */
void addCountry(Country *newCountry);

/*
 *	find army of given country and compare with that neigbours and 
 * neigbours of neighbours. Finally print most powerful country among these.
 */
void mostPowerful(Country countries[], int numberOfCountries);

/*
 *	find area of given country and compare with that neigbours and 
 * neigbours of neighbours. Finally print the largest country among these.
 */
void largestCountry(Country countries[], int numberOfCountries);

/*
 *	compute number of people between two countriies and print it or 
 *	if it is not accesible , print inaccessible
 */
void howManyPeople(Country countries[], int numberOfCountries);

/*
 *	find index of the given country name in struct
 * if it is not exist , return -1.
 */
int findCountry(Country countries[], char neighbour[], int numberOfCountries);


int main(){
	int i;
	char choice;
	int counter=0;
	int exit = FALSE;
	Country new[MAX_COUNRTY];
	
	
	
	/* Initilize */
	for(i=0; i < MAX_COUNRTY; ++i)
	{
		new[i].name[0] = '\0';
		new[i].population = 0;
		new[i].area = 0;
		new[i].neighbour[0][0] = '\0';
		new[i].numberOfNei = 0;
	}
	
	do
	{
		printf("Make your choice:\n");
		scanf(" %c", &choice);
		
		switch(choice)
		{
			case 'a': 	
						addCountry(&new[counter]);
						++counter;
						break;
			case 'b':	mostPowerful(new,counter+1);
						break;
			case 'c':	largestCountry(new,counter+1);
						break;
			case 'd':	howManyPeople(new, counter+1);
						break;
			case 'e':	exit = TRUE;
						break;
			default: 	printf("Invalid choice, press 'e' for exit\n");
		}	
	}		
	while(counter < MAX_COUNRTY && !(exit));
/*
		for(i=0; i < MAX_NEIGHBOUR; ++i)
	{
	printf(">>%s",new[0].neighbour[i]);
}*/
	return 0;
}


void addCountry(Country *newCountry){
	int first = 0;
	char temp[MAX_CHARACTER];
	int i=0;
	
	scanf(" %s", newCountry->name);
	scanf(" %d", &(newCountry->population));		
	scanf(" %d", &(newCountry->area));	
	scanf(" %d", &(newCountry->army));
	
	do
	{
		scanf(" %s",&temp[first]);
		if(strcmp(temp,"-1")!=0)
		{
			strcpy(newCountry->neighbour[i], temp );
			++i;
		}
	}	
	while((strncmp(temp,"-1",2)!=0));
	
	newCountry->numberOfNei = i+1;
}


void mostPowerful(Country countries[], int numberOfCountries){
	int i,j,k;
	int index, index1;
	int found = 0;
	char input[MAX_CHARACTER];
	int powerful;
	int neighbour;
	int neighbour1;
	int soldier=0;
	int soldier1=0;
	
	scanf(" %s",input);
	
	i=0;
	while(i < numberOfCountries && !(found)) /* search given country */
	{
		if(strcmp(countries[i].name, input) == 0)	
		{
			found = 1;
			i++;
			printf("i : %d\n", i);
			
		}
	}	
	--i;
	powerful = i;
	
	if(!(found))
	{
		printf("<output> Country not found\n");
	}
	else
	{
		
		for(j=0; j < countries[i].numberOfNei; ++j)	/* find powerful Nei. */
		{
			index = findCountry(&countries[i], countries[i].neighbour[j],
					numberOfCountries);
			printf("j: %d\n", j);
			printf("index: %d\n", index);
			if(index != -1)
			{
				if(countries[index].army > soldier)
				{
					soldier = countries[index].army;
					neighbour = index;
				}
			}
			for(k=0; k < countries[index].numberOfNei; ++k)
			{
			printf("k: %d\n", k);
				index1 = findCountry(&countries[index], 
							countries[index].neighbour[k], numberOfCountries);
				printf("index1: %d\n", index1);
				if(index1 != -1)
				{
					if(countries[index1].army > soldier1)
					{
						soldier1 = countries[index1].army;
						neighbour1 = index1;
					}
				}
			}
		}
		
		if(soldier > soldier1)
		{
			powerful = neighbour;
		}
		else
		{
			powerful = neighbour1;
		}
		printf(">>%d\n", countries[i].army);
		if(countries[i].army > countries[powerful].army)
		{
			powerful = i;
		}
	
		printf("<output> %s\n", countries[powerful].name);
	
		
	}
		
	
}
	
void largestCountry(Country countries[], int numberOfCountries){
	
	int i,j,k;
	int index, index1;
	int found = 0;
	char input[MAX_CHARACTER];
	int largest;
	int neighbour;
	int neighbour1;
	int area=0;
	int area1=0;
	
	scanf(" %s",input);
	
	i=0;
	while(i < numberOfCountries && !(found)) /* search given country */
	{
		if(strcmp(countries[i].name, input) == 0)	
		{
			found = 1;
			i++;
			printf("i : %d\n", i);
			
		}
	}	
	--i;
	largest = i;
	
	if(!(found))
	{
		printf("<output> Country not found\n");
	}
	else
	{
		
		for(j=0; j < countries[i].numberOfNei; ++j)	/* find largest Nei. */
		{
			index = findCountry(&countries[i], countries[i].neighbour[j],
					numberOfCountries);
			printf("j: %d\n", j);
			printf("index: %d\n", index);
			if(index != -1)
			{
				if(countries[index].area > area)
				{
					area = countries[index].area;
					neighbour = index;
				}
			}
			for(k=0; k < countries[index].numberOfNei; ++k)
			{
			printf("k: %d\n", k);
				index1 = findCountry(&countries[index], 
							countries[index].neighbour[k], numberOfCountries);
				printf("index1: %d\n", index1);
				if(index1 != -1)
				{
					if(countries[index1].area > area1)
					{
						area1 = countries[index1].area;
						neighbour1 = index1;
					}
				}
			}
		}
		
		if(area > area1)
		{
			largest = neighbour;
		}
		else
		{
			largest = neighbour1;
		}
		printf(">>%d\n", countries[i].area);
		if(countries[i].area > countries[largest].area)
		{
			largest = i;
		}
	
		printf("<output> %s\n", countries[largest].name);
	
		
	}
		
	
}
	
void howManyPeople(Country countries[], int numberOfCountries){
	char location[MAX_CHARACTER];
	char destination[MAX_CHARACTER];
	scanf("%s %s", location,destination);
	
	printf("<output> INACCESSIBLE\n");
}
	
	
int findCountry(Country countries[], char neighbour[], int numberOfCountries){
	
	int i=0;
	int found = 0;
	for(i=0; i < numberOfCountries && !(found); ++i)
	{
		if(strcmp(countries[i].name, neighbour)==0)
		{	
			found = 1;
			return i;
		}
		
	}
	return i;
}




