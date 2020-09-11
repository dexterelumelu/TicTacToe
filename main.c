/*
	TICTACTOE GAME BUILT BY DEXTER ELUMELU

	READ THE INSTRUCTIONS :)

	I used i686-w64-mingw32-gcc to compile it and I tested it as an executeable
*/

#include <stdio.h>
#include <windows.h>


//ascii for  directions.
#define KEY_UP 119		//w
#define KEY_DOWN 115	//s
#define KEY_LEFT 97		//a
#define KEY_RIGHT 100	// d
#define KEY_ENTER 121	// y

int game_table[3][3];
int alternate = 0;
int spaces_left;
int position;


void zero_table(void);
void print_welcome(void);
void print_table(void);
void player_one_play(void);
void player_two_play(void);
int check_win(void);
int check_win_diagonal(void);
int check_win_horizontal(void);
int check_win_vertical(void);
void shift_pointer(int is_pressed);
int state_of_spot(void);


int main(int argc, char const *argv[])
{
	print_welcome();

	// Flow of control for the end of the game
	start:
	
	//(9 places to play at the beginning of each game)
	spaces_left = 9;

	//set every value on table to default/empty
	zero_table();

	//position of the pointer to first column on the first row
	position = 0;

	//we are using ASCII to get values
	int c = 0;

	print_table();
	while(1){
		//To insert my multiplayer functions and  virus code when I am done with them 

		//local_multiplayer_same_system:
		while(1){

			c = 0;

			// Switch statement because why not
			switch((c=getchar())) {

	        case KEY_UP:
	            printf("\n\n");
				shift_pointer(1);
				system("cls");
				print_table();
	            break;

	        case KEY_DOWN:
	            printf("\n");
				shift_pointer(2);
				system("cls");
				print_table();
				break;

	        case KEY_LEFT:
	            printf("\n");
				shift_pointer(3);
				system("cls");
				print_table();
				break;

	        case KEY_RIGHT:
	            printf("\n");
				shift_pointer(4);
				system("cls");
				print_table();
				break;

			case KEY_ENTER:
	            if (state_of_spot() == 0)
				{
					if (alternate == 0)
					{
						player_one_play();
						Sleep(10);
						system("cls");
						print_table();
						alternate = 1;
						spaces_left--;
					}else if (alternate == 1){
						player_two_play();
						Sleep(10);
						system("cls");
						print_table();
						alternate = 0;
						spaces_left--;
					}
					if (check_win() == 1)
					{
						system("cls");
						goto start;
					}else if (spaces_left == 0)
					{
						system("cls");
						printf("DRAW!!\n");
						goto start;
					}
				}else{
					printf("\n");
				}
				break;
	        default:
	        	break;
        	}
		}
	}
	return 0;
}

//To print the table with the position cursor
void print_table(void){
	for (int i = 0; i < 3; i++)
	{
		printf("|");
		for (int j = 0; j < 3; j++)
		{
			if (game_table[i][j] == 0)
			{
				if (position / 3 == i &&
				position % 3 == j)
				{
					printf("_|");
				}
				else{
					printf("X|");
				}
			}else if (game_table[i][j] == 1)
			{
				if (position / 3 == i &&
				position % 3 == j)
				{
					printf("_|");
				}
				else{
					printf("O|");
				}
			}else{
				if (position / 3 == i &&
				position % 3 == j)
				{
					printf("_|");
				}else{
					printf(" |");
				}
			}
		}
		printf("\n");
	}
}

//To zero the table 
void zero_table(void){
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game_table[i][j] = -1;
		}
	}
}

//Player one plays:
void player_one_play(void){
	int position_row, position_column;
	//convert 1d position to 2d position on the table
	position_row = position / 3;
	position_column = position % 3;

	game_table[position_row][position_column] = 0;
}

void player_two_play(void){
	int position_row, position_column;

	//convert 1d position to 2d position on the table
	position_row = position / 3;
	position_column = position % 3;

	game_table[position_row][position_column] = 1;
}

