#include <stdio.h>



void initBoard(char board[]);
void printBoard(char board[]);
int isPieceMovable(char board[]);
int isValidCell(char col, int row);
void getPosition(char *col, int *row); 
int getIndex(char col, int row);
int isRookMovable(char *board , char sourceCol, int sourceRow, 
					char targetCol, int targetRow);
					
int isKnightMovable(char *board, char sourceCol, int sourceRow, 
					char targetCol, int targetRow);
					
int isBishopMovable(char *board, char sourceCol, int sourceRow, 
					char targetCol, int targetRow);
					
int isQueenMovable(char *board, char sourceCol, int sourceRow, 
					char targetCol, int targetRow);
					
int isKingMovable(char *board, char sourceCol, int sourceRow, 
					char targetCol, int targetRow);
					
int isPawnMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow);


void emptyBuffer()
{
	while ( getchar() != '\n' );
}
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
	board[7]=' ';			
	board[37]='b';
	board[30]='q';
	board[45]='K';
	
	board[35]='Q';
		board[8]=' ';
		board[44]='P';
		board[52]=' ';
		board[18]='b';
		board[20]='R';
		
		
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
				
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;
}


void initBoard(char board[])
{
    int i;
    int j;
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    
    
    j=0;
    for(i=0; i < 64 ; ++i)
    {
        if(i < 8)       /* First Row */
        {
            board[i] = pieces[j];
            ++j;
        }
        else if(i < 16)     /* 2nd row - Pawns */
        {    
            board[i] = 'P';
        }  
        
        else if(i < 48)     /* empty rows among pieces */
        {
            board[i] = ' ';
        }
        else if(i < 56)     /* 7th row - pawns */
        {
            board[i] = 'p';     
        }
        else        /* and Last Row */
        {
            board[i] = pieces[j];
            ++j;
        }
    }
    
}

void printBoard(char board[]){
	/* Declaration of Variables */
    int i;
    int last;
    int row;
    
    printf("  a b c d e f g h \n");
    printf("  - - - - - - - - \n");
    
    row = 8;
    last = 63;
    i=56; /* first element of 8th row (h1)*/
    while(row > 0){
    
        printf("%d|", row);
    
        for( ; i < last ; ++i)
        {
            printf("%c ", board[i]);
        }
        printf("%c|\n", board[last]);   /* the last place on the row */
        i -= 15;     /* Go to next row */
        last -= 8;   
        --row;
    }
    printf("  - - - - - - - - \n");
}

int isPieceMovable(char board[])
{
	/* Declaration of Variables */
    char sourceY;
    int sourceX;
    char targetY;
    int targetX;
    int sourcePosition;
    int movable;
    
    scanf (" %c", &sourceY);
    scanf ("%d", &sourceX);
    
    scanf (" %c", &targetY);
    scanf ("%d", &targetX);
    
    if(sourceY == targetY && sourceX == targetX)
    {
    	return 0;
    }
    
    
    if(isValidCell(sourceY, sourceX) && 
    	isValidCell(targetY, targetX))
    {
    	getPosition(&sourceY, &sourceX);
    	getPosition(&targetY, &targetX);
    	sourceX *= 8;	/* x-axis of cell on the board */
    	targetX *= 8;
    	printf("%d %d\n", getIndex(sourceY, sourceX), 
    	getIndex(targetY, targetX) );
    	sourcePosition = getIndex(sourceY, sourceX);
    	
    	if(board[sourcePosition] == ' ')	/* it must be a piece to move */
    	{
    		return 0;
    	}
   	}
   	else
   	{
		return 0;
	}
	
	switch ( board[sourcePosition] )
	{
		case 'R': movable = isRookMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'r': movable = isRookMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'N': movable = isKnightMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;			 	
		case 'n': movable = isKnightMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'B': movable = isBishopMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'b': movable = isBishopMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'Q': movable = isQueenMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'q': movable = isQueenMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'K': movable = isKingMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'k': movable = isKingMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'P': movable = isPawnMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		case 'p': movable = isPawnMovable( board ,sourceY ,sourceX, targetY, targetX);
			break;
		default: 	return 0;
	}
    
    if(!movable)
    {
    	return 0;	
    }
    
    return 1;
}

int isValidCell(char col, int row)
{
	if(col >= 'a' && col <= 'h' && row > 0 && row < 9)
	{
		return 1;
	}
	return 0;
}

void getPosition(char *col, int *row)
{
	/* converting integer */  
   	*col -= 'a';
    *row -= 1;   
	
	  
}

int getIndex(char col, int row)
{
	return (int)(col + row);
}


