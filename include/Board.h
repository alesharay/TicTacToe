#pragma once

#include<iostream>
#include"catch.hpp"
using namespace std;

class Board
{
private:
	// private data members
	char stateOfGame[3][3];
	//char player[2];

	// private functions
	void sampleBoardDisplay() const;
	void updatedBoardDisplay();
	bool stateOfGameUpdate(int, int, int);

public:
	Board();
	void display();
	bool move(int, int);
};
