#include<stdio.h>

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(menuIdicator==menuFirstPage && mx>=650 && mx<=800 && my>=500 && my<=540)
		{
			menuIdicator=menuSecondPage;
			screenClearIndicator=menuSecondPage;
			
		}
		if(menuIdicator==menuFirstPage && mx>=650 && mx<=800 && my>=400 && my<=440)
		{
			exit(0);
		}
		if(menuIdicator==menuFirstPage && mx>=650 && mx<=800 && my>=300 && my<=340)
		{
			menuIdicator=menuThirdPage;
		}
		if(menuIdicator==menuSecondPage && mx>=1430 && mx<=1500 && my>=5 && my<=40)
		{
			menuIdicator=menuFirstPage;
			//iClear();
		}
		if(menuIdicator==menuSecondPage && mx>=1250 && mx<=1350 && my>=670 && my<=740)
		{
			outputIndicator=menuSecondPage;
		}
		if(menuIdicator==menuSecondPage && mx>=250 && mx<=850 && my>=670 && my<=740)
		{
			boxColorIndicator=functionBoxColor;
		}
		if(menuIdicator==menuSecondPage && mx>=900 && mx<=1200 && my>=670 && my<=740)
		{
			boxColorIndicator=valueBoxColor;
		}
		if(menuIdicator==menuSecondPage && mx>=1250 && mx<=1350 && my>=670 && my<=740)
		{
			boxColorIndicator=getResultBoxColor;
		}
		if(menuIdicator==menuSecondPage && mx>=1380 && mx<=1480 && my>=670 && my<=740)
		{
			boxColorIndicator=resultBoxColor;
		}
		if(menuIdicator==menuSecondPage)
		{
			if(drawingIndicator>0)
			{
				startingIndicator=1;
			}
			if(mx>=20 && mx<=190 && my>=700 && my<=780)
			{
				drawingIndicator=putNOtGate;
			}
			if(mx>=20 && mx<=190 && my>=600 && my<=680)
			{
				drawingIndicator=putAndGate;
			}
			if(mx>=20 && mx<=190 && my>=500 && my<=580)
			{
				drawingIndicator=putOrGate;
			}
			if(mx>=20 && mx<=190 && my>=400 && my<=480)
			{
				drawingIndicator=putLine;
			}
			if(mx>=20 && mx<=190 && my>=300 && my<=380)
			{
				drawingIndicator=putInputBox;
			}
			if(mx>=20 && mx<=190 && my>=200 && my<=280)
			{
				drawingIndicator=putValue;
			}
			if(drawingIndicator==putNOtGate)
			{
				notGateX=mx;
				notGateY=my;
			}
			if(drawingIndicator==putAndGate)
			{
				andGateX=mx;
				andGateY=my;
			}
			if(drawingIndicator==putOrGate)
			{
				orGateX=mx;
				orGateY=my;
			}
			if(drawingIndicator==putLine)
			{
				if(lineInputIndicator==0 && mx>200)
				{
					lineFirstX=mx;
					lineFirstY=my;
					lineInputIndicator=1;
				}
			}
			if(drawingIndicator==putInputBox)
			{
				valueInputX=mx;
				valueInputY=my;
				tester3=0;
			}
			if(drawingIndicator==putValue)
			{
				binaryValueInputX=mx;
				binaryValueInputY=my;
			}
		}
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if(menuIdicator==menuSecondPage)
		{
			if(drawingIndicator==putLine)
			{
				if(lineInputIndicator==1)
				{
					lineSecondX=mx;
					lineSecondY=my;
					lineInputIndicator=0;
				}
			}
		}
	}
}
void iKeyboard(unsigned char key)
{
	if(key == 'A')
	{
		boleanFunction[index]='A';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"A", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'B')
	{
		boleanFunction[index]='B';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"B", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'C')
	{
		boleanFunction[index]='C';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"C", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'D')
	{
		boleanFunction[index]='D';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"D", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'E')
	{
		boleanFunction[index]='E';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"E", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'F')
	{
		boleanFunction[index]='F';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"F", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'G')
	{
		boleanFunction[index]='G';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"G", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'H')
	{
		boleanFunction[index]='H';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"H", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'I')
	{
		boleanFunction[index]='I';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"I", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'J')
	{
		boleanFunction[index]='J';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"J", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'K')
	{
		boleanFunction[index]='K';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"K", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'L')
	{
		boleanFunction[index]='L';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"L", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'M')
	{
		boleanFunction[index]='M';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"M", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'N')
	{
		boleanFunction[index]='N';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"N", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'O')
	{
		boleanFunction[index]='O';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"O", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'P')
	{
		boleanFunction[index]='P';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"P", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'Q')
	{
		boleanFunction[index]='Q';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"Q", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'R')
	{
		boleanFunction[index]='R';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"R", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'S')
	{
		boleanFunction[index]='S';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"S", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'T')
	{
		boleanFunction[index]='T';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"T", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'U')
	{
		boleanFunction[index]='U';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"U", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'V')
	{
		boleanFunction[index]='V';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"V", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'W')
	{
		boleanFunction[index]='W';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"W", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'X')
	{
		boleanFunction[index]='X';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"X", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'Y')
	{
		boleanFunction[index]='Y';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"Y", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == 'Z')
	{
		boleanFunction[index]='Z';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"Z", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == '+')
	{
		boleanFunction[index]='+';
		index++;
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"+", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=20;
	}
	if(key == '.')
	{
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,".", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=10;
	}
	if(key == '(')
	{
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,"(", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=10;
	}
	if(key == ')')
	{
		iSetColor(255,255,255);
		iText(inputFunctionCordinateX, inputFunctionCordinateY,")", GLUT_BITMAP_TIMES_ROMAN_24);
		inputFunctionCordinateX+=10;
	}
	
	if(key == '1')
	{
		boleanFunctionVariableVaule[index2]=1;
		index2++;
		iSetColor(255,255,255);
		if(binaryValueInputX>200 && binaryValueInputY<650)
		{
			iText(binaryValueInputX, binaryValueInputY,"1");
		}
		iText(inputValueCordinateX, inputValueCordinateY, "1", GLUT_BITMAP_TIMES_ROMAN_24);
		inputValueCordinateX+=30;
		
	}
	if(key == '0')
	{
		boleanFunctionVariableVaule[index2]=0;
		index2++;
		iSetColor(255,255,255);
		if(binaryValueInputX>200 && binaryValueInputY<650)
		{
			iText(binaryValueInputX, binaryValueInputY,"0");
		}
		iText(inputValueCordinateX, inputValueCordinateY, "0", GLUT_BITMAP_TIMES_ROMAN_24);
		inputValueCordinateX+=30;
		
	}
	
}