#include <stdio.h>
#include <stdlib.h>
#include <time.h> //use to seed rand()
#include <unistd.h>  // add time delay

void display_board(char board[9])
//Displays the current state of the board
{
	printf("=======================\n");
	printf("=====-------------=====\n");
	printf("=====---|%c|%c|%c|---=====\n",board[0], board [1],board[2]);
	printf("=====---|-+-+-|---=====\n");
	printf("=====---|%c|%c|%c|---=====\n",board[3],board[4],board[5]);
	printf("=====---|-+-+-|---=====\n");
	printf("=====---|%c|%c|%c|---=====\n", board[6],board[7],board[8]);
	printf("=====-------------=====\n");
	printf("=======================\n");
}

int is_move_valid(char user_move,char board[9]){
//returns 1 if the move is valid, and 0 if the move is invalid

	if (board[user_move-49] >= '1' && board[user_move-49]<='9'){ //comparison of ASCII code '1':49 '9':57
		return 1;
	}
	else{
		return 0;
	}
}

int check_win (char player, char board[9]){
//Check if player (Com or player) has won
	if(board[4]==player){
		if (board[0]==player && board[8]==player){
			return 1;
		}
		if (board[1]==player && board[7]==player){
			return 1;
		}
		if (board[2]==player && board[6]==player){
			return 1;
		}
		if (board[3]==player && board[5]==player){
			return 1;
		}
	}

	else if (board[2]==player){
		if (board[0]==player && board[1]==player){
			return 1;
		}
		if (board[5]==player && board[8]==player){
			return 1;
		}
		}
	else if (board[6]==player){
		if (board[7]==player && board[8]==player){
			return 1;	
		}
		if (board[0]==player && board[3]==player){
			return 1;
		}
		}

	else{
		return 0;
	}
		return 0;
	}

int is_game_over(char board[9], int moves){
//check if the game is over - com/player won or no more moves to be made
	//player has won
	if(check_win('o',board)){
		printf("Player has won\n");
		return 1;
		}
	//com won
	else if(check_win('x',board)){
		display_board(board);
		printf("The computer has won\n");
		return 1;
		}
	//no more moves
	else if (moves==9){
		printf("No one has won.");
		return 1;
		}
	else {
		return 0;
		}
}
	
void game_sequence(void){

	char board[9]={'1','2','3','4','5','6','7','8','9'};
	char turn = 'o';
	char user_move;
	int game = 0;
	int moves =0;
	srand((unsigned)time(NULL)); //seeding a random number only has to be done once
	int r;
	char com_move;

//game_start
	printf("The game is starting\n");

//player's turn
	while (game == 0){
	if (turn == 'o'){
		display_board(board);
		printf("please choose a square to place your 'o' piece\n");
		
		scanf(" %c",&user_move);

		if(is_move_valid(user_move,board)){
			board[user_move-49]='o';
			display_board(board);
			moves ++;
			game = is_game_over(board,moves);
			turn = 'x'; //change turn 
			}
		else {
			printf("Sorry, the move is not valid\n");
			}
	}

//com's turn 
	else{
		printf("=======================\n");
		printf("=Computer is thinking.=\n");
		while (turn == 'x'){
			sleep(1);
			printf("=Thinking.............=\n");
			r = rand() % 8+1; //give a random number of range 1 to 8
			com_move = (char)('0'+r);
			if(is_move_valid(com_move,board)){
				board[r-1]='x';
				moves ++;
				game = is_game_over(board,moves);
				turn = 'o';
				}

			}
		}
	}
}


int main (void)
{
char start_game;

//Launch game
	printf("Welcome to Tic Tac Toe\n");
	printf("Start Game y/n\n");

	if(scanf("%c",&start_game)==1 && start_game=='y'){
		game_sequence();	
		}

	else{
		printf("Game has closed");
		}
	

	return 0;
}
