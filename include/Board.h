#pragma once

#include<iostream>
#include"catch.hpp"
#include<assert.h>
using namespace std;

class Board
{
private:
	/******** private data members ********/

	char m_stateOfGame[3][3];
	int m_moves;

	/******** private functions ********/
	
	/** Displays the sample board with the number placements
		for choices to be made.
		@post	Will display the complete status board.
	*/
	void displaySampleBoard() const;

	/**	Displays the updated board after the player chooses 
		their next move.
		@post	Will display updated board with player marker 
			  	in the chosen box
	*/
	void displayUpdatedBoard();

	/**	Updates the state of game with the chosen box from
		the current player.
		@pre	Both row and col will be between 0-2, 
			 	playerNum will be 0 or 1.
		@post	True will be returned if successfully updated;
				Otherwise, false will be returned.
		@param row			(integer) Row of the players move.
		@param col			(integer) Column of the players move.
		@param playerNum	(integer) Number that indicates which 
									  player is choosing a box.
		@return				True if gameboard was updated;
							otherwise, returns false.
	*/
	bool stateOfGameUpdated(int row, int col, int playerNum);

public:
	
	//	Constructor
	Board();

	/** Displays both game boards
		@post	Will display the sample board and the updated 
				game board with the player's next move.
	*/
	void displayBoard();
	
	/** Allows player to choose the box they would like to put 
		their character in.
		@pre	Choice will be a value between 1-9, 
				playerNum will be 0 or 1.
		@post	True Will be returned if a box was chosen successfully;
				Otherwise, will return false.
		@param choice		(integer) Number that corresponds to the
								  box the player would like to choose.
		@param playerNum	(integer) Number that that indicates which
									  player is choosing a box.
	*/
	bool boxChosen(int choice, int playerNum);
	
	
	/**	Indicates if a player has won the game
		@post 	Will return true if there is a winner, false otherwise.
		@return	True, if there is a winner; false otherwise.	
	*/
	bool gameWon();
	
	/**	Indicate if the game ends in a draw.
		@post Will return true if the game is a draw, will return false
			  if not.
		@return True, if the game ends in a draw; false otherwise.
	*/
	bool gameDraw();
};