void shift_pointer(int is_pressed){
	//shifts the pointer either left, right, up or down
	//the only part of the table that has no movement restrictions is the middle(non-border area)
	//up is 1; down is 2; left is 3; right is 4;
	if (is_pressed == 1)
	{	
		//no up movement on row 0 (1st row)
		if (position < 3)
		{
			position = position;
		}else{
			position -= 3;
		}
	}else if (is_pressed == 2)
	{
		//no down movement on row 2 (3rd row)
		if (position > 5)
		{
			position = position;
		}else{
			position += 3;
		}
	}else if (is_pressed == 3)
	{
		//no left movement on column 0 (1st column)
		if (position % 3 == 0)
		{
			position = position;
		}else{
			position -= 1;
		}
	}else if(is_pressed == 4)
	{	
		//no right movement on column 2 (3rd column)
		if (position % 3 == 2)
		{
			position = position;
		}
		else{
			position += 1;
		}
	}
}

void print_welcome(void){
	printf("Welcome\n");
}

//check that spot is free
int state_of_spot(void){
	//To know if spot is empty
	int row, column;
	row = position / 3;
	column = position % 3;

	if (game_table[row][column] == 0 ||
		game_table[row][column] == 1)
	{
		return 1;
	}

	return 0;
}

//determine if there is a win from one of the possible ways of winning
int check_win(void){
	/*	if x registers as 0, a win would be x on a whole line. This means that the
		sum of the row will be zero.
		empty rows register as -1, so there will be no errors
		
		if o registers as 1, a win would be y on a whole line. This means that the
		sum of the row will be three.
		empty rows register as -1, so there will be no errors
	*/
	if (check_win_horizontal() == 0 ||
		check_win_vertical() == 0 ||
		check_win_diagonal() == 0)
	{
		printf("X WINS!!!!!\n");
		return 1;
	}else if (check_win_horizontal() == 1 ||
		check_win_vertical() == 1 ||
		check_win_diagonal() == 1)
	{
		printf("Y WINS!!!!!\n");
		return 1;
	}
	return 0;
}

//determine if there is a horizontal win
int check_win_horizontal(void){
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += game_table[i][j];
			if (game_table[i][j] == -1)
			{
				break;
			}
		}
		if (sum == 3)
		{
			return 1;
		}else if(sum == 0){
			return 0;
		}
	}
	return -1;
}

//determine if there is a vertical win
int check_win_vertical(void){
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += game_table[j][i];
			if (game_table[j][i] == -1)
			{
				break;
			}
		}
		if (sum == 3)
		{
			return 1;
		}else if (sum == 0)
		{
			return 0;
		}
	}
	return -1;
}

//determine if there is a diagonal win
int check_win_diagonal(void){
	int sum = game_table[0][0] + game_table[1][1] + game_table[2][2];
	if (sum == 3)
	{
		return 1;
	}
	else if (sum == 0)
	{
		return 0;
	}

	sum = game_table[0][2] + game_table[1][1] + game_table[2][0];
	if (sum == 3)
	{
		return 1;
	}
	else if (sum == 0)
	{
		return 0;
	}
}


// This is in case you want to use virtual keystrokes :)
/*
	for (int i = 8; i <= 255; i++)
			{
				if(GetAsyncKeyState(i) == -32767)
				{
					if (i == VK_UP){
						printf("\n\n");
						shift_pointer(1);
						print_table();
					}else if (i == VK_DOWN){
						printf("\n");
						shift_pointer(2);
						print_table();
					}else if (i == VK_LEFT){
						printf("\n");
						shift_pointer(3);
						print_table();
					}else if (i == VK_RIGHT){
						printf("\n");
						shift_pointer(4);
						print_table();
					}else if (i == VK_RETURN)
					{
						if (state_of_spot == 0)
						{
							if (alternate == 0)
							{
								player_one_play();
								print_table();
								alternate = 1;
							}else if (alternate == 1){
								player_two_play();
								print_table();
								alternate = 0;
							}
						}
					}
				}
	}
*/
