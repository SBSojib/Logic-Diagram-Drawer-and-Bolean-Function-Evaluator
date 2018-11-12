#include<stdio.h>

void DrawIconGate();
void MenuBar();
void Drawing();
void DrawNotGate(int notGateX, int notGateY);
void DrawAndGate(int andGateX, int andGateY);
void DrawOrGate(int orGateX, int orGateY);
void FunctionOutput(char s[100], int a[100]);
void Drawing()
{
	if(drawingIndicator==putNOtGate)
	{
		if(notGateX>200 && notGateY<650)
		{
			DrawNotGate(notGateX, notGateY);
		}
	}
	if(drawingIndicator==putAndGate)
	{
		if(andGateX>200 && andGateY<650)
		{
			DrawAndGate(andGateX, andGateY);
		}
	}
	if(drawingIndicator==putOrGate)
	{
		if(orGateX>200 && orGateY<650)
		{
			DrawOrGate(orGateX, orGateY);
		}
	}
	if(drawingIndicator==putLine)
	{
		if(lineInputIndicator==0)
		{
			//iLine(lineFirstX, lineFirstY,lineSecondX,lineSecondY);
			int temporaryvariable1= lineFirstX-lineSecondX;
			int temporaryvariable2= lineFirstY-lineSecondY;
			if(temporaryvariable1<0) temporaryvariable1*=-1;
			if(temporaryvariable2<0) temporaryvariable2*=-1;
			if(temporaryvariable1>=temporaryvariable2 && lineFirstX>200 && lineSecondX>200 && lineFirstY<650 && lineSecondY<650)
			{
				iLine(lineFirstX, lineFirstY,lineSecondX,lineFirstY);
			}
			else if( lineFirstX>200 && lineSecondX>200 && lineFirstY<650 && lineSecondY<650)
			{
				iLine(lineFirstX, lineFirstY,lineFirstX,lineSecondY);
			}
		}
		
	}
	if(drawingIndicator==putInputBox)
	{
		
		if(valueInputX>200 && valueInputY<650)
		{
			iRectangle(valueInputX, valueInputY-10, 20,20);
		}
		if(tester3==0 && inputCordinateStorage!=NULL)
		{
			fprintf(inputCordinateStorage,"%d %d\n",valueInputX, valueInputY);
			tester3=1;
		}
		//fclose(inputCordinateStorage);
	}
	
}
void MenuBar()
{
	if(menuIdicator==menuFirstPage || menuIdicator==menuSecondPage || menuIdicator==menuThirdPage)
	{
		//iClear();
		//iShowBMP(0,0,"1.bmp");
		if(menuIdicator==menuSecondPage || menuIdicator==menuThirdPage)
		{
			colorRed=0; colorGreen=0; colorBlue=0;
		}
		else
		{
			colorRed = 0; colorGreen = 0; colorBlue = 255;
		}
		iSetColor(colorRed,colorGreen,colorBlue);
		iFilledRectangle(650,500,150,40);
		iFilledRectangle(650,400,150,40);
		iFilledRectangle(650,300,150,40);
		if(menuIdicator==menuSecondPage || menuIdicator==menuThirdPage)
		{
			colorRed=0; colorGreen=0; colorBlue=0;
		}
		else
		{
			colorRed = 255; colorGreen = 255; colorBlue = 255;
		}
		iSetColor(colorRed,colorGreen,colorBlue);
		iText(670, 510,"Start", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 410,"Exit", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 310,"Instructions", GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	
	if(menuIdicator==menuFirstPage || menuIdicator==menuThirdPage || menuIdicator==menuSecondPage)
	{
		if(menuIdicator==menuSecondPage || menuIdicator==menuFirstPage)
		{
			colorRed=0; colorGreen=0; colorBlue=0;
		}
		else
		{
			colorRed = 255; colorGreen = 255; colorBlue = 255;
		}
		iSetColor(colorRed,colorGreen,colorBlue);
		iText(900,500, "1. Select a tool and left click on the drawing position.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900,450, "2. For line left click on the first place and right on second.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900,400, "3. Insert the variable value serially as they appear.", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(menuIdicator==menuSecondPage)
	{
		if(tester==menuFirstPage)
		{
			//iClear();
			inputCordinateStorage= fopen("inputCordinateStorage.txt","w");
			tester=1;

		}
		//iShowBMP(0,0,"33.bmp");
			if(menuIdicator==0)
			{
				iSetColor(0,0,0);
			}
			else
			{
				iSetColor(255,255,255);
			}
			iText(250,750, "Insert Your Function", GLUT_BITMAP_TIMES_ROMAN_24);
			if(menuIdicator==0)
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=0;
			}
			else if(boxColorIndicator==functionBoxColor)
			{
				boxColorRed=255; boxColorGreen=255; boxColorBlue=255;
			}
			else
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=255;
			}
			iSetColor(boxColorRed, boxColorGreen, boxColorBlue);
			iRectangle(250,670,600,70);
			iSetColor(255,255,255);
			iText(900,750, "Insert Variable Value", GLUT_BITMAP_TIMES_ROMAN_24);
			if(menuIdicator==0)
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=0;
			}
			else if(boxColorIndicator==valueBoxColor)
			{
				boxColorRed=255; boxColorGreen=255; boxColorBlue=255;
			}
			else
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=255;
			}
			iSetColor(boxColorRed, boxColorGreen, boxColorBlue);
			iRectangle(900,670,300,70);
			if(menuIdicator==0)
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=0;
			}
			else if(boxColorIndicator==getResultBoxColor)
			{
				boxColorRed=255; boxColorGreen=255; boxColorBlue=255;
			}
			else
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=255;
			}
			iSetColor(boxColorRed, boxColorGreen, boxColorBlue);
			iFilledRectangle(1250,670,100,70);
			if(menuIdicator==0)
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=0;
			}
			else if(boxColorIndicator==resultBoxColor)
			{
				boxColorRed=255; boxColorGreen=255; boxColorBlue=255;
			}
			else
			{
				boxColorRed=0; boxColorGreen=0; boxColorBlue=255;
			}
			iSetColor(boxColorRed, boxColorGreen, boxColorBlue);
			iRectangle(1380,670,100,70);
			iSetColor(255,255,255);
			iText(1260,710, "Get", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1260,680, "Result", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1380,750, "Output", GLUT_BITMAP_TIMES_ROMAN_24);
		
		
			iSetColor(0,0,255);
			iFilledRectangle(200,0,10,800);
			iFilledRectangle(0,0,10,850);
			iFilledRectangle(0,5,200,10);
			iFilledRectangle(0,790,200,10);
			iFilledRectangle(210,650,1300,5);
			iFilledRectangle(1490,650,10,150);
			iFilledRectangle(210,790,1300,10);
			iSetColor(0,0,255);
			iFilledRectangle(1430,5,70,35);
			iSetColor(0,255,0);
			iText(1440,15,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
			if(drawingIndicator==putNOtGate)
			{
				notRed=0;notGreen=0;notBlue=0;
			}
			else 
			{
				notRed=255;notGreen=255;notBlue=255;
			}
			iSetColor(notRed, notGreen, notBlue);
			iFilledRectangle(20,700,170,80);
			if(drawingIndicator==putAndGate)
			{
				andRed=0;andGreen=0;andBlue=0;
			}
			else 
			{
				andRed=255;andGreen=255;andBlue=255;
			}
			iSetColor(andRed, andGreen, andBlue);
			iFilledRectangle(20,600,170,80);
			if(drawingIndicator==putOrGate)
			{
				orRed=0;orGreen=0;orBlue=0;
			}
			else 
			{
				orRed=255;orGreen=255;orBlue=255;
			}
			iSetColor(orRed, orGreen, orBlue);
			iFilledRectangle(20,500,170,80);
			if(drawingIndicator==putLine)
			{
				lineRed=0;lineGreen=0;lineBlue=0;
			}
			else 
			{
				lineRed=255;lineGreen=255;lineBlue=255;
			}
			iSetColor(lineRed, lineGreen, lineBlue);
			iFilledRectangle(20,400,170,80);
			if(drawingIndicator==putInputBox)
			{
				inputRed=0;inputGreen=0;inputBlue=0;
			}
			else 
			{
				inputRed=255;inputGreen=255;inputBlue=255;
			}
			iSetColor(inputRed, inputGreen, inputBlue);
			iFilledRectangle(20,300,170,80);
			if(drawingIndicator==putValue)
			{
				valueRed=0;valueGreen=0;valueBlue=0;
			}
			else 
			{
				valueRed=255;valueGreen=255;valueBlue=255;
			}
			iSetColor(valueRed, valueGreen, valueBlue);
			iFilledRectangle(20,200,170,80);
			DrawIconGate();
	}
		
}


