#include <iostream>
#include <queue>
using namespace std;

struct vertex
{
	int x, y;
};

int direction[8][2]{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(m));

	queue<vertex> bfs_queue;
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			int shark;
			cin >> shark;
			dist[x][y] = -1;

			if (shark == 1)
			{
				bfs_queue.push({ x, y });
				dist[x][y] = 0;
			}
		}
	}

	int max_dist = 0;
	while (!bfs_queue.empty())
	{
		vertex pre_vertex = bfs_queue.front();
		bfs_queue.pop();

		for (int i = 0; i < 8; ++i)
		{
			int next_x = pre_vertex.x + direction[i][0];
			int next_y = pre_vertex.y + direction[i][1];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
			if (dist[next_x][next_y] != -1) continue;

			dist[next_x][next_y] = dist[pre_vertex.x][pre_vertex.y] + 1;
			if (dist[next_x][next_y] > max_dist)
			{
				max_dist = dist[next_x][next_y];
			}

			bfs_queue.push({ next_x, next_y });
		}
	}

	cout << max_dist;
	return 0;
}