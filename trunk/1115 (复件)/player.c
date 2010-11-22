#include "common.h"

//people play chess
void player(int *fd_mouse, int *player_flag)
{

	int x_old, y_old;
	int i, j, k, n = 0;
	int buf[1024];
	int x, y;

	if(buf_mouse[0] & 0x1)
	{
		memset(buf_mouse, 0, 8);
		move_mouse(fd_mouse);
		if((buf_mouse[0] & 0x1) == 0)
		{
			x_old = cx;
			y_old = cy;

			click_pos();
			if((cx > X - 20) && (cy > Y - 20) && (cx < X + NUM * SPACE - 30) && (cy < Y + NUM * SPACE - 30) &&
					(pos_flag[(cx-X) / SPACE][(cy-Y) / SPACE] == 0))
			{
				fb_white_point(cx, cy);
				fb_num(chess_num++, cx, cy, 0x0);
				pos_flag[(cx - X) / SPACE][(cy - Y) / SPACE] = 1;
				*player_flag = 0;
			}
			cx = x_old;
			cy = y_old;
		}
	}

	return;
}
