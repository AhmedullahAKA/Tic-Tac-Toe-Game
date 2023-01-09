// A Tic Tac Toe Game in c programming language:

//First we will import libraries ;
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//Declaring some varibles which will be used in our program;
char board[5][5];
const char PLAYER = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

//The following are the functions prototype
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void secondPlayer();
void computerMove();
char checkWiner();
void printWiner(char);
void printWiner1(char);

// The main function through which compiler start compiling our code;
int main()
{
	// Declaring some variables;
    char winner = ' ';
    char response;
    int option;
    
    do										// Loop for game if user want to play again;
    {
        winner = ' ';
        response= ' ';
        
        printf("\t\t\t\t\t *****WELCOME TO TIC TAC TOE GAME*****\n\n\n");   
		printf("   which game do you want to play :  \n\n\n   1)User to Computer \n\n\n   2)User to User\n");
		scanf("%d",&option);
		if (option == 1)					
		{
	        resetBoard();					// Recalling reset fuunction will make matrix of 5 * 5;
	        
	        while (winner == ' ' && checkFreeSpaces() != 0)
	        {
	        	
	            printBoard();				// Printing board for game by recalling printBoard function;	
	            printf("\n\t\t\t\t\t *****USER TO COMPUTER*****\n\n\n ");
	
	            playerMove();				// It is playerMove function through which user will be able to do his move;
	            winner = checkWiner();		// Cheacking if player wins
	            if(winner != ' ' || checkFreeSpaces() == 0 )
	            {
	                break;
	            }
	
	            computerMove();				// Computer move atomatically generated move
	            winner = checkWiner();		// Cheacking if computer wins
	            if(winner != ' ' || checkFreeSpaces() == 0 )
	            {
	                break;
	            }
	
	        }
	        
	        printBoard();
	        printWiner(winner);
	        
	        printf("\n would you like to play again? (Y/N): ");       // This following four lines are used if user want to play again;
	        scanf("%c");
	        scanf("%c", &response);
	        response = toupper(response);
 			system("cls");					// Built in funtion that remove previous interface which we do not need further more;

		}
		
    } while (response == 'Y');				// Loop condition that if user want to play again;
    
    if  (option == 2)						// This code will be for User to User if option = 2;
    {
    	do									
    {
        winner = ' ';						
        response= ' ';
        resetBoard();						// Recalling reset fuunction which will make matrix of 5 * 5;

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
        	printBoard();					// Printing board for game by recalling printBoard function;
			printf("\n\t\t\t\t\t *****USER TO USER*****\n\n\n ");
            playerMove();					// First player move ;
            printBoard();				   // printing board;

            winner = checkWiner();			// cheacking if player 1 win;
            if(winner != ' ' || checkFreeSpaces() == 0 )
            {
                break;
            }

            printBoard();					//Agian printing board;
			printf("\n\t\t\t\t\t *****USER TO USER*****\n\n\n ");
			secondPlayer();					// second player move;
			printBoard();					// After move the board should print;
			
            winner = checkWiner();			// Chaeck if second player win!
            if(winner != ' ' || checkFreeSpaces() == 0 )
            {
                break;
            }

        }
        
        printBoard();						
        printWiner(winner);					// printing winner whether first player or second player;

        printf("\n would you like to play again? (Y/N): ");		// This following four lines are used if user want to play again;
        scanf("%c");
        scanf("%c", &response);				
        response = toupper(response);
        system("cls");
    } while (response == 'Y');
	
	}
	else									// if user entered wrong choice in beggining
	{
		printf("YOU HAVE ENTERED WRONG CHOICE PLEASE RESTART IT;\n");	 
		return 0;
	}	
	
    
    printf("thanks for playing! :( ");

    return 0;
}

