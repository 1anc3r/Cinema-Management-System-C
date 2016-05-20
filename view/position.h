//============================================================================
// Name        : position.h
// Author      : lancer
// Version     : 2.1
// Copyright   : made by lancer
// Description : Cinema Management System in C, Ansi-style
//============================================================================

void Position(int x,int y);

void Position(int x,int y)
{
	COORD pos = { x - 1, y - 1 };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
