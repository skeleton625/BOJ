#include <iostream>
#include <queue>
#define MAX_LENGTH 50
using namespace std;

struct vertex
{
	int x, y;
};

int direction[4][2]{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, l, r;
	cin >> n >> l >> r;

	vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(n));
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			cin >> grid[x][y];
		}
	}

	int count = 0;
	while (true)
	{
		vector<vector<int>> new_grid = vector<vector<int>>(n, vector<int>(n));
		vector<vector<bool>> is_visit = vector<vector<bool>>(n, vector<bool>(n));

		int connection = 0;
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < n; ++y)
			{
				if (is_visit[x][y]) continue;

				queue<vertex> bfs_queue;
				bfs_queue.push({ x, y });
				new_grid[x][y] = grid[x][y];

				vector<vertex> link_list;
				while (!bfs_queue.empty())
				{
					vertex pre_vertex = bfs_queue.front();
					bfs_queue.pop();

					for (int i = 0; i < 4; ++i)
					{
						int next_x = pre_vertex.x + direction[i][0];
						int next_y = pre_vertex.y + direction[i][1];

						if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
						if (is_visit[next_x][next_y]) continue;

						int diff = abs(grid[next_x][next_y] - grid[pre_vertex.x][pre_vertex.y]);
						if (diff < l || diff > r) continue;

						is_visit[next_x][next_y] = true;
						link_list.push_back({ next_x, next_y });
						bfs_queue.push({ next_x, next_y });
					}
				}

				if (link_list.size() > 0)
				{
					int sum = 0;
					for (int i = 0; i < link_list.size(); ++i)
					{
						sum += grid[link_list[i].x][link_list[i].y];
					}

					sum /= link_list.size();
					for (int i = 0; i < link_list.size(); ++i)
					{
						new_grid[link_list[i].x][link_list[i].y] = sum;
					}
					connection++;
				}
			}
		}

		if (connection == 0)
		{
			cout << count;
			return 0;
		}

		grid = new_grid;
		count++;
	}
}