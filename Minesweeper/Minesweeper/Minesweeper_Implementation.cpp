#include "minesweeper_header.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void minesweeper::player_input(int x, int y, char rea[][10], char disp[][10])
{
str:
	cout << "Press 1 to open the box, Press 2 to flag the box, Press 3 to unflag the box, Press 4 to highlight a box." << endl;
	int input;
	cout << "Input : ";
	cin >> input;
	switch (input)
	{
	case 1:
		openbox(x, y, rea, disp);
		break;
	case 2:
		flagbox(x, y, rea, disp);
		break;
	case 3:
		unflagbox(x, y, rea, disp);
		break;
	case 4:
		highlight(x, y, rea, disp);
		break;
	default:
		cout << "Invalid entry.\n";
		goto str;
	}
}
int minesweeper::wincon(char rea[][10], char disp[][10])
{
	int counter = 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (disp[i][j] == 'B' && rea[i][j] == '*')
			{
				counter--;
			}
		}
	}
	if (counter == 0)
	{
		return counter;
	}

}
int minesweeper::losecon(char rea[][10], char disp[][10])
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (disp[i][j] == '*')
			{
				return 2;
			}
		}
	}
}
void minesweeper::highlight(int x, int y, char rea[][10], char disp[][10])
{
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (disp[i][j] == 'H' && x >= 0 && x <= 9 && y >= 0 && y <= 9)
			{
				disp[i][j] = 'x';
			}
		}
	}
	cout << "Please select the field you would like to highlight." << endl;
	cout << "Enter the column number : ";
	cin >> y;
	cout << "Enter the row Number : ";
	cin >> x;
	if (disp[x][y] == 'x' && x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		disp[x][y] = 'H';
	}

}
void minesweeper::flagbox(int x, int y, char rea[][10], char disp[][10])
{
str:

	cout << "Enter the column number : ";
	cin >> y;
	cout << "Enter the row Number : ";
	cin >> x;
	if (tracker == 10)
	{
		cout << "You have placed too many flags, please go back and remove one before placing another.\n";
		player_input(x, y, rea, disp);
	}
	else if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && (disp[x][y] == 'x' || disp[x][y] == 'H'))
	{
		tracker++;
		disp[x][y] = 'B';
	}
	else
	{
		if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && disp[x][y] == 'B')
		{
			cout << "This box is already flagged!\n";
			goto str;
		}
		else
		{
			if (x < 0 || x > 9 || y < 0 || y > 9)
			{
				cout << "Location entered is not within the boards parameters.\n";
				goto str;
			}
		}
	}

}
void minesweeper::unflagbox(int x, int y, char rea[][10], char disp[][10])
{
st:
	cout << "Enter the column number : ";
	cin >> y;
	cout << "Enter the row Number : ";
	cin >> x;
	if (tracker == 0)
	{
		cout << "There are no flags placed, please go back and place one before removing another.\n";
		player_input(x, y, rea, disp);
	}

	else if (disp[x][y] == 'B' && x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		tracker--;
		disp[x][y] = 'x';
	}
	else if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && disp[x][y] != 'B')
	{
		cout << "This box has not been flagged yet.\n";
		goto st;
	}
	else
	{
		if (x < 0 || x > 9 || y < 0 || y > 9)
		{
			cout << "Location entered is not within the boards parameters.\n";
			goto st;
		}
	}
}
void minesweeper::flagcounter(char disp[][10], char rea[][10])
{
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (rea[i][j] == '*')
			{
				flag++;
			}
		}
	}
	cout << endl << "Total number of flags : " << flag << endl;
	cout << "Total number of mines : " << flag << endl;
	int flag_holder = 0;
	flag_holder = flag;
	int bomb_check = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (disp[i][j] == 'B')
			{
				flag_holder--;
				bomb_check++;
				if (flag_holder < 0 || bomb_check > 10)
				{
					cout << "You have placed to many flags, please go back and remove one before placing another.\n";
				}
			}

		}
	}
	cout << endl << "Number of current flags remaining : " << flag_holder << endl;
	cout << "Number of potentially marked mines : " << bomb_check << endl;
}
char minesweeper::revealmine(char disp[][10], char rea[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (rea[i][j] == '*')
			{
				disp[i][j] = rea[i][j];
			}
		}
	}
	printanyboard(disp);
	return 0;
}
void minesweeper::revealwhenx(int x, int y, char rea[][10], char disp[][10])
{
	if (rea[x][y] != '*' && (disp[x][y] == 'x' || disp[x][y] == 'H') && x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		disp[x][y] = rea[x][y];
		if (rea[x][y] == 'x')
		{
			disp[x][y] = '0';
			revealwhenx(x, y + 1, rea, disp);
			revealwhenx(x, y - 1, rea, disp);
			revealwhenx(x + 1, y, rea, disp);
			revealwhenx(x - 1, y, rea, disp);
			revealwhenx(x - 1, y - 1, rea, disp);
			revealwhenx(x + 1, y + 1, rea, disp);
			revealwhenx(x + 1, y - 1, rea, disp);
			revealwhenx(x - 1, y + 1, rea, disp);
		}
	}
}
void minesweeper::openbox(int x, int y, char rea[][10], char disp[][10])
{
str:
	cout << "Enter the column number : ";
	cin >> y;
	cout << "Enter the row Number : ";
	cin >> x;
	if (rea[x][y] != 'x' && disp[x][y] != 'B' && rea[x][y] != '*' && (disp[x][y] == 'x' || disp[x][y] == 'H') && x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		disp[x][y] = rea[x][y];
	}
	else
	{
		if (rea[x][y] == 'x' && (disp[x][y] == 'x' || disp[x][y] == 'H') && x >= 0 && x <= 9 && y >= 0 && y <= 9)
		{
			revealwhenx(x, y, rea, disp);
		}
		else
		{
			if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && rea[x][y] == '*' && disp[x][y] == 'x')
			{
				scorecalc(rea, disp);
				revealmine(disp, rea);
				cout << "You hit a mine!" << endl << "GAME OVER!" << endl;
				cout << "Your score was : " << score << endl;
				losecon(rea, disp);
			}
			else
			{
				if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && disp[x][y] != 'x' && disp[x][y] != 'B')
				{
					cout << "The box has already been selected, please make a new selection.\n";
					goto str;
				}
				else
				{
					if (x < 0 || x > 9 || y < 0 || y > 9)
					{
						cout << "Location entered is not within the boards parameters.\n";
						goto str;
					}
					else
					{
						if (disp[x][y] == 'B' && x >= 0 && x <= 9 && y >= 0 && y <= 9)
						{
							cout << "The box is already flagged and can not be selected.\n";
							goto str;
						}
						else
						{
							if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && disp[x][y] != 'B' && disp[x][y] != 'x')
							{
								cout << "The box is already selected.\n";
								goto str;
							}
						}
					}
				}
			}
		}
	}
}

