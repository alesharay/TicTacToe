#include "Board.h"

Board::Board(): moves(0)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			stateOfGame[i][j]='*';
		}
	}
}

void Board::sampleBoardDisplay() const
{
	cout << "\n7 | 8 | 9\n"
		 << "---------\n"
		 << "4 | 5 | 6\n"
		 << "---------\n"
		 << "1 | 2 | 3\n" << endl;
}

#include<string>
void Board::updatedBoardDisplay()
{
	cout << "\n\n\n";

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if((j+1)%3)
			{
				cout << stateOfGame[i][j] << " | ";
			}
			else
			{
				cout << stateOfGame[i][j];
			}
		}

		if((i+1)%3)
		{
			cout << endl << string(9, '-') << endl;
		}
	}
	cout << endl;
}

bool Board::stateOfGameUpdate(int row, int col, int playerNum)
{
	if(stateOfGame[row][col] != '*')
		return false;

	playerNum=playerNum-1;

	if(playerNum == 0)
	{
		stateOfGame[row][col] = 'X';
		return true;
	}
	else
	{
		stateOfGame[row][col] = 'O';
		return true;
	}
}

bool Board::move(int choice, int playerNum)
{

	bool validOption;
	if(choice < 1 || choice > 9)
		validOption = false;
	else
	{
		switch(choice)
		{
			case 1:
				validOption = stateOfGameUpdate(2,0,playerNum);
				break;
			case 2:
				validOption = stateOfGameUpdate(2,1,playerNum);
				break;
			case 3:
				validOption = stateOfGameUpdate(2,2,playerNum);
				break;
			case 4:
				validOption = stateOfGameUpdate(1,0,playerNum);
				break;
			case 5:
				validOption = stateOfGameUpdate(1,1,playerNum);
				break;
			case 6:
				validOption = stateOfGameUpdate(1,2,playerNum);
				break;
			case 7:
				validOption = stateOfGameUpdate(0,0,playerNum);
				break;
			case 8:
				validOption = stateOfGameUpdate(0,1,playerNum);
				break;
			case 9:
				validOption = stateOfGameUpdate(0,2,playerNum);
				break;
			default:
				validOption = false;
				break;
		}
	}
	
	if(validOption)
		moves++;
	return validOption;
}

bool Board::gameWon()
{
	bool won = ((stateOfGame[0][0] == stateOfGame[0][1]) && 
				(stateOfGame[0][1] == stateOfGame[0][2]) &&
				(stateOfGame[0][0] != '*')) ||
			   ((stateOfGame[1][0] == stateOfGame[1][1]) && 
				(stateOfGame[1][1] == stateOfGame[1][2]) &&
				(stateOfGame[1][0] != '*'))	||
			   ((stateOfGame[2][0] == stateOfGame[2][1]) && 
				(stateOfGame[2][1] == stateOfGame[2][2]) &&
				(stateOfGame[2][0] != '*')) ||
			   ((stateOfGame[0][0] == stateOfGame[1][1]) && 
				(stateOfGame[1][1] == stateOfGame[2][2]) &&
				(stateOfGame[0][0] != '*')) ||
			   ((stateOfGame[2][0] == stateOfGame[1][1]) && 
				(stateOfGame[1][1] == stateOfGame[0][2]) &&
				(stateOfGame[2][0] != '*')) ||
			   ((stateOfGame[0][0] == stateOfGame[1][0]) && 
				(stateOfGame[1][0] == stateOfGame[2][0]) &&
				(stateOfGame[0][0] != '*')) ||
			   ((stateOfGame[0][1] == stateOfGame[1][1]) && 
				(stateOfGame[1][1] == stateOfGame[2][1]) &&
				(stateOfGame[0][1] != '*')) ||
			   ((stateOfGame[0][2] == stateOfGame[1][2]) && 
				(stateOfGame[1][2] == stateOfGame[2][2]) &&
				(stateOfGame[0][2] != '*'));
		
	return won;	
}

bool Board::gameDraw()
{
	return moves > 8 && !gameWon() ? true : false;
}

void Board::display()
{
	sampleBoardDisplay();
	updatedBoardDisplay();
}
