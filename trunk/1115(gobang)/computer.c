#include "common.h"

extern void get_player_win_table_max();
extern void get_computer_win_table_max();
extern void fb_black_point(int, int);
extern void fb_num(int, int, int, int);

//computer play chess
void computer(void)
{
	int x, y;
	int i, j;

	get_player_win_table_max();
	get_computer_win_table_max();

	printf("player_max:(%d, %d)\n", player_max_x, player_max_y); 
	printf("computer_max:(%d, %d)\n", computer_max_x, computer_max_y); 

	if(computer_max >= player_max)
	{
		x = computer_max_x;
		y = computer_max_y;
		
		pos_flag[x][y] = 2;
	
		x = X + x * SPACE;
		y = Y + y * SPACE;

		fb_black_point(x, y);
		fb_num(chess_num++, x, y, 0xffffff);
	}
	else
	{
		x = player_max_x;
		y = player_max_y;

		pos_flag[x][y] = 2;

		x = X + x * SPACE;
		y = Y + y * SPACE;

		fb_black_point(x, y);
		fb_num(chess_num++, x, y, 0xffffff);
	}
	
	get_player_win_table_max();
	get_computer_win_table_max();

	return;
}