char minesweeper::initrealboard(char y[][10])
{
	/*cout << "Please enter the size of your board. (X)\n";
	int size = 0;
	cin >> size;*/
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			y[i][j] = 'x';
		}
	}
	return 0;
}
char minesweeper::initdisplayboard(char t[][10])
{
	//cout << "Please enter the size of your board. (Y)\n";
	//int size = 0;
	//cin >> size;
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			t[i][j] = 'x';
		}
	}return 0;
}
char minesweeper::printanyboard(char y[][10])
{
	cout << endl;
	cout << endl;
	for (int i = 9; i >= 0; i--)
	{
		cout << setw(30);
		cout << i << " | ";
		for (int j = 0; j <= 9; j++)
		{
			cout << y[i][j] << " ";
		}
		cout << endl;

	}
	cout << setw(53) << "---------------------\n";
	for (int i = 0; i < 1; i++)
	{
		cout << setw(34);
		for (int j = 0; j <= 9; j++)
		{
			cout << j << " ";
		}
	}
	cout << endl;
	return 0;
}
void minesweeper::hints(int x, int y, char arr[][10])
{
	if (arr[x][y] != '*' && x >= 0 && x <= 9 && y >= 0 && y <= 9)
	{
		int count = 0;
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x][y + 1] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x][y - 1] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x - 1][y] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x - 1][y + 1] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x - 1][y - 1] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x + 1][y] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x + 1][y + 1] == !'*')
					count++;
			}
		}
		if (x > 0)
		{
			if (y > 0)
			{
				if (arr[x + 1][y - 1] == !'*')
					count++;
			}
		}
		if (arr[x][y] == !'*' || arr[x][y] == 'x')
		{
			arr[x][y] = '1';
		}
		else if (arr[x][y] == 'C' || arr[x][y] == 'D')
		{
			arr[x][y] = '*';
		}
		else
		{
			arr[x][y] = arr[x][y] + 1;
		}
	}
}
void minesweeper::minegenerator(char t[][10])
{
	int counter = 0;
	int a = 0, b = 0, y = 0;
	int p = 0;
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 19;
	}
	srand(time(0));
	cout << "Before while loop ";
	while (counter <= 9 && y < 20)
	{
	strt:
		a = rand() % 10;
		b = rand() % 10;
		if (p > 0)
		{
			for (int i = 0; i < 20; i += 2)
			{
				if (a == arr[i] && b == arr[i + 1])
				{
					goto strt;
				}
			}
		}
		arr[y] = a;
		arr[y + 1] = b;
		t[a][b] = '*';

		cout << " calling hints with x : " << a << " y : " << b;
		hints(a, b + 1, t);
		hints(a, b - 1, t);
		hints(a - 1, b, t);
		hints(a - 1, b + 1, t);
		hints(a - 1, b - 1, t);
		hints(a + 1, b, t);
		hints(a + 1, b + 1, t);
		hints(a + 1, b - 1, t);
		counter++;
		y += 2;
		p++;
	}
}
int minesweeper::scorecalc(char rea[][10], char disp[][10])
{
	score = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (rea[i][j] == '*' && disp[i][j] == '*' || disp[i][j] == 'B' && rea[i][j] == '*')
			{
				score += 10;
			}
		}
	}
	return score;
}