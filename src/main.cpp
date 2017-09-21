#include<iostream>
using namespace std;

#include"Board.h"

int main(void)
{
	Board gameBoard;

	gameBoard.display();

	gameBoard.move(5, 1);

	gameBoard.display();

	gameBoard.move(7, 2);

	gameBoard.display();

	return 0;
}
