#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_RAND 11
#define RAND_FIRST -5
#define PI 3.14159265359

int reflection(int angle);
int kickDisc(double wallWidth, double wallHeight, double ballCenterX,
 		double kickAngle, double ballRadius, double goalWidth);

int randNumber(int angle){
srand(angle);
return (rand() % MAX_RAND + RAND_FIRST);
}

int main(){

	kickDisc(10, 26, 2, 45, 1, 2);

	return 0;
}

int reflection(int angle){

	angle += randNumber(angle);
	
	if(angle < 5)
	{
		angle = 5;
	}
	else if(angle > 175)
	{
		angle = 175;
	}

	return angle;
}

int kickDisc(double wallWidth, double wallHeight, double ballCenterX,
 		double kickAngle, double ballRadius, double goalWidth){
 		
 		double difference = wallWidth - ballCenterX;
 		double radian = (kickAngle * PI / 180);
 		double height = (difference + ballRadius) * tan(radian) ;
 		double reflect = reflection(radian);
 		double goalLeft = (wallWidth / 2) - (goalWidth / 2);
 		double goalRight = (wallWidth / 2) + (goalWidth / 2);
 		
 		
 		if	(wallWidth < 0 || wallHeight < 0
 			|| goalWidth > wallWidth 
 			|| 2.0 * ballRadius > wallWidth 
 			|| 2.0 * ballRadius > goalWidth 
 			|| 2.0 * ballRadius > wallHeight 
 			|| (kickAngle < 5.0 || kickAngle > 175.0) 
 			|| ballCenterX - ballRadius < 0 
 			|| ballCenterX + ballRadius > wallWidth )
 		{
 			return 0;
 		}
 		else if(height == 0)
 		{
 			/* check goal or not */
 			if(ballCenterX > goalLeft && ballCenterX < goalRight)
 			{
 				return 1;
 			}
 		}
 		else
 		{
			if(kickAngle > 90)
			{
				kickAngle = 180 - kickAngle;
			}
		
	 		ballCenterX += difference;
	 		if((wallHeight - height) > 0 ) 
	 		{
	 			wallHeight -= height;
	 			
	 			/* X Leftmost */
	 			if(ballCenterX == ballRadius)
	 			{
	 				wallWidth -= (2 * ballRadius);
	 				height = 
	 			}
	 			/* X rightmost */
		 		else if( ballCenterX == wallWidth - ballRadius )
		 		{
		 			kickDisc(wallWidth, wallHeight, ballCenterX,
		 			reflect, ballRadius, goalWidth);
		 		}
		 		else
		 		{
		 		;
		 		}
	 		}
	 		else
 			{
	 			height =- wallHeight;
	 				
	 		}
 	return 0;	
}


