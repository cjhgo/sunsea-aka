#include <stdlib.h>
#include <graphics.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>
#define Enter 7181
#define ESC 283
#define UP 18432
#define DOWN 20480
#define LEFT 19200
#define RIGHT 19712
#ifdef __cplusplus
#define __CPPARGS ...
#else
#define __CPPARGS
#endif
void interrupt (*oldhandler)(__CPPARGS);
void interrupt newhandler(__CPPARGS);
void SetTimer(void interrupt (*IntProc)(__CPPARGS));
void KillTimer(void);
void Initgra(void);
void TheFirstBlock(void);
void DrawMap(void);
void Initsnake(void);
void Initfood(void);
void Snake_Headmv(void);
void Flag(int,int,int,int);
void GameOver(void);
void Snake_Bodymv(void);
void Snake_Bodyadd(void);
void PrntScore(void);
void Timer(void);
void Win(void);
void TheSecondBlock(void);
void Food(void);
void Dsnkorfd(int,int,int);
void Delay(int);
struct Snake
{int x;int y;int color;}Snk[12];
struct Food
{int x;int y;int color;}Fd;
int flag1=1,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,
    checkx,checky,num,key=0,Times,Score,Hscore,Snkspeed,TimerCounter,TureorFalse;
char Sco[2],Time[6];
void main()
{ Initgra();
	SetTimer(newhandler);
	TheFirstBlock();
	while(1)
	{DrawMap();
		Snake_Headmv();
		GameOver();
		Snake_Bodymv();
		Snake_Bodyadd();
		PrntScore();
		Timer();
		Win();
		if(key==ESC)
			break;
		if(key==Enter)
		{cleardevice();
			TheFirstBlock();
		}
		TheSecondBlock();
		Food();
		Delay(Snkspeed);
	}
	closegraph();
	KillTimer();
}
void interrupt newhandler(__CPPARGS)
{
	TimerCounter++;
	oldhandler();
}
void SetTimer(void interrupt (*IntProc)(__CPPARGS)) 
{
	oldhandler=getvect(0x1c);
	disable();
	setvect(0x1c,IntProc);
	enable();
}

