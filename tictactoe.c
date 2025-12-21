#include <stdio.h>

//helper functions
/*
Functions to create
[x] display_board
[x] is_valid_move
[] game_sequence
-> [x] player move
-> [] AI move
[x] game end
-> [x] Check if win
-> [x] Game end if no more moves
*/

void display_board(char board[9])
{
	printf("-------------\n");
	printf("---|%c|%c|%c|---\n",board[0], board [1],board[2]);
	printf("---|-+-+-|---\n");
	printf("---|%c|%c|%c|---\n",board[3],board[4],board[5]);
	printf("---|-+-+-|---\n");
	printf("---|%c|%c|%c|---\n", board[6],board[7],board[8]);
	printf("-------------\n");
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
	//player has won
	if(check_win('o',board)){
		printf("Player has won\n");
		return 1;
		}
	//com won
	else if(check_win('x',board)){
		printf("The computer has won\n");
		return 1;
		}
	//no more moves
	else if (moves==9){
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
		printf("Let's wait till this part is coded\n");
		turn = 'o';
		//game = 0;
		//moves ++;
		game = is_game_over(board,moves);
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
