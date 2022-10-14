#include <iostream>
#include <queue>
#define MAX_DIST 401
using namespace std;

struct vert
{
	int x, y;
};

int direction[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int n;
int start_x;
int start_y;
int shark_size;
int moving_dist;
vector<vector<int>> grid;
vector<vector<int>> dist;

bool bfs()
{
	int min_x = start_x;
	int min_y = start_y;
	int min_dist = MAX_DIST;

	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y)
			dist[x][y] = -1;

	queue<vert> bfs_queue;
	bfs_queue.push({ start_x, start_y });
	dist[start_x][start_y] = 0;

	while (!bfs_queue.empty())
	{
		vert pre_vertex = bfs_queue.front(); bfs_queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int next_x = pre_vertex.x + direction[i][0];
			int next_y = pre_vertex.y + direction[i][1];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
			if (dist[next_x][next_y] != -1 || grid[next_x][next_y] > shark_size) continue;

			dist[next_x][next_y] = dist[pre_vertex.x][pre_vertex.y] + 1;
			if (grid[next_x][next_y] != 0 && grid[next_x][next_y] < shark_size)
			{
				if (dist[next_x][next_y] < min_dist)
				{
					min_x = next_x;
					min_y = next_y;
					min_dist = dist[next_x][next_y];
				}
				else if (dist[next_x][next_y] == min_dist)
				{
					if (next_x < min_x)
					{
						min_x = next_x;
						min_y = next_y;
					}
					else if (next_x == min_x)
					{
						if (next_y < min_y)
						{
							min_x = next_x;
							min_y = next_y;
						}
					}
				}
			}

			bfs_queue.push({ next_x, next_y });
		}
	}

	if (min_x == start_x && min_y == start_y)
		return false;

	start_x = min_x;
	start_y = min_y;
	moving_dist += min_dist;
	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	
	grid = vector<vector<int>>(n, vector<int>(n));
	dist = vector<vector<int>>(n, vector<int>(n));
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			cin >> grid[x][y];

			if (grid[x][y] == 9)
			{
				start_x = x;
				start_y = y;
			}
		}
	}

	int eat_count = 0;
	
	shark_size = 2;
	grid[start_x][start_y] = 0;
	while (bfs())
	{
		grid[start_x][start_y] = 0;
		eat_count++;

		if (eat_count == shark_size)
		{
			eat_count = 0;
			shark_size++;
		}
	}

	cout << moving_dist;
	return 0;
}