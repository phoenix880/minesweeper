#include<iostream>
using namespace std;
int main()
{
	srand(time(0));
	char sgrid[11][11]{};
	char grid[11][11]{};
	cout << "To chech the box, write after numbers V, for example: " << rand() % 9 + 1 << rand() % 9 + 1 << 'V' << endl << endl;
	for (int i = 1; i < 10; ++i)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			sgrid[i][j] = 'X';
			if (rand() % 5 == 0)
			{
				grid[i][j] = '*';
			}
			else
			{
				grid[i][j] = '0';
			}
		}
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << sgrid[i][j] << " ";
		}
		cout << ' ' << i << endl;
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			int n = 0;

			if (grid[i][j] == '*') continue;
			if (grid[i + 1][j] == '*') n++;
			if (grid[i][j + 1] == '*') n++;
			if (grid[i - 1][j] == '*') n++;
			if (grid[i][j - 1] == '*') n++;
			if (grid[i + 1][j + 1] == '*') n++;
			if (grid[i - 1][j - 1] == '*') n++;
			if (grid[i - 1][j + 1] == '*') n++;
			if (grid[i + 1][j - 1] == '*') n++;

			grid[i][j] = n + '0';
		}
	}

	char* str;
	while (1)
	{
		str = new char[4];
		cin.getline(str, 256);

		int x = str[0] - '0';
		int y = str[1] - '0';

		system("cls");

		cout << "\t\t\t\t" << x << endl;
		cout << "\t\t\t\t" << y << endl;
		for (int i = 1; i < 10; ++i)
		{
			cout << i << " ";
		}
		cout << endl << endl;
		if (str[2] == 'V')
		{
			sgrid[x][y] = 'V';
		}
		else
		{
			sgrid[x][y] = grid[x][y];
		}

		if (sgrid[x][y] != '*')
		{
			for (int i = 1; i < 10; i++)
			{
				for (int j = 1; j < 10; j++)
				{
					cout << sgrid[i][j] << " ";
				}
				cout << ' ' << i << endl;
			}
		}
		else
		{
			for (int i = 1; i < 10; i++)
			{
				for (int j = 1; j < 10; j++)
				{
					cout << grid[i][j] << " ";
				}
				cout << ' ' << i << endl;
			}
			cout << "Game Over!" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}
