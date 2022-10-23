#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	for (int test = 0; test < t; ++test)
	{
		int v, e;
		cin >> v >> e;

		vector<vector<int>> grid = vector<vector<int>>(v + 1, vector<int>());
		vector<int> dot_color = vector<int>(v + 1, -1);
		for (int line = 0; line < e; ++line)
		{
			int a, b;
			cin >> a >> b;
			grid[a].push_back(b);
			grid[b].push_back(a);
		}

		bool is_failed = false;
		queue<int> bfs_queue;
		for (int dot = 1; dot <= v; ++dot)
		{
			if (dot_color[dot] != -1) continue;

			bfs_queue.push(dot);
			dot_color[dot] = 0;

			while (!bfs_queue.empty())
			{
				int pre_dot = bfs_queue.front();
				bfs_queue.pop();

				int next_color = dot_color[pre_dot] == 0 ? 1 : 0;
				for (int line = 0; line < grid[pre_dot].size(); ++line)
				{
					int next_dot = grid[pre_dot][line];
					if (dot_color[next_dot] == -1)
					{
						dot_color[next_dot] = next_color;
						bfs_queue.push(next_dot);
					}
					else if (dot_color[next_dot] == dot_color[pre_dot])
					{
						is_failed = true;
						break;
					}
				}

				if (is_failed) break;
			}

			if (is_failed) break;
		}

		cout << (is_failed ? "NO" : "YES") << '\n';
	}

	return 0;
}