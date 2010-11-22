/************************************************************
*  名称：五子棋小游戏
*
*  版本：v1.0
*
*  作者：张双喜
*
*  日期：2010年11月14日
*
*  模块功能：获取人物玩家及电脑玩家获胜表，并分别分析出各自获胜表中分值最大的内容，
*	存入全局变量player_max_x,player_max_y, player_max;computer_max_x,computer_max_y中
* 
 ***********************************************************/

#include "common.h"

static int i = 0, j = 0, k, p, m, n;
static int left_score, right_score, up_score, down_score, left_up_score, right_up_score, left_down_score, right_down_score;

//reset
static void reset(int win_table[NUM][NUM])
{
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			win_table[j][i] = 0;	
		}
	}

	return;
}

//judge win
static void win(char *msg)
{
	if(n == 5)
	{
		printf("%s\n", msg);
		exit(0);
	}

	return;
}

//judge left
static void left(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = j - 1;
	m = 0;
	n = 0;
	for(; k >= 0; k--)
	{
		if(pos_flag[k][i] == code1)
			n++;
		else if(pos_flag[k][i] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[k][i] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	left_score = score[m][n];

	return;
}

//judge right
static void right(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = j + 1;
	m = 0;
	n = 0;
	for(; k < NUM; k++)
	{
		if(pos_flag[k][i] == code1)
			n++;
		else if(pos_flag[k][i] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[k][i] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	right_score = score[m][n];

	return; 
}

//judge up
static void up(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i - 1;
	m = 0;
	n = 0;
	for(; k >= 0; k--)
	{
		if(pos_flag[j][k] == code1)
			n++;
		else if(pos_flag[j][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[j][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	up_score = score[m][n];

	return; 
}

//judge down
static void down(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i + 1;
	m = 0;
	n = 0;
	for(; k < NUM; k++)
	{
		if(pos_flag[j][k] == code1)
			n++;
		else if(pos_flag[j][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[j][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	down_score = score[m][n];

	return; 
}

//judge left up
static void left_up(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i - 1;
	p = j - 1;
	m = 0;
	n = 0;
	for(; k >= 0, p >=0; k--, p--)
	{
		if(pos_flag[p][k] == code1)
			n++;
		else if(pos_flag[p][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[p][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	left_up_score = score[m][n];
	
	return;
}

//judge right up
static void right_up(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i - 1;
	p = j + 1;
	m = 0;
	n = 0;
	for(; k >= 0, p < NUM; k--, p++)
	{
		if(pos_flag[p][k] == code1)
			n++;
		else if(pos_flag[p][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[p][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	right_up_score = score[m][n];

	return; 
}

//judge left down
static void left_down(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i + 1;
	p = j - 1;
	m = 0;
	n = 0;
	for(; k < NUM, p >= 0; k++, p--)
	{
		if(pos_flag[p][k] == code1)
			n++;
		else if(pos_flag[p][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[p][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	left_down_score = score[m][n];

	return; 
}

//judge right down
static void right_down(int i, int j, int code1, int code2, char *msg, int score[2][5])
{
	k = i + 1;
	p = j + 1;
	m = 0;
	n = 0;
	for(; k < NUM, p < NUM; k++, p++)
	{
		if(pos_flag[p][k] == code1)
			n++;
		else if(pos_flag[p][k] == code2)
		{
			m = 0;
			break;
		}
		else if(pos_flag[p][k] == 0)
		{
			m = 1;
			break;
		}
	}

	win(msg);

	right_down_score = score[m][n];

	return; 
}

//judge player chess a pos score and save to player win table
void get_player_win_table_max(void)
{
	char *msg = "white win!";

	reset(player_win_table);	

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[j][i] == 0)
			{
				left(i, j, 1, 2, msg, L);
				right(i, j, 1, 2, msg, L);
				up(i, j, 1, 2, msg, L);
				down(i, j, 1, 2, msg, L);
				left_up(i, j, 1, 2, msg, L);
				right_up(i, j, 1, 2, msg, L);
				left_down(i, j, 1, 2, msg, L);
				right_down(i, j, 1, 2, msg, L);
			}
			player_win_table[j][i] = left_score + right_score + up_score + down_score + 
				left_up_score + right_up_score + left_down_score + right_down_score;
		}
	}
	player_max = player_win_table[0][0];
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(player_max < player_win_table[j][i])
			{
				player_max_x = j;
				player_max_y = i;
				player_max = player_win_table[j][i];
			}
		}
	}
	return;
}

//judge computer chess a pos score and save to player win table
void get_computer_win_table_max(void)
{
	char *msg = "black win!";

	reset(computer_win_table);

	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(pos_flag[j][i] == 0)
			{
				left(i, j, 2, 1, msg, F);
				right(i, j, 2, 1, msg, F);
				up(i, j, 2, 1, msg, F);
				down(i, j, 2, 1, msg, F);
				left_up(i, j, 2, 1, msg, F);
				right_up(i, j, 2, 1, msg, F);
				left_down(i, j, 2, 1, msg, F);
				right_down(i, j, 2, 1, msg, F);
			}
			computer_win_table[j][i] = left_score + right_score + up_score + down_score + 
				left_up_score + right_up_score + left_down_score + right_down_score;
		}
	}
	computer_max = computer_win_table[0][0];
	for(i = 0; i < NUM; i++)
	{
		for(j = 0; j < NUM; j++)
		{
			if(computer_max < computer_win_table[j][i])
			{
				computer_max_x = j;
				computer_max_y = i;
				computer_max = computer_win_table[j][i];
			}
		}
	}
	return;
}
