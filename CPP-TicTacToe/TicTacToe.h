#pragma once
#include <iostream>
#include "Game.h"

class TicTacToe : public Game
{

private:
	char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
	char currentPlayer = 'X';
	int moves = 0;
public:

	virtual ~TicTacToe(){}

	virtual void TakeTurn();

	virtual bool IsGameOver() const; 

	virtual void Display() const;

};