
# include "iGraphics.h"


void iDraw()
{
	
	iClear();
}

void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	
}

int main()
{
	
	iInitialize(400, 400, "demooo");
	return 0;
}	