#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 5
#define MAX_PLAYER 6
typedef struct player_scores{
	char * name;
	double * scores;
	int size;
	double average;
} PlayerScores;

typedef struct Node{
	char *name;
	int avg;
	struct Node *next;
}LinkedList;

int countScores(char str[], int size);
int addList(LinkedList *head, char *name, double data);

int main(){
	
	FILE *fp;
	PlayerScores player[MAX_PLAYER];
	int ch = 0;
	int countCh = 0;
	char score[MAX_CHAR];
	char *str;
	char *ptr;
	double total;
	/* Loop Condition Values */
	int i;
	int j;
	int k;
	int end = 0;
	
	
	fp = fopen("i2.txt", "r");
	
	if(fp == NULL)	/* check existance of file */
	{
		printf("File not exist.\n");
		return (-1);
	}
	
	for(k=0;!(end); ++k)
	{
	
	printf("<<<<<<<<<< %d >>>>>>>>>\n", k);
		countCh=0;
		/* count number of characters in that line */
		while((ch != (int)'\n') && !(end))
		{
			ch = fgetc(fp);
			printf("%c", (char)ch);
			++countCh;
			if(ch == EOF)
			{
			perror("end");
				end = 1;
			}
		}
		
	printf("line> %d\n", countCh);
		if(!end)
		{
	
			/* go to the headline */
			fseek(fp, (-1) * countCh, SEEK_CUR);
		perror("fff");
			/* create an dynamic array to write characters in a line */
			str = (char*)calloc(countCh, sizeof(char));
			fgets(str, countCh, fp);
		
		if(ch == (int)'\n')
		{
			if((ch = fgetc(fp) != '\n'))
				fseek(fp,-1,SEEK_CUR);
		}
		perror("fff2");
			/* determine number of scores in a line and allocate it at struct */
			player[k].size = countScores(str, countCh);
			player[k].scores = (double*)calloc(player[k].size, sizeof(double));
		perror("fff3");	
			player[k].name = (char*)malloc(sizeof(char) * 10);
			strcpy(player[k].name, strtok(str, " "));
		perror("fff4");
			i = 0;
			do
			{
				ptr = strtok(NULL, " ");
					perror("kls");
				strcpy(score, ptr);
				player[k].scores[i] = atof(score);
				++i;
			}
			while(i < player[k].size);
		perror("kls2");	

		
			for(j = 0, total = 0; j < player[k].size; ++j)
			{
				total += player[k].scores[j];
			}
	
			player[k].average = total / (double)player[k].size;
	
			free(str);
		/*###print###*/
			printf("name: %s\n", player[k].name);
			printf("size: %d\nscores:", player[k].size);
	
			for(i=0; i < player[k].size; ++i)
			{
				printf(" %.2f", player[k].scores[i]);
			}
			printf("\navg: %f\n", player[k].average);
		
			/*addList(&player[k], player[k].name, player[k].average);
		*/
			free(player[k].scores);
			free(player[k].name);
		}
	}	
	fclose(fp);	
	return 0;
}


int countScores(char str[], int size){
	int i;
	int counter = 0;
	
	for(i = 0; i < size; ++i)
	{
		if(str[i] == '.')
		{
			counter++;
		}
	
	}
	
	return counter;
}

int addList(LinkedList *head, char *name, double data){
	LinkedList *temp;
	
	if(head == NULL){
		head = (LinkedList*)malloc(sizeof(LinkedList));
		strcpy(head -> name, name);
		head -> avg = data;
		head -> next = NULL;
		return 0;
	}
	
	temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	
	temp -> next = (LinkedList*)malloc(sizeof(LinkedList));
	strcpy(temp -> next -> name, name);
	temp -> next -> avg = data;
	temp -> next -> next = NULL;
	return 0;
}
