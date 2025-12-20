#include <stdio.h>

//declaration
char board[9]={1,2,3,4,5,6,7,8,9};


//helper functions
void display_board(board)
{
	for (int i = 0; i<9; i++){
	printf("%c",board[i])
	
	}

}



int main (void)
{
//Launch game
	printf("Welcome to Tic Tac Toe\n");

	return 0;
}
