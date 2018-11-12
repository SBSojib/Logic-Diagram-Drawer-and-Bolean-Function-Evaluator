# include "iGraphics.h"
int xbar, ybar, xball, yball, xball2, yball2, dxbar, dybar, dxball, dyball, startflag, flag1, flag2, flag3, endflag, countpoint, countlife, gameoverflag;
char showpoint[3];
char showlife[3];

void BallChange()
{
	if(endflag==0)
	{
		yball -= dyball;
		if(yball<=0)
		{
			yball=700;
			xball=(rand())%1100;
			countlife--;
			if(countlife<=0)
			{
				endflag=1;
				gameoverflag=1;
			}
		}
		if((xball<=xbar+150 && xball>=xbar) && (yball<=30))
		{
			yball=700;
			xball=(rand())%1100;
			
			countpoint++;

		}
	}
}
void BallChange2()
{
	if(endflag==0)
	{
		yball2 -= dyball;
		if(yball2<=0)
		{
			yball2=700;
			xball2=(rand())%1100;
			countlife--;
			if(countlife<=0)
			{
				endflag=1;
				gameoverflag=1;
			}
		}
		if((xball2<=xbar+100 && xball2>=xbar) && (yball2<=30))
		{
			yball2=700;
			xball2=(rand())%1100;
			
			countpoint++;

		}
	}
}

void Collapse()
{
	endflag=1;
}
void iDraw()
{
	iClear();
	iSetColor(0,255,0);
	iFilledRectangle(xbar,ybar,150,20);
	iText(10,680, "Press h, m, e for Heard, Mediup, Easy level");
	iText(10,660, "Right Click for the bar to go Right and Left Click for left");
	iText(10,640, "Press x for exit");
	itoa(countpoint,showpoint,10);
	itoa(countlife,showlife,10);
	iText(1040,680,"Point:");
	iText(1100,680,showpoint);
	iText(970,660,"Life remaining:");
	iText(1100,660,showlife);
	if(gameoverflag==1)
	{
		iText(550,350,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,300,"Score  ",GLUT_BITMAP_HELVETICA_18);
		iText(550,250,showpoint,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(endflag==1)
	{
		iText(550,350,"GAME END", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,300,"Score  ",GLUT_BITMAP_HELVETICA_18);
		iText(550,250,showpoint,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iSetColor(0,0,255);
	iFilledCircle(xball, yball, 10);
	iFilledCircle(xball2, yball2, 10);

}
void iMouse(int button, int state, int mx, int my)
{

}

void iMouseMove(int mx, int my)
{

}
void iKeyboard(unsigned char key)
{
	if(key=='x')
	{
		exit(0);
	}
	if(key=='p')
	{
		iPauseTimer(0);
	}
	if(key=='r')
	{
		iResumeTimer(0);
	}

	if(startflag==0)
	{
		startflag=1;
		if(endflag==0)
		{
			if(key=='h' && flag1==0)
			{
				iSetTimer(10,BallChange);
				iSetTimer(10,BallChange2);
				flag1=1;
			}
			if(key=='m' && flag2==0)
			{
				iSetTimer(30,BallChange);
				iSetTimer(30,BallChange2);
				flag2=1;
			}
			if(key=='e' && flag3==0)
			{
				iSetTimer(50,BallChange);
				iSetTimer(50,BallChange2);
				flag3=1;
			}
		}
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_RIGHT && xbar<=1100)
	{
		if(flag1==1) xbar += dxbar*3;
		if(flag2==1) xbar += dxbar*2;
		if(flag3==1) xbar += dxbar;
	}
	if(key==GLUT_KEY_LEFT && xbar>=0)
	{
		if(flag1==1) xbar -= dxbar*3;
		if(flag2==1) xbar -= dxbar*2;
		if(flag3==1) xbar -= dxbar;
	}
}

int main()
{
	dxbar=25;
	xbar=600;
	ybar=10;
	dyball=10;
	xball=(rand())%1100;
	xball2=(rand())%1100;
	yball=710;
	yball2=1010;
	startflag=0;
	flag1=0;
	flag2=0;
	flag3=0;
	endflag=0;
	gameoverflag=0;
	countpoint=0;
	countlife=10;
	iSetTimer(1000*120,Collapse);
	iShowBMP(0,0,"venom.bmp");
	iInitialize(1200,700,"New Windiow");
	return 0;
}