void KillTimer() 
{
	disable();
	setvect(0x1c,oldhandler);
	enable();
}
void Initgra()
{int gd=DETECT,gm;
	initgraph(&gd,&gm,"d:\\tc");
}
void TheFirstBlock()
{setcolor(11);
	settextstyle(0,0,4);
	outtextxy(100,220,"The First Block");
loop:key=bioskey(0);
     if(key==Enter)
     {cleardevice();
	     Initsnake();
	     Initfood();
	     Score=0;
	     Hscore=1;
	     Snkspeed=10;
	     num=2;
	     Times=0;
	     key=0;
	     TureorFalse=1;
	     TimerCounter=0;
	     Time[0]='0';Time[1]='0';Time[2]=':';Time[3]='1';Time[4]='0';Time[5]='\0';
     }
     else if(key==ESC) cleardevice();
     else goto loop;
}
void DrawMap()
{line(10,10,470,10);
	line(470,10,470,470);
	line(470,470,10,470);
	line(10,470,10,10);
	line(480,20,620,20);
	line(620,20,620,460);
	line(620,460,480,460);
	line(480,460,480,20);
}
void Initsnake()
{randomize();
	num=2;
	Snk[0].x=random(440);
	Snk[0].x=Snk[0].x-Snk[0].x%20+50;
	Snk[0].y=random(440);
	Snk[0].y=Snk[0].y-Snk[0].y%20+50;
	Snk[0].color=4;
	Snk[1].x=Snk[0].x;
	Snk[1].y=Snk[0].y+20;
	Snk[1].color=4;
}
void Initfood()
{randomize();
	Fd.x=random(440);
	Fd.x=Fd.x-Fd.x%20+30;
	Fd.y=random(440);
	Fd.y=Fd.y-Fd.y%20+30;
	Fd.color=random(14)+1;
}
void Snake_Headmv()
{if(bioskey(1))
	{key=bioskey(0);
		switch(key)
		{case UP:Flag(1,0,0,0);break;
		case DOWN:Flag(0,1,0,0);break;
		case LEFT:Flag(0,0,1,0);break;
		case RIGHT:Flag(0,0,0,1);break; 
		default:break;
		}
	}
	if(flag1)
	{checkx=Snk[0].x;
		checky=Snk[0].y;
		Dsnkorfd(Snk[0].x,Snk[0].y,0);
		Snk[0].y-=20;
		Dsnkorfd(Snk[0].x,Snk[0].y,Snk[0].color);
	}
	if(flag2)
	{checkx=Snk[0].x;
		checky=Snk[0].y;
		Dsnkorfd(Snk[0].x,Snk[0].y,0);
		Snk[0].y+=20;
		Dsnkorfd(Snk[0].x,Snk[0].y,Snk[0].color);
	}
	if(flag3)
	{checkx=Snk[0].x;
		checky=Snk[0].y;
		Dsnkorfd(Snk[0].x,Snk[0].y,0);
		Snk[0].x-=20;
		Dsnkorfd(Snk[0].x,Snk[0].y,Snk[0].color);
	}
	if(flag4)
	{checkx=Snk[0].x;
		checky=Snk[0].y;
		Dsnkorfd(Snk[0].x,Snk[0].y,0);
		Snk[0].x+=20;
		Dsnkorfd(Snk[0].x,Snk[0].y,Snk[0].color);
	}
}
void Flag(int a,int b,int c,int d)
{flag1=a;flag2=b;flag3=c;flag4=d;}
void GameOver()
{int i;
	if(Snk[0].x<20||Snk[0].x>460||Snk[0].y<20||Snk[0].y>460)
	{cleardevice();
		setcolor(11);
		settextstyle(0,0,4);
		outtextxy(160,220,"Game Over");
loop1:key=bioskey(0);
      if(key==Enter)
      {cleardevice();
	      TheFirstBlock();
      }
      else
	      if(key==ESC)
		      cleardevice();
	      else
		      goto loop1;
	}
	for(i=3;i<num;i++)
	{if(Snk[0].x==Snk[i].x&&Snk[0].y==Snk[i].y)
		{cleardevice();
			setcolor(11);
			settextstyle(0,0,4);
			outtextxy(160,220,"Game Over");
loop2:key=bioskey(0);
      if(key==Enter)
      {cleardevice();
	      TheFirstBlock();
      }
      else
	      if(key==ESC)
		      cleardevice();
	      else goto loop2;
		}
	}
}
void Snake_Bodymv()
{int i,s,t;
	for(i=1;i<num;i++)
	{Dsnkorfd(checkx,checky,Snk[i].color);
		Dsnkorfd(Snk[i].x,Snk[i].y,0);
		s=Snk[i].x;
		t=Snk[i].y;
		Snk[i].x=checkx;
		Snk[i].y=checky;
		checkx=s;
		checky=t;
	}
}
void Food()
{if(flag5)
	{randomize();
		Fd.x=random(440);
		Fd.x=Fd.x-Fd.x%20+30;
		Fd.y=random(440);
		Fd.y=Fd.y-Fd.y%20+30;
		Fd.color=random(14)+1;
		flag5=0;
	}
	Dsnkorfd(Fd.x,Fd.y,Fd.color);
}
void Snake_Bodyadd()
{if(Snk[0].x==Fd.x&&Snk[0].y==Fd.y)
	{if(Snk[num-1].x>Snk[num-2].x)
		{num++;
			Snk[num-1].x=Snk[num-2].x+20;
			Snk[num-1].y=Snk[num-2].y;
			Snk[num-1].color=Fd.color;
		}
		else
			if(Snk[num-1].x<Snk[num-2].x)
			{num++;
				Snk[num-1].x=Snk[num-2].x-20;
				Snk[num-1].y=Snk[num-2].y;
				Snk[num-1].color=Fd.color;
			}
			else
				if(Snk[num-1].y>Snk[num-2].y)
				{num++;
					Snk[num-1].x=Snk[num-2].x;
					Snk[num-1].y=Snk[num-2].y+20;
					Snk[num-1].color=Fd.color;
				}
				else
					if(Snk[num-1].y<Snk[num-2].y)
					{num++;
						Snk[num-1].x=Snk[num-2].x;
						Snk[num-1].y=Snk[num-2].y-20;
						Snk[num-1].color=Fd.color;
					}
		flag5=1;
		Score++;
	}
}
void PrntScore()
{if(Hscore!=Score)
	{setcolor(11);
		settextstyle(0,0,3);
		outtextxy(490,100,"SCORE");
		setcolor(2);
		setfillstyle(1,0);
		rectangle(520,140,580,180);
		floodfill(530,145,2);
		Sco[0]=(char)(Score+48);
		Sco[1]='\0';
		Hscore=Score;
		setcolor(4);
		settextstyle(0,0,3);
		outtextxy(540,150,Sco);
	}
}
void Timer()
{if(TimerCounter>18)
	{Time[4]=(char)(Time[4]-1);
		if(Time[4]<'0')
		{Time[4]='9';
			Time[3]=(char)(Time[3]-1);
		}
		if(Time[3]<'0')
		{Time[3]='5';
			Time[1]=(char)(Time[1]-1);
		}
		if(TureorFalse)
		{setcolor(11);
			settextstyle(0,0,3);
			outtextxy(490,240,"TIMER");
			setcolor(2);
			setfillstyle(1,0);
			rectangle(490,280,610,320);
			floodfill(530,300,2);
			setcolor(11);
			settextstyle(0,0,3);
			outtextxy(495,290,Time);
			TureorFalse=0;
		}
		if(Time[1]=='0'&&Time[3]=='0'&&Time[4]=='0')
		{setcolor(11);
			settextstyle(0,0,4);
			outtextxy(160,220,"Game Over");
loop:key=bioskey(0);
     if(key==Enter)
     {cleardevice();
	     TheFirstBlock();
     }
     else if(key==ESC) cleardevice();
     else goto loop;
		}
		TimerCounter=0;
		TureorFalse=1;
	}
}
void Win()
{if(Score==3)
	Times++;
	if(Times==2)
	{cleardevice();
		setcolor(11);
		settextstyle(0,0,4);
		outtextxy(160,220,"You Win");
loop:key=bioskey(0);
     if(key==Enter)
     {cleardevice();
	     TheFirstBlock();
	     key=0;
     }
     else if(key==ESC) cleardevice();
     else goto loop;
	}
}
void TheSecondBlock()
{if(Score==3)
	{cleardevice();
		setcolor(11);
		settextstyle(0,0,4);
		outtextxy(100,220,"The Second Block");
loop:key=bioskey(0);
     if(key==Enter)
     {cleardevice();
	     Initsnake();
	     Initfood();
	     Score=0;
	     Hscore=1;
	     Snkspeed=8;
	     num=2;
	     key=0;
     }
     else if(key==ESC) cleardevice();
     else goto loop;
	}
}
void Dsnkorfd(int x,int y,int color)
{setcolor(color);
	setfillstyle(1,color);
	circle(x,y,10);
	floodfill(x,y,color);
}
void Delay(int times)
{int i;
	for(i=1;i<=times;i++)
		delay(15000);
} 
