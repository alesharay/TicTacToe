#include "Board.h"

Board::Board()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			stateOfGame[i][j]='*';
		}
	}

	for(int k=0; k<2; k++)
	{
		if(k==0)
			player[k]='X';
		else
			player[k]='O';
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
