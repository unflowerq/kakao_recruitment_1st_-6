#include <iostream>
#include <string>

using namespace std;

#define test test2

int main()
{
	string test1[4] = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	string test2[6] = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };

	bool delete_flag = false;

	int n, m;

	cin >> n >> m;

	char **board = new char*[n];
	for (int i = 0; i < n; i++)
		board[i] = new char[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = test[i][j];

	bool **bool_board = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		bool_board[i] = new bool[m];
		memset(bool_board[i], false, sizeof(bool)*m);
	}

	do
	{
		delete_flag = false;

		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1])
				{
					bool_board[i][j] = true;
					bool_board[i + 1][j] = true;
					bool_board[i][j + 1] = true;
					bool_board[i + 1][j + 1] = true;
					delete_flag = true;
				}
			}
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (bool_board[i + 1][j] == true)
				{
					board[i + 1][j] = board[i][j];
					board[i][j] = ' ';
					bool_board[i + 1][j] = false;
					bool_board[i][j] = true;
				}
			}
		}

	} while (delete_flag);

	int blank_count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == ' ')
				blank_count++;
		}
	}

	cout << blank_count << endl;

	for (int i = 0; i < n; i++)
		delete[] board[i];
	delete[] board;

	for (int i = 0; i < n; i++)
		delete[] bool_board[i];
	delete[] bool_board;

	return 0;
}