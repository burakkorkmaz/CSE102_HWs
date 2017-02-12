#include <stdio.h>
#define BOARD_SIZE 8


/*
 *	Chess pieces set out in order. 
 */
void initBoard(char board[]);

/*
 *	Show Chessboard.
 */
void printBoard(char board[]);

/*
 *	converting integer value all coordinates to find position easily.
 */
void getPosition(char *col, int *row); 

/*
 *	return row index on board
 */
int getRowIndex(int row);
/*
 *	return cell index on board
 */
int getIndex(char col, int row);

/*
 *	Check validness of given coordinate.
 *	Valid -> return 1
 *	Invalid -> return 0
 */
int isValidCell(char col, int row);


int isPieceMovable(char *board, char sc, int sr, char tc, int tr);


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

/*	Checks whether a king is in check or not.
 *		If white king is in check, returns 1
 *		If black king is in check, returns 2
 *		If there is no check, returns 0
 */
int isInCheck(char* board);

/*	Moves a piece from source to destination if current player’s king is not
 *	in check and piece can move from source to destination.
 *		If move is invalid, returns 0
 *		If move is invalid because same player's king is in check, returns 1
 *	 	If move is valid, returns 2
 *		If move is valid and opponent player's king is in check, returns 3
 */
int makeMove(char *board, char sc, int sr, char tc, int tr);
char getPlayer(char*board, char sc, int sr);
int isBlack(char currentPlayer);
int isWhite(char currentPlayer);
int main() {
    char board [BOARD_SIZE * BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}


void initBoard(char board[])
{
    int i;
    int j;
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 
        'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    
    
    j=0;
    for(i=0; i < (BOARD_SIZE * BOARD_SIZE) ; ++i)
    {
        if(i < BOARD_SIZE)       /* First Row */
        {
            board[i] = pieces[j];
            ++j;
        }
        else if(i < BOARD_SIZE * 2)     /* 2nd row - Pawns */
        {    
            board[i] = 'P';
        }  
        
        else if(i < BOARD_SIZE * 6)     /* empty rows among pieces */
        {
            board[i] = ' ';
        }
        else if(i < BOARD_SIZE * 7)     /* 7th row - pawns */
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
    
    row = BOARD_SIZE;
    last = (BOARD_SIZE * BOARD_SIZE) - 1 ;
    i = (BOARD_SIZE * 7); /* first element of 8th row (h1) - index 56 */
    while(row > 0){
    
        printf("%d|", row);
    
        for( ; i < last ; ++i)
        {
            printf("%c ", board[i]);
        }
        printf("%c|\n", board[last]);   /* the last place on the row */
        i -= (2 * BOARD_SIZE - 1);     /* Go to next row (index -15)*/
        last -= BOARD_SIZE;   
        --row;
    }
    printf("  - - - - - - - - \n");
}

void getPosition(char *col, int *row)
{
	scanf (" %c", col);
    scanf ("%d", row);

	/* converting integer */  
   	*col -= 'a';
    *row -= 1;   
}

int getRowIndex(int row){
	return (row * BOARD_SIZE);
}

int getIndex(char col, int row)
{
	return (int)(col + getRowIndex(row));
}

int isValidCell(char col, int row)
{
	if(col >= 0 && col < BOARD_SIZE && row >= 0 && row < BOARD_SIZE)
	{
		return 1;
	}
	return 0;
}
char getPlayer(char*board, char sc, int sr){
	
	int position = getIndex(sc, sr);
	
	if(board[position] > 'A' && board[position] < 'Z')
	{
		return 'W';	/* White player */
	}
	
	return 'B';	/* Black player */
}

int isBlack(char currentPlayer){
	if(currentPlayer == 'B')
	{
		return 1;
	}
	return 0;
}
int isWhite(char currentPlayer){
	if(currentPlayer == 'W')
	{
		return 1;
	}
	return 0;
}


int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
	/* Declaration of Variables */
    int sourcePosition = getIndex(sc, sr);
    int movable;
    
    if(sc == tc && sr == tr)
    {
    	return 0;
    }
    
	if(board[sourcePosition] == ' ')	/* it must be a piece to move */
	{
		return 0;
	}
 
	switch ( board[sourcePosition] )
	{
		case 'R':
		case 'r': movable = isRookMovable(board, sc ,sr, tc, tr);
			break;
		case 'N': 		 	
		case 'n': movable = isKnightMovable(board, sc ,sr, tc, tr);
			break;
		case 'B': 
		case 'b': movable = isBishopMovable(board, sc ,sr, tc, tr);
			break;
		case 'Q': 
		case 'q': movable = isQueenMovable(board, sc ,sr, tc, tr);
			break;
		case 'K': 
		case 'k': movable = isKingMovable(board, sc ,sr, tc, tr);
			break;
		case 'P': 
		case 'p': movable = isPawnMovable(board, sc ,sr, tc, tr);
			break;
		default: 	return 0;
	}
    
    if(!movable)
    {
    	return 0;	
    }
    
    return 1;
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
	int sr = getRowIndex(sourceRow);
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
		if( target >= sr && target < (sr + BOARD_SIZE) )
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
				!(exit) && i < (sr + BOARD_SIZE) && i >= sr;
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
				j = BOARD_SIZE;
			}
			else		/* Move Down */
			{
				j = -1 * BOARD_SIZE; /* -8 */
			}
			
			for (i = source ;
			 	!(exit) && i >= 0 && i < (BOARD_SIZE*BOARD_SIZE); 
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
	int sr = getRowIndex(sourceRow);
	
	
	
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
	
		if((source + 16) < 64)	/* move up (+16) */
		{
			if( (sr + 16) <= (source + 15)) /* up + left(-1) */
			{
				if(target == (source + (source + 15)) )
				{
					return 1;
				}
			}
			if( (sr + 16) + 8 > (source + 17)) /* up + right(+1) */
			{
				if(target == (source + 17) )
				{
					return 1;
				}
			}
		}
	
		if((source - 16) > 0)	/* move down */
		{
			if( (sr - 16) <= (source - 17)) /* down + left */
			{
				if(target == (source - 17) )
				{
					return 1;
				}
			}
			if( (sr - 16) + 8 > (source - 15)) /* down + right */
			{
				if(target == (source - 15) )
				{
					return 1;
				}
			}
		}
	
		if((source + 2) < 64)	/* move right (+2)*/
		{
			if( (sr + 16) > 10) /* right + up(+8) */
			{
				if(target == (source + 10 ))
				{
					return 1;
				}
			}
			if( sr  > (source - 6)) /* right + down(-8) */
			{
				if(target == (source - 6 ))
				{
					return 1;
				}
			}
		}
		if((source - 2) > 0)	/* move left (-2)*/
		{
			if( (sr + 8) >= (source + 6)) /* left + up (+8)*/
			{
				if(target == (source + 6 ))
				{
					return 1;
				}
			}
			if( (sr - 8) >= (source - 10)) /* left + down(-8) */
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
	int sr = getRowIndex(sourceRow);
	int tr = getRowIndex(targetRow);
	int move;

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
		if(sr < tr)
		{
			move = 7;	/* left-top */
		}
		else if( sr == tr )
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
		if(sr > tr)
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
		if(sr < tr)
		{
			move = 9;	/* right-top */
		}
		else if( sr == tr )
		{
			move = 1;	/* right-middle */
		}
		else
		{
			move = -7;	/* right-bottom */
		}
	}
	
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
	


	if(board[source] > 'A' && board[source] < 'Z')
	{
		/* White pieces are Uppercase letters */
		pieceColor1 = 'A';
		pieceColor2 = 'Z';
		piece = 'P';
		move = 8; 	/* Board size(up) */
	}
	
	else 
	{
		/* Black pieces are Lowercase letters */
		pieceColor1 = 'a';
		pieceColor2 = 'z';
		piece = 'p';
		move = -8;	/* Board size (down)*/
	} 
	
	if(board[source] == piece )
	{
		if(0 <= (source + move) && (source + move) < BOARD_SIZE*BOARD_SIZE)
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
			/* taking opponent pieces diagonally */
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
					if((source + move) + 1  < BOARD_SIZE*BOARD_SIZE)
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

void indexToCoordinate(int index, char *col, int *row){
	
	*row = index / BOARD_SIZE;
	--(*row);
	
	*col = index % BOARD_SIZE;
	--(*col);

	
}

int isInCheck(char* board){
	
	int sr;
	char sc;
	int tr;
	char tc;
	int i;
	int index;
	int checkBlack = 0;
	int checkWhite = 0;

/* black in check */
	for(i=0; i < 64; ++i)
	{
		if(board[i] == 'k')
		{
			index = i;
		}
	}
	/* Target is black king */
	indexToCoordinate(index, &tc, &tr);
		
	for(i=0; i < 64 && !(checkBlack) ; ++i)
	{
		if(board[i] > 'A' && board[i] < 'Z')
		{
			indexToCoordinate(i, &sc, &sr);
			if(isPieceMovable(board, sc, sr, tc, tr) == 1)
			{
				checkBlack = 1;
			}
		}
	}
	
	if(checkBlack)
	{
		return 2;
	}
	
	/* white in check */
	for(i=0; i < 64; ++i)
	{
		if(board[i] == 'K')
		{
			index = i;
		}
	}
	/* Target is white king */
	indexToCoordinate(index, &tc, &tr);
		
	for(i=0; i < 64 && !(checkWhite) ; ++i)
	{
		if(board[i] > 'a' && board[i] < 'z')
		{
			indexToCoordinate(i, &sc, &sr);
			if(isPieceMovable(board, sc, sr, tc, tr) == 1)
			{
				checkWhite = 1;
			}
		}
	}
	
	if(checkWhite)
	{
		return 1;
	}
	
	
	return 0;

}

int makeMove(char *board, char sc, int sr, char tc, int tr){
	
	int source = getIndex(sc, sr);
	int target = getIndex(tc, tr);
	int valid = 2;	
	char player = getPlayer(board, sc, sr);
	printf("player %c\n", player);
	printf("sor %d tar %d\n ", source, target );
		printf("incheck %d\n", isInCheck(board));
printf("piecemoveb %d\n",(isPieceMovable(board,sc,sr,tc,tr)));
	/* White king against black king */
	if((board[source] == 'K' && board[target] == 'k') 
		|| (board[source] == 'k' && board[target] == 'K'))
	{
		if((isPieceMovable(board,sc,sr,tc,tr)))
		{
			return 0;
		}
	}
	
	/* check make movement */
	if(!(isPieceMovable(board,sc,sr,tc,tr)))
	{
		return 0; 
	}	
	else
	{
		if(player == 'W')
		{
			switch(isInCheck(board))
			{
				case 0: valid = 2; break;
				case 1: return 1;
				case 2: valid = 3; break;
			}	
		}
		if(player == 'B')
		{
			switch(isInCheck(board))
			{
				case 0: valid = 2; break;
				case 1: valid = 3; break;
				case 2: return 1;
			}	
		}
		
		/* Make move */
		board[target] = board[source];
		board[source] = ' ';
		
		
	}
	
	
	
	return valid;
}