void DrawIconGate()
{
	iSetColor(255,255,255);
	for(int index=220; index<1500; index+=20)
	{
		for(int index2=10; index2<650; index2+=20)
		{
			iFilledCircle(index, index2, 1);
		}
	}
	iSetColor(0,0,255);
	iLine(40,740,80,740);
	iLine(80,760,120,740);
	iLine(80,720,120,740);
	iLine(80,760,80,720);
	iCircle(125,740,5);
	iLine(130,740,170,740);

	iLine(40,650,80,650);
	iLine(40,630,80,630);
	iLine(80,620,80,660);
	iHalfCircle(80,640,20);
	iLine(100,640,140,640);

	iLine(40,550,80,550);
	iLine(40,530,80,530);
	iOneFourthUpperEllipse(75,540,40,20);
	iOneFourthDownEllipse(75,540,40,20);
	iHalfEllipse(75,540,10,20);
	iLine(115,540,155,540);

	iLine(40,440,160,440);

	iRectangle(60,320, 80,40);
	iText(70, 330,"Input",GLUT_BITMAP_TIMES_ROMAN_24);

	iRectangle(60,220, 80,40);
	iText(70, 230,"Value",GLUT_BITMAP_TIMES_ROMAN_24);
}
void DrawNotGate(int notGateX, int notGateY)
{
	iLine(notGateX, notGateY-20, notGateX, notGateY+20);
	iLine(notGateX, notGateY-20, notGateX+40, notGateY);
	iLine(notGateX, notGateY+20, notGateX+40, notGateY);
	iCircle(notGateX+45, notGateY,5);
}
void DrawAndGate(int andGateX, int andGateY)
{
	iLine(andGateX, andGateY-20, andGateX, andGateY+20);
	iHalfCircle(andGateX, andGateY,20);
}
void DrawOrGate(int orGateX, int orGateY)
{
	iOneFourthUpperEllipse(orGateX, orGateY, 40,20);
	iOneFourthDownEllipse(orGateX, orGateY, 40,20);
	iHalfEllipse(orGateX, orGateY, 10,20);
}
void FunctionOutput(char s[100], int c[100])
{
    int indes,indes2,a=1,b[200],d=0,e,k=1;
    int ar[10];
    int result=0;
    int value[100]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    for(indes=1;indes<strlen(s);indes++)
    {
        if(s[indes]!='+')
        {
            int f=0;
            for(indes2=indes-1;indes2>=0;indes2--)
            {
                if(s[indes]==s[indes2])
                {
                    f=5;
                    break;
                }
            }
            if(f!=5)
            {
                a++;
            }
        }
    }
    indes2=0;
    for(indes=0;indes<strlen(s);indes++)
    {
        if(s[indes]=='+')
        {
            d++;
            ar[indes2]=indes;
            indes2++;
        }
    }
    for(indes=1;indes<strlen(s);indes++)
    {
        if(s[indes]!='+')
        {
            b[s[0]]=c[0];
            int f=0;
            for(indes2=indes-1;indes2>=0;indes2--)
            {
                if(s[indes]==s[indes2])
                {
                    f=5;
                    break;
                }
            }
            if(f!=5)
            {
                b[s[indes]]=c[k];
                k++;
            }
        }
    }
    indes=0;
    k=0;
    b['+']=5;
    for(indes2=0;indes2<=d;indes2++)
    {
        for(; indes<strlen(s);indes++)
        {
            if(s[indes]=='+')
            {
                break;
            }
            value[k]=value[k]&b[s[indes]];
        }
        indes++;
        k++;

    }
    for(indes=0;indes<=d;indes++)
    {
        result=result | value[indes];
    }
	itoa(result, functionOutputValue, 10);
	iSetColor(255,255,255);
	iText(1420, 690, functionOutputValue, GLUT_BITMAP_TIMES_ROMAN_24);
}