int isRookMovable(char *board , char sourceCol, int sourceRow, 
					char targetCol, int targetRow)
{
	/* Declaration of Variables */
	char piece;
	char pieceColor1;
	char pieceColor2;
	int source = getIndex(sourceCol,sourceRow);
	int target = getIndex(targetCol,targetRow);
	int i;
	int j;
	int exit = 0;
	
	
	
	
	 
	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		
		if( board[source] == 'R')
		{
			piece = 'R';
		}
		
		/* isQueenMovable function needs calling RookMovable and BishopMovable
		 * to use rook and bishop movements
		 */
		else if(board[source] == 'Q')	
		{
			piece = 'Q';
		}
	}
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		if(board[source] == 'r')
		{
			piece = 'r';
		}
		else if(board[source] == 'q')
		{
			piece = 'q';
		}
	} 
	/* Checking Piece Movement */
	if( board[source] == piece && !(board[target] > pieceColor1 
			&& board[target] < pieceColor2) )
	{
		if( target >= sourceRow && target < (sourceRow + 8) )
		{
			if(targetCol > sourceCol){ 	/* Move Right*/
				j = 1;
			}
			else		/* Move Left*/
			{
				j = -1;
			}
								 /* Horizontal Mov. Boundary of Rook */
			for (i = source; 
				!(exit) && i < (sourceRow + 8) && i >= sourceRow;
				i += j)
			{
				if(board[i + j] == ' ')
				{
					if( (i + j) == target )
					{
						
						return 1;
					}
					
				}
				else
				{
					if((i + j) == target )
					{
						
						return 1;
					}
					else
					{
						if(board[i + j] != ' ')
							exit = 1;
					}
				}
			}
		}
		
		else
		{
			if(target > source){ /* Move Up */
				j = 8;
			}
			else		/* Move Down */
			{
				j = -8;
			}
			
			for (i = source ;
			 	!(exit) && i >= 0 && i < 64; 
			 	i += j )
			{
				if(board[i + j] == ' ')
				{
					if( (i + j) == target )
					{
						return 1;
					}
					
				}
				else
				{
					if( (i + j) == target )
					{
						return 1;
					}
					else
					{
						if(board[i+j] != ' ')
							exit = 1;
					}
				}
			}
			
			
		
		}
	}
	
	
	return 0;
}
int isKnightMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow)
{
	char piece;
	char pieceColor1;
	char pieceColor2;
	int source = getIndex(sourceCol, sourceRow);
	int target = getIndex(targetCol, targetRow);
	
	
	
	
	/* White Knight Checks Movable */
	
	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		piece = 'N';
	}
	
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		piece = 'n';
		
	} 
	
	if(board[source] == piece && !(board[target] > pieceColor1 
			&& board[target] < pieceColor2) )
	{
	
		if((source + 16) < 64)	/* move up */
		{
			if( (sourceRow + 16) <= (source + 15)) /* up + left(-1) */
			{
				if(target == (source + 15) )
				{
					return 1;
				}
			}
			if( (sourceRow + 16) + 8 > (source + 17)) /* up + right(+1) */
			{
				if(target == (source + 17) )
				{
					return 1;
				}
			}
		}
	
		if((source - 16) > 0)	/* move down */
		{
			if( (sourceRow - 16) <= (source - 17)) /* down + left */
			{
				if(target == (source - 17) )
				{
					return 1;
				}
			}
			if( (sourceRow - 16) + 8 > (source - 15)) /* down + right */
			{
				if(target == (source - 15) )
				{
					return 1;
				}
			}
		}
	
		if((source + 2) < 64)	/* move right */
		{
			if( (sourceRow + 16) > (source + 10)) /* right + up(+8) */
			{
				if(target == (source + 10) )
				{
					return 1;
				}
			}
			if( sourceRow  > (source - 6)) /* right + down(-8) */
			{
				if(target == (source - 6) )
				{
					return 1;
				}
			}
		}
		if((source - 2) > 0)	/* move left */
		{
			if( (sourceRow + 8) >= (source + 6)) /* left + up */
			{
				if(target == (source + 6) )
				{
					return 1;
				}
			}
			if( (sourceRow - 8) >= (source - 10)) /* left + down */
			{
				if(target == (source - 10) )
				{
					return 1;
				}
			}
		}
	}
	
	
	return 0;
}
int isBishopMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow)
{
	/* Declaration of Variables */
	char piece;
	char pieceColor1;
	char pieceColor2;
	int source = getIndex(sourceCol, sourceRow);
	int target = getIndex(targetCol, targetRow);
	int i;
	int j;
	int exit = 0;
	
	
	
	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		
		if( board[source] == 'B')
		{
			piece = 'B';
		}
		
		/* isQueenMovable function needs calling RookMovable and BishopMovable
		 * to use rook and bishop movements
		 */
		else if(board[source] == 'Q')	
		{
			piece = 'Q';
		}
	}
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		if(board[source] == 'b')
		{
			piece = 'b';
		}
		else if(board[source] == 'q')
		{
			piece = 'q';
		}
	} 
	
	/* Checking movement of Bishops */
	if( board[source] == piece && (!(board[target] > pieceColor1 
		&& board[target] < pieceColor2)))
	{
		if(target > source) /* Check moves to upper rows*/
		{
		
			if (sourceCol > targetCol)	/* left-top */
			{
				j=7;
			}	
			else		/* right-top */
			{
				j=9;
			}
		}
		else		/* Check moves to lower rows*/
		{
			if(sourceCol > targetCol)	/* left-bottom */
			{
				j = -9;
			}
			else		/* right-bottom */
			{
				j = -7;
			}
		}	
		
		for (i = source; !(exit) && i>=0 && i < 64; i += j)
		{	
			if(board[i + j] == ' ')
			{
				if( target == (i + j) )
				{
					return 1;
				}
			}
			else
			{
				if((i + j) == target)
				{
					return 1;
				}
				else
				{
					if(board[i + j] != ' ')
						break;
				}
			}		
		}
	}
	
	return 0;
}
int isQueenMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow)
{

	if ( isRookMovable(board, sourceCol, sourceRow, targetCol, targetRow)
		|| isBishopMovable(board, sourceCol, sourceRow, targetCol, targetRow) )
	{
		return 1;
	}
	return 0;
}
int isKingMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow)
{
	char piece;
	char pieceColor1;
	char pieceColor2;
	int source = getIndex(sourceCol, sourceRow);
	int target = getIndex(targetCol, targetRow);
	int move;

	sourceRow *= 8;	/* x-axis of cell on the board */
	targetRow *= 8;
	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		piece = 'K';
	}
	
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		piece = 'k';
	} 
	
	if(sourceCol > targetCol)	/* Left side */
	{
		if(sourceRow < targetRow)
		{
			move = 7;	/* left-top */
		}
		else if( sourceRow == targetRow )
		{
			move = -1;	/* left-middle */
		}
		else
		{
			move = -9;	/* left-bottom */
		}
	}
	else if(sourceCol == targetCol)	/* Middle */
	{
		if(sourceRow > targetRow)
		{
			move = -8;	/* Down */
		}
		else
		{
			move = 8; /* Up */
		}
	}
	else	
	{
		if(sourceRow < targetRow)
		{
			move = 9;	/* right-top */
		}
		else if( sourceRow == targetRow )
		{
			move = 1;	/* right-middle */
		}
		else
		{
			move = -7;	/* right-bottom */
		}
	}
	printf("move %d Smove %d\n",move, (source + move) );
	if(board[source] == piece && !(board[target] > pieceColor1 
			&& board[target] < pieceColor2) )
	{
	
		if( 0 <= (source + move) && (source + move) < 64)
		{
			if(sourceCol == targetCol - 1)	/* Move Left */
			{
				if((source + move) == target)
				{
					return 1;
				}
			}
			
			else if(sourceCol == targetCol)
			{
				if((source + move) == target)
				{
					return 1;
				}
			}
			
			else if(sourceCol == targetCol + 1)	/* Move Right*/
			{
				if((source + move) == target)
				{
					return 1;
				}
			} 
		}
	}
	
	return 0;
}

int isPawnMovable(char *board, char sourceCol, int sourceRow,
					char targetCol, int targetRow)
{
	char piece;
	char pieceColor1;
	char pieceColor2;
	int source = getIndex(sourceCol, sourceRow);
	int target = getIndex(targetCol, targetRow);
	int move;
	

printf("sc %d sr %d tc %d tr %d s %d t %d\n", sourceCol, sourceRow, targetCol, targetRow, source, target);

	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		piece = 'P';
		move = 8;
	}
	
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		piece = 'p';
		move = -8;
	} 
	
	if(board[source] == piece )
	{
		if(0 <= (source + move) && (source + move) < 64)
		{
			if(sourceCol == targetCol)
			{
				if((source + move) == target && (board[target] == ' '))
				{
					return 1;
				}
			}
			else 
			{
				if(board[source] == piece && !(board[target] > pieceColor1 
			&& board[target] < pieceColor2))
				{
					if(0 <= (source + move) - 1)
					{	
						if((source + move) - 1 == target && board[target] !=' ')
						{
							return 1;
						}
					}
					if((source + move) + 1  < 64)
					{	
						if((source + move) + 1 == target && board[target] !=' ')
						{
							return 1;
						}
					}
				}
			}
		}
	}

	return 0;
}
