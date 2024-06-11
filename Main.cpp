/************************************************************************************************
	Name:		CoachLDEW
	Date:		06.11.2024
	Purpose:	This program will draw a playing field in the console.  Whatever game that will 
				be developed can be played with a boundary such as this.  I will also be using 3
				other functions, WindowSize(), HideCursor and GoToXY to help demonstrate since I
				am using these functions to help develop a simple space shooter in the console.
				When you compile this code you will get warnings due to using a int value in a 
				char.  That is fine.  It will still work.  It's just a truncation warning.
*************************************************************************************************/

#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library contains the function to control the cursor position



using namespace std;


//Function that changes the window size
void WindowSize(int x, int y)
{
	HWND console = GetConsoleWindow();		//Get the Console Window and put it in a variable of the Window Handle type
	RECT ConsoleRect;						//Rect Structure defines a Rectangle (The Window)
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}



//Function to hide the cursor
void HideCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window
	//Data Structure that controls the apearance of the cursor.  It has two attributes dwSize and bVisible
	CONSOLE_CURSOR_INFO cursor;
	//This attribute changes the size of the cursor. Here it is set at 100%
	cursor.dwSize = 100;
	//This Boolean attribute sets the cursor to visible or invisible.  False is invisible
	cursor.bVisible = false;

	//Manipulates the characteristics it takes two parameters.  The ID of the console window and a data structure that
	//handles the appearance of the cursor
	//You have to pass the cursor variable by reference so that it can make changes to the actual object
	SetConsoleCursorInfo(hCon, &cursor);
}



void GoToXY(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window

	COORD coord;								//Variable of type COORD that holds the X and Y position
	coord.X = x;
	coord.Y = y;

	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor.	
	SetConsoleCursorPosition(hCon, coord);
}



void DrawBorders()
{
	//Border Dimensions (Playing Field Size)
	int width = 65;
	int height = 41;

	char tAndB = 205;			//Character code for top and bottom borders
	char lAndR = 186;			//Character code for left and right borders
	char topLeft = 201;			//Character code for top left corner
	char botLeft = 200;			//Character code for bottom left corner
	char topRight = 187;		//Character code for top right corner
	char botRight = 188;		//Character code for bottom right corner

	//Top & Bottom Borders
	for (int i = 2; i < width - 3; i++)
	{
		GoToXY(i, 3);
		cout << tAndB;

		GoToXY(i, height - 2);
		cout << tAndB;
	}

	//Left & Right Borders
	for (int j = 4; j < height - 2; j++)
	{
		GoToXY(2, j);
		cout << lAndR;

		GoToXY(61, j);
		cout << lAndR;
	}

	//Corners
	//Top Left
	GoToXY(2, 3);
	cout << topLeft;

	//Bottom Left
	GoToXY(2, height - 2);
	cout << botLeft;

	//Top Right
	GoToXY(61, 3);
	cout << topRight;

	//Bottom Right
	GoToXY(61, height - 2);
	cout << botRight;
}


int main()
{
	//Changes console window to 500x700
	WindowSize(500, 700);
	//Hides the curso
	HideCursor();
	//Draws the borders
	DrawBorders();

	return 0;
}