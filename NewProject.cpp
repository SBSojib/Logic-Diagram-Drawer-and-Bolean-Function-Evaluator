# include "iGraphics.h"

int ball_x, ball_y,z;
int dx, dy;
int a,b,c,d,e,f,g,h,i,j;
int *k,*l,*m,*n,*o,*p,*q,*r,*s,*t;

void iDraw()
{

	iClear();

	iSetColor(2, 255, 2);
	iFilledCircle(ball_x, ball_y, 20);
	iSetColor(100,255,100);
	iLine(a,b,c,d);
	iSetColor(255, 2, 2);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			ball_x=mx;
			ball_y=my;
			o=&ball_x;
			p=&ball_y;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		a=mx;
		b=my;
		c=mx-100;
		d=my;
		k=&a;
		l=&b;
		m=&c;
		n=&d;
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void ballChange(){
	//*o += dx;
	*p += dy;

	if(ball_x > 1200 || ball_x < 0)dx = -dx;
	if(ball_y > 700 || ball_y < 0)dy = -dy;
	if((*o >! *k && *o <! *m) && (ball_y ==*l))
	{
		dy=-dy;
	}
}

int main()
{
	iSetTimer(1, ballChange);
	dx = 5;
	dy = 5;
	iInitialize(1200, 700, "BallDemo");
	return 0;
}	