void resetBoard()					// This is function in which we make 5 * 5 matrix using nested loop;
{
    for(int i = 0; i < 5 ; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            board[i][j]= ' ';
        }

    }

}
void printBoard()					// this function display the board to the player to play the game.
{ 
   system("cls");
   printf("     1       2       3       4       5\n");
   printf("  +-------+-------+-------+-------+-------+\n");
   printf("  |       |       |       |       |       |\n");
   printf("1 |   %c   |   %c   |   %c   |   %c   |   %c   |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4]);
   printf("  |       |       |       |       |       |\n");
   printf("  +-------+-------+-------+-------+-------+\n");
   printf("  |       |       |       |       |       |\n");
   printf("2 |   %c   |   %c   |   %c   |   %c   |   %c   |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4]);
   printf("  |       |       |       |       |       |\n");
   printf("  +-------+-------+-------+-------+-------+\n");
   printf("  |       |       |       |       |       |\n");
   printf("3 |   %c   |   %c   |   %c   |   %c   |   %c   |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4]);
   printf("  |       |       |       |       |       |\n");
   printf("  +-------+-------+-------+-------+-------+\n");
   printf("  |       |       |       |       |       |\n");
   printf("4 |   %c   |   %c   |   %c   |   %c   |   %c   |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4]);
   printf("  |       |       |       |       |       |\n");
   printf("  +-------+-------+-------+-------+-------+\n");
   printf("  |       |       |       |       |       |\n");
   printf("5 |   %c   |   %c   |   %c   |   %c   |   %c   |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4]);
   printf("  |       |       |       |       |       |\n");
   printf("  +-------+-------+-------+-------+-------+\n");
}
int checkFreeSpaces()				// This function cheacks whether their is Free spaces available on board or not;
{
    int freeSpaces = 25;
    for(int i = 0; i < 5 ; i++ )
    {
        for(int j = 0; j < 5 ; j++ )
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove()					// This function allows user to do his move only in possible condition;
{
   
    int x ;
    int y ;

    do
    {
    printf("Player 1 \n Enter row #(1-5): ");
    scanf("%d",&x);
    x--;

    printf("Player 1 \n Enter column #(1-5): ");
    scanf("%d",&y);
    y--;

    if (board[x][y] != ' ')
    {
        printf("invalid move ! \n");
        return playerMove();
    }
    else{
    board[x][y] = PLAYER;}
    break;
    
    } 
    while (board[x][y] != ' ');
}
void secondPlayer()					// This function allows sencond user to do his move only in possible condition;
{
   
    int x ;
    int y ;

    printf("Player 2 \n Enter row #(1-5): ");
    scanf("%d",&x);
    x--;

    printf("Player 2 \n Enter column #(1-5): ");
    scanf("%d",&y);
    y--;

    if (board[x][y] != ' ' && board[x][y] < 6 )
    {
        printf("invalid move ! \n");
        return secondPlayer();
    }
    else{
    board[x][y] = PLAYER2;}
}

void computerMove()					// This function will attomatically generate move; 
{
    //create a seed based on current time
    srand (time(0));				// This is built in function to change time contineously
    int x ;
    int y ;

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 5;			// It will randomly assign any position to x-axis;
            y = rand() % 5;			// It will randomly assign any position to y-axis;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
        
    }
    else
    {
        printWiner(' ');
    }
}
char checkWiner()					// In this condition we will tell all conditions on which game will be won and terminate.
{
     //condition to cheack rows that they are same or not 
    for (int i = 0 ; i < 5 ; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board [i][4] )
        {
            return board[i][0];
        }
    }
    //condition to cheack column that they are same or not
    for (int i = 0 ; i < 5 ; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i] )
        {
            return board[0][i];
        }
    }
    //condition to cheack diagonal that they are same or not
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board [3][3] && board[0][0] == board[4][4] )
    {
        return board[0][0];
    }
    if (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] == board[4][0])
    {
        return board[0][4];
    }

    return ' ';
}
void printWiner(char winner)	// This condition will print winner (In case of Player VS computer)
{
    if (winner == PLAYER)
    {
        printf("YOU WIN!");

    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSE!");

    }
    else 
    {
        printf("ITS A TIE!");
    }
}
void printWiner1(char winner)			// This condition will print winner (In case of Player VS Player)
{
    if (winner == PLAYER)
    {
        printf("Player 1 WIN!");

    }
    else if (winner == PLAYER2)
    {
        printf("Player 1 LOSE!\n \t AND \t\n Player 2 WiN! :(");

    }
    else 
    {
        printf("ITS A TIE!");
    }
}
