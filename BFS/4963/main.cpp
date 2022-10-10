#include "iostream"
#include "queue"
#define vert pair<int, int>
#define MAX_VALUE 51
using namespace std;

int direction[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int main()
{
	int n, m;

	cin.tie(0);
	ios::sync_with_stdio(0);

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> grid[i][j];
			}
		}

		int c = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 0) continue;
				grid[i][j] = 0;
				c++;

				queue<vert> que;
				que.push({ i, j });

				while (!que.empty())
				{
					vert pre = que.front();
					que.pop();

					for (int k = 0; k < 8; ++k)
					{
						int next_x = pre.first + direction[k][0];
						int next_y = pre.second + direction[k][1];
						if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)  continue;
						if (grid[next_x][next_y] == 0) continue;

						grid[next_x][next_y] = 0;
						que.push({ next_x, next_y });
					}
				}
			}
		}
		cout << c << '\n';
	}

	return 0;
}