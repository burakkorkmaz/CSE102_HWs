#include <stdio.h>
#include <string.h>

int isPalindrome(char * str);
int resizeString(char * str, int first, int last);
char convertCase(char ch);

int main(){
	
	printf("main1\n");
	
	printf("-->%d\n",isPalindrome("zz"));
	
	return 0;
}

int isPalindrome(char * str){
	
	int size = strlen(str);
	int first = 0;
	int last = (size - 1);
	
	
	if(resizeString(str, first, last))
		{
		return 1;
		}

	return 0;
}

int resizeString(char * str, int first, int last){
	
	
	int result = 0 ;
	int temp1 = str[first];
	int temp2 = str[last];
	/* base cases */
	if(str[first] == '\0')	
	{
	return 0;
	}
	
	else if((last - first <= 0)
			&& str[first] >= 'A' && 'z' >= str[first] 
			&& str[last] >= 'A' && 'z' >= str[last] 
			)	
	{
			if((str[first] >= 'Z' && 'a' >= str[first]) 
				&& (str[last] >= 'Z' && 'a' >= str[last]))
			{
				return 0;
			}
		return 1;
	}
	
	else
	{
		if((str[first] >= 'A' && str[first] <= 'Z') || 
			(str[last] >= 'A' && str[last] <= 'Z') )
		{
			if((str[first] >= 'A' && str[first] <= 'Z'))
			{
				temp1 = convertCase(str[first]);
			}	
		
			if(str[last] >= 'A' && str[last] <= 'Z')
			{
				temp2 = convertCase(str[last]);
			}
		}
		if( (temp1 < 'a' || temp1 > 'z') ||
			(temp2 < 'a' || temp2 > 'z'))
		{	
			if(temp1 < 'a' || temp1 > 'z')
			{
				result = resizeString(str, ++first, last);
			}
			if(temp2 < 'a' || temp2 > 'z')
			{
				result = resizeString(str, first, --last);	
			}
		}
		if((temp1 >= 'a' && temp1 <= 'z') ||
			(temp2 >= 'a' && temp2 <= 'z'))
		{	
			if(temp2 == temp1)
			{
				result = resizeString(str, ++first, --last);
			}
			else 
			{
				return result;
			}
		}
	}
	
	return result;
}

char convertCase(char ch){
	
	ch += 32;	/* 'a' - 'A' = 32 */ 
	
	return ch;
}
