#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> mat;
vector<vector<int>> movs[3];
int n;
int last[3][2] = {
	{0, 0},
	{-1, 0},
	{0, -1}
};

struct pipe
{
	int types;
	int x, y;
};

int CountMoving()
{
	int cnt = 0;
	bool flag = true;
	queue<pipe> que;
	que.push({ 0, 0, 1 });

	int px, py, pt;
	int nx, ny, nt;
	while (!que.empty())
	{
		pt = que.front().types;
		px = que.front().x;
		py = que.front().y;
		que.pop();

		if (px == n - 1 && py == n - 1)
		{
			++cnt;
			continue;
		}

		for (int i = 0; i < movs[pt].size()-1; i++)
		{
			nx = px + movs[pt][i][0], ny = py + movs[pt][i][1];
			if (nx >= n || ny >= n || mat[nx][ny] == 1)
				continue;

			if (pt == 2)
				nt = i;
			else
				nt = pt;

			que.push({ nt, nx, ny });
		}

		int las = movs[pt].size()-1;
		nx = px + movs[pt][las][0], ny = py + movs[pt][las][1];
		for (int i = 0; i < 3; i++)
		{		
			if (nx >= n || ny >= n || mat[nx + last[i][0]][ny + last[i][1]])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			que.push({ 2, nx, ny });
		flag = true;
	}

	return cnt;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	movs[0] = vector<vector<int>>(2, vector<int>(2, 0));
	movs[0] = { {0, 1}, {1, 1} };
	movs[1] = vector<vector<int>>(2, vector<int>(2, 0));
	movs[1] = { {1, 0}, {1, 1} };
	movs[2] = vector<vector<int>>(3, vector<int>(2, 0));
	movs[2] = { {0, 1}, {1, 0}, {1, 1} };
	
	cin >> n;
	mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	cout << CountMoving();
	return 0;
}