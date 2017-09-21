#pragma once

#include<iostream>
#include"catch.hpp"
using namespace std;

class Board
{
private:
	// private data members
	char stateOfGame[3][3];
	int moves;

	// private functions
	void sampleBoardDisplay() const;
	void updatedBoardDisplay();
	bool stateOfGameUpdate(int, int, int);

public:
	Board();
	void display();
	bool move(int, int);
	bool gameWon();
	bool gameDraw();
};
