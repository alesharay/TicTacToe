#include<iostream>
using namespace std;

#include"Board.h"

int main(void)
{
	bool again = true;

	do
	{
		Board gameBoard;
		gameBoard.display();

		int player = 1;
		int moves = 1;

		while(!gameBoard.gameWon() && !gameBoard.gameDraw())
		{
				cout << "\n\nPlayer " << player << ", please choose an option: ";
				int option;
				cin >> option;

				bool validMove = gameBoard.move(option, player);
				gameBoard.display();

				while(!validMove)
				{
						cout << "\nThat is an invalid option, please try again: ";
						cin >> option;
						validMove = gameBoard.move(option, player);
						gameBoard.display();
						cout << endl;
				}

				if(!gameBoard.gameWon())
				{
						if(player == 1)
								player++;
						else
								player--;
				}
		}

		if(gameBoard.gameDraw())
				cout << "\nIt's a cat's game!" << endl;
		else
				cout << "\nCongratulations! Player " << player << ", you are the winner!" << endl;
	
		
		cout << "\nWould you like to play again? (1-yes, 0-no): ";
		cin >> again;

	}while(again);

	return 0;
}
