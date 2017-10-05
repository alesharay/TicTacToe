#include "Board.h"

Board::Board(): m_moves(0)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			m_stateOfGame[i][j]='*';
		}
	}
}

void Board::displaySampleBoard() const
{
	cout << "\n7 | 8 | 9\n"
		 << "---------\n"
		 << "4 | 5 | 6\n"
		 << "---------\n"
		 << "1 | 2 | 3\n" << endl;
}

#include<string>
void Board::displayUpdatedBoard()
{
	cout << "\n\n\n";

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if((j+1)%3)
			{
				cout << m_stateOfGame[i][j] << " | ";
			}
			else
			{
				cout << m_stateOfGame[i][j];
			}
		}

		if((i+1)%3)
		{
			cout << endl << string(9, '-') << endl;
		}
	}
	cout << endl;
}

bool Board::stateOfGameUpdated(int row, int col, int playerNum)
{
	if(m_stateOfGame[row][col] != '*')
		return false;

	playerNum=playerNum-1;
	
	assert(playerNum == 1 || playerNum == 2);

	if(playerNum == 0)
	{
		m_stateOfGame[row][col] = 'X';
		return true;
	}
	else
	{
		m_stateOfGame[row][col] = 'O';
		return true;
	}
}

bool Board::boxChosen(int choice, int playerNum)
{

	bool validOption;
	
	if(choice < 1 || choice > 9)
		validOption = false;
	else
	{
		switch(choice)
		{
			case 1:
				validOption = stateOfGameUpdated(2,0,playerNum);
				break;
			case 2:
				validOption = stateOfGameUpdated(2,1,playerNum);
				break;
			case 3:
				validOption = stateOfGameUpdated(2,2,playerNum);
				break;
			case 4:
				validOption = stateOfGameUpdated(1,0,playerNum);
				break;
			case 5:
				validOption = stateOfGameUpdated(1,1,playerNum);
				break;
			case 6:
				validOption = stateOfGameUpdated(1,2,playerNum);
				break;
			case 7:
				validOption = stateOfGameUpdated(0,0,playerNum);
				break;
			case 8:
				validOption = stateOfGameUpdated(0,1,playerNum);
				break;
			case 9:
				validOption = stateOfGameUpdated(0,2,playerNum);
				break;
			default:
				validOption = false;
				break;
		}
	}
	
	if(validOption)
		m_moves++;
	return validOption;
}

bool Board::gameWon()
{
	bool won = ((m_stateOfGame[0][0] == m_stateOfGame[0][1]) && 
				(m_stateOfGame[0][1] == m_stateOfGame[0][2]) &&
				(m_stateOfGame[0][0] != '*')) ||
			   ((m_stateOfGame[1][0] == m_stateOfGame[1][1]) && 
				(m_stateOfGame[1][1] == m_stateOfGame[1][2]) &&
				(m_stateOfGame[1][0] != '*'))	||
			   ((m_stateOfGame[2][0] == m_stateOfGame[2][1]) && 
				(m_stateOfGame[2][1] == m_stateOfGame[2][2]) &&
				(m_stateOfGame[2][0] != '*')) ||
			   ((m_stateOfGame[0][0] == m_stateOfGame[1][1]) && 
				(m_stateOfGame[1][1] == m_stateOfGame[2][2]) &&
				(m_stateOfGame[0][0] != '*')) ||
			   ((m_stateOfGame[2][0] == m_stateOfGame[1][1]) && 
				(m_stateOfGame[1][1] == m_stateOfGame[0][2]) &&
				(m_stateOfGame[2][0] != '*')) ||
			   ((m_stateOfGame[0][0] == m_stateOfGame[1][0]) && 
				(m_stateOfGame[1][0] == m_stateOfGame[2][0]) &&
				(m_stateOfGame[0][0] != '*')) ||
			   ((m_stateOfGame[0][1] == m_stateOfGame[1][1]) && 
				(m_stateOfGame[1][1] == m_stateOfGame[2][1]) &&
				(m_stateOfGame[0][1] != '*')) ||
			   ((m_stateOfGame[0][2] == m_stateOfGame[1][2]) && 
				(m_stateOfGame[1][2] == m_stateOfGame[2][2]) &&
				(m_stateOfGame[0][2] != '*'));
		
	return won;	
}

bool Board::gameDraw()
{
	bool draw = m_moves > 8 && !gameWon() ? true : false;
	return draw;
}

void Board::displayBoard()
{
	displaySampleBoard();
	displayUpdatedBoard();
}
