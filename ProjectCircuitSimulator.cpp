
# include "iGraphics.h"
# include "Variable.h"
# include "Macro.h"
# include "Function.h"
# include "Function2.h"
# include "UnusedFunctions.h"



void iDraw()
{
	
	MenuBar();
	if(startingIndicator>0)
	{
		Drawing();
	}
	if(outputIndicator==1)
	{
		FunctionOutput(boleanFunction, boleanFunctionVariableVaule);
	}
}
int main()
{
	index=0;
	index2=0;
	colorRed = 0;
	colorGreen = 0;
	colorBlue = 255;
	inputFunctionCordinateX=260;
	inputFunctionCordinateY=690;
	inputValueCordinateX=910;
	inputValueCordinateY=690;
	
	iInitialize(1500, 800, "Logic Diagram");
	return 0;
}	


