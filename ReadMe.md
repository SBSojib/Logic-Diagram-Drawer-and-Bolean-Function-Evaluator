========================================================================
# Summary:
This Project is for evaluating Bolean Functions output and drawing logic diagram. It can evaluate the output of a Bolean function from the variables given value. When the user insert the function and its variable value and click on the output button, it will show the output value of the given function. And the second feature is a drawing tool. From the given list of different gates and some other tools the user can draw any logic diagram what he/she wants. This is a simple drawing tool. Here the basic logic gates have been used.
# Feature:
There are two features in this project. They are listed below:
-	Evaluation of Bolean Functions output.
-	Drawing logic diagram.

# Installation:
- At first navigate to the main page of the repository
- Under the repository name, click Clone or download.
- In the Clone with HTTPs section, click to copy the clone URL for the repository.
- Open .
- Change the current working directory to the location where you want the cloned directory to be made.
- Run the code. It is recommended to use Microsoft Visual Studio 2012 as the code was created using this tool.
# Documentation:
The total code is divided into 6 parts, 1 main file which is in .cpp format and 5 header files.

####	Logic Diagram Drawer and Bolean Function Evaluator.cpp:

It’s the main file which is in .cpp format. Here other header files are included. There are total 2 functions here.
main(): It initialize the window and call the idraw() function again and again.
 iDraw() : It is called by the main function and it calls the other function.
#### Vaiable.h:
It’s a header file. It only contains the variables of the functions. All the variables that are used in this project are declared here.
#### 	Macro.h:
Here only marcos are defined. All macros are defined here.

#### 	Function.h:
It contains all the functions that have been written.  There are total 7 functions.
Drawing(): This function is to draw the gates of logic diagram. Whenever a gate or any other tools needs to draw, this function is called and then it calls some other functions which is need to be draw specifically and that called function draw the gate and other tools.

MenuBar(): This function is to draw the menu and the main page. It has mainly two parts. First one draw the menu page and second one draw the main page diagram and call another function which draw the iconic gate and tools here.

DrawIconGate(): In calling it, it draws all the icon gate and tools that can be seen in the second page. It calls just calls all the tools drawing functions.

DrawNotGate(): Whenever this function is called, it draws a NOT gate.

DrawAndGate(): This function draws a AND gate.

DrawOrGate(): It draws a OR gate.

FunctionOutput(…): This fuctions takes the Bolean given fuction and its variable value as parameter and return the output of the particular Bolean Function for the given value.


#### 	Function2.h:
This header file contains two functions in total.

iMouse(…): It’s a default function of iGraphics. It works whenever the mouse is clicked. It’s a very much necessary tools for the project. The drawing side is totally controlled by this functions with the click.
iKeyboard(): It’s also a default function of iGraphics. It is called when the Keyboard is hit. Here it is used for taking the function as input and it’s variable value. It is also used for plugging the value in the logic diagram.

#### UnusedFunction.h:

iMouseMove(): It’s a iGraphics function which is called whenever the mouse is clicked and moved.

iSpecialKeyboard(): It’s a iGraphics function too. It’s is called when specila key is hit.
