#include <iostream>
#include <queue>
#define INF 1001
#define MAX(a ,b) ( a < b ? b : a )
using namespace std;

struct pos
{
	int x, y;
	int val;
};


int direct[3][2] = { {1, 0}, {0, 1}, {1, 1} };
int mat[INF][INF];
int res[INF][INF];

int BFS(int n, int m)
{
	res[0][0] = mat[0][0];
	int nx, ny, nv;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				nx = i+ direct[k][0], ny = j + direct[k][1];
				nv = mat[nx][ny] + res[i][j];
				if (nx >= n || ny >= m)
					continue;
				res[nx][ny] = MAX(res[nx][ny], nv);
			}
		}
	}

	return res[n - 1][m - 1];
}

int main()
{
	int n, m;
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	cout << BFS(n, m);

	return 0;
}