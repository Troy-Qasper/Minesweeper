#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "minesweeper_header.h"
using namespace std;
int main()
{
start:
	minesweeper minesweeper_game;
	char displayboard[10][10];
	char realboard[10][10];
	int x_axis = 0;
	int y_axis = 0;
	int score = 0;
	bool t = true;
	int win = 0;
	int loss = 0;
	minesweeper_game.initdisplayboard(displayboard);
	minesweeper_game.initrealboard(realboard);
	minesweeper_game.minegenerator(realboard);
	while (t)
	{
		minesweeper_game.flagcounter(displayboard, realboard);
		minesweeper_game.printanyboard(realboard);
		minesweeper_game.printanyboard(displayboard);
		minesweeper_game.player_input(x_axis, y_axis, realboard, displayboard);
		loss = minesweeper_game.losecon(realboard, displayboard);
		if (win == minesweeper_game.wincon(realboard, displayboard) || loss == 2)
		{
			t = false;
		}
	}
	if (win == minesweeper_game.wincon(realboard, displayboard))
	{
		cout << "You win!\n";
		cout << "Your score is : " << minesweeper_game.scorecalc(realboard, displayboard) << endl;
	}

	cout << "Would you like to play again?\n";
	cout << "Enter your choice (Y/N): ";
	char play_again;
	cin >> play_again;
	switch (play_again)
	{
	case 'Y':
		goto start;
	case 'y':
		goto start;
	case 'N':
	{
		cout << "Thank you for playing Minesweeper!\n";
		exit(0);
	}
	case 'n':
	{
		cout << "Thank you for playing Minesweeper!\n";
		exit(0);
	}
	default:
		cout << "Invalid selection/entry.\n";
		break;
	}
}