#include <iostream>
#include<vector>
using namespace std;
vector<vector<char>> board(3, vector<char>(3, ' '));
void outputboard()
{

	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << board[i][0] << "|" << board[i][1] << "|" << board[i][2];
		if (i != 2)
			cout << "\n-+-+-";
		cout << endl;
	}
	cout << endl;
}
char checkval()
{
	for (int i = 0; i < 3; i++)
		if ((board[i][0] != ' ' && board[i][0] + board[i][1] == 2 * board[i][2])
			|| (board[0][i] != ' ' && board[0][i] + board[1][i] == 2 * board[2][i]))
			return board[i][0];
	if ((board[0][0] != ' ' && board[0][0] + board[1][1] == 2 * board[2][2])
		|| (board[1][1] != ' ' && board[0][2] + board[1][1] == 2 * board[2][0]))
		return board[0][0];

	return 0;
}
int main()
{
	int number, turn = 1, x, y, draw = 0;
	cout << "Game started: \n";
	while (true)
	{
		outputboard();
		char a = checkval();

		if (a != 0)
		{
			cout << "Player: " << (turn == 2 ? 1 : 2) << " WINS!!!" << endl;
			return 0;
		}
		else if (draw == 9)
		{
			cout << "Draw! \n";
			return 0;
		}
		else
		{
			while (false)
			{
			renter:
				cout << "Try Again!..\n";
				if (turn == 1)turn = 2; else turn = 1;
			}

			if (turn == 1 && (turn = 2))
				cout << "Player 1 Enter num from 1 to 9: ... ";
			else if (turn == 2 && (turn = 1))
				cout << "Player 2 Enter num from 1 to 9: ... ";

			cin >> number;
			--number, x = number / 3, y = number % 3;
			if (board[x][y] != ' ')
				goto renter;
			else
				board[x][y] = ((turn == 2) ? 'X' : 'O'), draw++;

		}
	}
}
