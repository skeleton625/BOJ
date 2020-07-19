#include <iostream>
#define MIN(a, b) ( a < b ? a : b )
using namespace std;

char input[50][50];

int solve(int x, int y)
{
	int bChange = 0, wChange = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			// È¦¼ö
			if (i & 1)
			{
				// È¦¼ö
				if (j & 1)
				{
					if (input[i][j] != 'B') ++bChange;
					if (input[i][j] != 'W') ++wChange;
				}
				// Â¦¼ö 
				else
				{
					if (input[i][j] != 'W') ++bChange;
					if (input[i][j] != 'B') ++wChange;
				}
			}
			// Â¦¼ö
			else
			{
				// È¦¼ö
				if (j & 1)
				{
					if (input[i][j] != 'W') ++bChange;
					if (input[i][j] != 'B') ++wChange;
				}
				// Â¦¼ö 
				else
				{
					if (input[i][j] != 'B') ++bChange;
					if (input[i][j] != 'W') ++wChange;
				}
			}
		}
	}

	return MIN(bChange, wChange);
}

int main()
{
	iostream::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++)
		cin >> input[i];

	int res = 64;
	for (int i = 0; i <= x - 8; i++)
	{
		for (int j = 0; j <= y - 8; j++)
			res = MIN(res, solve(i, j));
	}

	cout << res;
	return 0;
}