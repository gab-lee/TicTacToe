Tic Tac Toe

Game setup
<array> display_board()
//
1|2|3
-+-+-
4|5|6
-+-+-
7|8|9

==variables==
board=[1,2,3,4,5,6,7,8,9]


==Helper_fucntions==
user_move -> check_valid_move -> return 1 if valid 0 if not valid
user_move -> overwrite_board //changes the board based on user input 
board -> display_board -> prints the tic tac toe board
board -> check_win -> return 1 if there is a winning board, 0 if not
board -> check_no_more_moves -> return 1 if there are no more moves, 0 if there is still space
board -> computer_moves random move -> check valid - > if valid then overwrite board -> display board -> check if win 

User/Com move
> after_move_sequence
>> overwrite_board
>> display_board
>> check_win
>> check_no_more_moves


==Game play==

void main() 

> display_board()

While game_on 
User_input 
> while check_valid_move(user_input) == false
	user_input

after_move_sequence(User_move)

computer_input
>while check_valid_move(Computer_input) == False
> after_move_sequence (com_move)



