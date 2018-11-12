
# include "iGraphics.h"

int andGateX, andGateY, notGateX, notGateY, orGateX, orGateY, notGateInputLineLength, notGateOutputLineLength, orGateInputLineLength, orGateOutputLineLength;
int andGateInputLineLength, andGateOutputLineLength, notGateHeight, notGateLength, notGateCircleRadius, andGateHalfCircleRadius, orGateLength, orGateHeight;
int orGateThirdEllipseHeight, orGateThirdEllipseLength, orGateSecondInputX, functionFirstInputX, functionFirstInputY1, functionFirstInputY2;
int functionLiteralDifference, functionGateHeightDifference, andGateHeight, menuIdicator=0, menuIdicator2=0, colorRed, colorGreen, colorBlue;
int letterAsci=0, inputLetterX=220, inputLetterY=470;
char logicFunction[100];

void DrawNotGate(int notGateX, int notGateY)
{
	iLine(notGateX, notGateY, notGateX+notGateInputLineLength, notGateY);
	iLine(notGateX+notGateInputLineLength, notGateY+notGateHeight/2, notGateX+notGateInputLineLength+notGateLength, notGateY);
	iLine(notGateX+notGateInputLineLength, notGateY-notGateHeight/2, notGateX+notGateInputLineLength+notGateLength, notGateY);
	iLine(notGateX+notGateInputLineLength, notGateY+notGateHeight/2, notGateX+notGateInputLineLength, notGateY-notGateHeight/2);
	iLine(notGateX+notGateInputLineLength+notGateLength+notGateCircleRadius*2, notGateY, notGateX+notGateInputLineLength+notGateLength+notGateOutputLineLength, notGateY);
	iCircle(notGateX+notGateInputLineLength+notGateLength+notGateCircleRadius, notGateY, notGateCircleRadius);
}
void DrawAndGate(double andGateX, double andGateY, double andGateSecondInputX, int slices=1000)
{
	double index, PI=acosl(-1), indexChange, startingX, startingY, variableX, variableY;
	indexChange = 2*PI/slices;
	andGateHalfCircleRadius = andGateHeight/2;
	variableX = functionLiteralDifference+andGateInputLineLength+andGateHalfCircleRadius;
	variableY= andGateY;
	iLine(andGateX, andGateY+andGateHalfCircleRadius/2, functionLiteralDifference+andGateInputLineLength, andGateY+andGateHalfCircleRadius/2);
	iLine(andGateSecondInputX, andGateY-andGateHalfCircleRadius/2, functionLiteralDifference+andGateInputLineLength, andGateY-andGateHalfCircleRadius/2);
	iLine(functionLiteralDifference+andGateInputLineLength+andGateHalfCircleRadius, andGateY, functionLiteralDifference+andGateInputLineLength+andGateHalfCircleRadius+andGateOutputLineLength, andGateY);
	glBegin(GL_POLYGON);
	for(index = 0; index <= 2*PI; index+=indexChange)
	{
		startingX = functionLiteralDifference+andGateInputLineLength + andGateHalfCircleRadius * cos(index);
		startingY = andGateY + andGateHalfCircleRadius * sin(index);
		if(variableX>=functionLiteralDifference+andGateInputLineLength){
			glVertex2f(variableX, variableY);}
		variableX = startingX;
		variableY = startingY;
	}
	glEnd();
}
void DrawOrGate(double orGateX, double orGateY, double orGateSecondInputX, int slices=100)
{
	double index, PI=acosl(-1), indexChange, startingX, startingY, variableX, variableY;
	indexChange = 2*PI/slices;
	variableX = orGateX+orGateInputLineLength+orGateLength;
	variableY = orGateY;
	iLine(orGateX, orGateY+orGateHeight/2, functionLiteralDifference+orGateInputLineLength+orGateThirdEllipseLength, orGateY+orGateHeight/2);
	iLine(orGateSecondInputX, orGateY-orGateHeight/2, functionLiteralDifference+orGateInputLineLength+orGateThirdEllipseLength, orGateY-orGateHeight/2);
	iLine(functionLiteralDifference+orGateInputLineLength+orGateLength, orGateY, functionLiteralDifference+orGateInputLineLength+orGateLength+orGateOutputLineLength, orGateY);
	
	for(index = 0; index <= 2*PI; index+=indexChange)
	{
		startingX = functionLiteralDifference+orGateInputLineLength + orGateLength * cos(index);
		startingY = orGateY + orGateHeight * sin(index);
		if(variableX>=functionLiteralDifference+orGateInputLineLength && variableY>=orGateY){
			iLine(variableX, variableY, startingX, startingY);
		}
		variableX = startingX;
		variableY = startingY;
	}//1st ellipse & if yp included then yp>=orGatey 1/4 upper portion
	
	for(index = 0; index <= 2*PI; index+=indexChange)
	{
		startingX = functionLiteralDifference+orGateInputLineLength + orGateLength * cos(index);
		startingY = orGateY + orGateHeight * sin(index);
		if(variableX>=functionLiteralDifference+orGateInputLineLength && variableY<=orGateY){
			iLine(variableX, variableY, startingX, startingY);
		}
		variableX = startingX;
		variableY = startingY;
	}//lower portion 2nd ellipse
	
	for(index = 0; index <= 2*PI; index+=indexChange)
	{
		startingX = functionLiteralDifference+orGateInputLineLength + orGateThirdEllipseLength * cos(index);
		startingY = orGateY + orGateThirdEllipseHeight * sin(index);
		if(variableX>=functionLiteralDifference+orGateInputLineLength){
			iLine(variableX, variableY, startingX, startingY);
		}
		variableX = startingX;
		variableY = startingY;
	
	}
	
}
void DrawSimpleDiagram(char logicFunction[])
{
	int index1, index2, literalNumber=0, literalX[100]={0};
	for(index1=0;index1<strlen(logicFunction);index1++)
    {
		if(logicFunction[index1]>=65 && logicFunction[index1]<=90)
        {
            int indicator=0;
			for(index2=index1-1;index2>=0;index2--)
            {
				if(logicFunction[index2]==logicFunction[index1])
                {
                    indicator=5;
                }
            }
            if(indicator!=5)
            {
				literalNumber++;
				literalX[logicFunction[index1]] = functionFirstInputX;
				iLine(functionFirstInputX, functionFirstInputY1, functionFirstInputX, functionFirstInputY2);
				functionFirstInputX += functionLiteralDifference;
            }
        }
    }
	andGateInputLineLength =  (literalNumber+1) * functionLiteralDifference;
	orGateInputLineLength =  (literalNumber+1) * functionLiteralDifference;
	notGateInputLineLength =  (literalNumber+1) * functionLiteralDifference;

	for(index1=0;index1<literalNumber;index1++)
	{
		
	}
	for(index1=0,index2=0;index1<strlen(logicFunction);index1+=1,index2+=1)
	{
		if(logicFunction[index1]=='+')
		{
			DrawOrGate(literalX[logicFunction[index1-1]], functionFirstInputY1-20, literalX[logicFunction[index1+1]]);
		}
		if(logicFunction[index1]=='.')
		{
			DrawAndGate(literalX[logicFunction[index1-1]], functionFirstInputY1-20, literalX[logicFunction[index1+1]]);
		}
		if(logicFunction[index1]=='`')
		{
			DrawNotGate(literalX[logicFunction[index1-1]], functionFirstInputY1-20);
		}
		functionFirstInputY1 -= 50;
	}
}
void MenuBar()
{
	if(menuIdicator==0)
	{
		iClear();
		iSetColor(200,0,100);
		iFilledRectangle(0,0,1500,842);
		iSetColor(colorRed,colorGreen,colorBlue);
		iFilledRectangle(650,500,150,40);
		iSetColor(0,255,0);
		iText(670, 510,"Start", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(colorRed,colorGreen,colorBlue);
		iFilledRectangle(650,400,150,40);
		iSetColor(0,255,0);
		iText(670, 410,"Exit", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(colorRed,colorGreen,colorBlue);
		iFilledRectangle(650,300,150,40);
		iSetColor(0,255,0);
		iText(670, 310,"About", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(menuIdicator==1)
	{
		iShowBMP(0,0,"33.bmp");
		iSetColor(0,255,0);
		iText(200, 550, "Insert Your Function:",GLUT_BITMAP_TIMES_ROMAN_24); 
		iSetColor(0,0,255);
		iFilledRectangle(200,450,400,50);
		iFilledRectangle(200,300,70,35);
		iSetColor(0,255,0);
		iText(210,310,"Back",GLUT_BITMAP_TIMES_ROMAN_24);

	}
}
void InputSection2()
{
	if(letterAsci==65)
	{
		iSetColor(0,255,0);
		iText(inputLetterX, inputLetterY, "A", GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	if(letterAsci==66)
	{
		iSetColor(0,255,0);
		iText(inputLetterX, inputLetterY, "B", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(letterAsci==67)
	{
		iSetColor(0,255,0);
		iText(inputLetterX, inputLetterY, "C", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(letterAsci==68)
	{
		iSetColor(0,255,0);
		iText(inputLetterX, inputLetterY, "D", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
void InputSection()
{
	scanf("%s",logicFunction);
	iSetColor(0,255,0);
	DrawSimpleDiagram(logicFunction);
}
		
void iDraw()
{
	iClear();
	if(menuIdicator2==0)
	{
		MenuBar();
	}
	if(menuIdicator2==1)
	{
		iShowBMP(0,0,"33.bmp");
		//InputSection();
	}
	InputSection2();
	functionFirstInputX = 50; 
	functionFirstInputY1 = 600;
	functionFirstInputY2 = 20;
	iSetColor(0,128,100);
	
	//iShowBMP(0,0,"22.bmp");
	
}

void iMouseMove(int mx, int my)
{
	/*iSetColor(0,255,0);
	iFilledCircle(mx, my,10);
	if(menuIdicator==0 && mx>=650 && mx<=800 && my>=500 && my<=540)
	{
		iClear();
		menuIdicator2=1;
	}
	if(menuIdicator==0 && mx>=650 && mx<=800 && my>=400 && my<=440)
	{
		exit(0);
	}*/
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(menuIdicator==0 && mx>=650 && mx<=800 && my>=500 && my<=540)
		{
			iClear();
			menuIdicator=1;
			//menuIdicator2=1;
		}
		if(menuIdicator==0 && mx>=650 && mx<=800 && my>=400 && my<=440)
		{
			exit(0);
		}
		if(menuIdicator==0 && mx>=650 && mx<=800 && my>=300 && my<=340)
		{
			iFilledCircle(mx,my,100);
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(menuIdicator==0 && mx>=650 && mx<=800 && my>=300 && my<=340)
		{
			exit(0);
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(menuIdicator==0 && mx>=650 && mx<=800 && my>=300 && my<=340)
		{
			colorRed = 0;
			colorGreen = 255;
			colorBlue = 0;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(menuIdicator==1 && mx>=200 && mx<=270 && my>=300 && my<=330)
		{
			menuIdicator=0;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	
}
void iKeyboard(unsigned char key)
{
	if(key == 'A' && menuIdicator==1)
	{
		letterAsci=65;
		inputLetterX+=15;
	}
	if(key == 'B' && menuIdicator==1)
	{
		letterAsci=66;
		inputLetterX+=15;
	}
	if(key == 'C' && menuIdicator==1)
	{
		letterAsci=67;
		inputLetterX+=15;
	}
	if(key == 'D' && menuIdicator==1)
	{
		letterAsci=68;
		inputLetterX+=15;
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
	notGateInputLineLength = 100;
	notGateOutputLineLength = 100;
	orGateInputLineLength = 100;
	orGateOutputLineLength = 100;
	andGateInputLineLength = 100;
	andGateOutputLineLength = 100;
	notGateHeight = 30*2;
	notGateLength = 30*2;
	notGateCircleRadius = 5*2;
	andGateHalfCircleRadius = 15*2;
	andGateHeight = 30*2;
	orGateLength = 30*2;
	orGateHeight = 15*2;
	orGateThirdEllipseHeight = 15*2;
	orGateThirdEllipseLength = 10*2;
	
	functionLiteralDifference = 40*2;
	functionGateHeightDifference = 50*2;
	colorRed = 0;
	colorGreen = 55;
	colorBlue = 220;
	//inputLetterX = 220;
	//inputLetterY = 470;
	
	iInitialize(1500, 842, "Logic Diagram");
	return 0;
}	