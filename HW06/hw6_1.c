#include <stdio.h>

void freq(char* str, int* fr);

int main(){

	int fr[37];
	int i;
	
	freq("asdfjkhlş786mn 9* xsndg dfg+",fr);
	for(i=0; i<37; ++i)
		printf("fr: %d \n",fr[i]);

	return 0;
}

void freq(char* str, int* fr){
	
	int i, j; 
	char ch ;
	
	for(i=0; i < 37; ++i)
		fr[i] = 0;
	
	for(i=0; str[i] != '\0' ; ++i)
	{
		ch = 'A';
		
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			ch += 32;	/* 'A'(65) ---> 'a'(97) */
			j = 0;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			
			j = 0;
		}
		else if(str[i] >= '0' && str[i] <= '9')
		{
			ch -= 17;	/* 'A'(65) ---> '0'(48) */
			j = 26; /*	start of digit index - '0'	*/
		}
		else
		{
			j = 36;
			ch = str[i];	
		}
		
		while( str[i] != ch ) 
		{
		ch++;
		++j;
		}
		
		fr[j]++;
		
	}
	
}
