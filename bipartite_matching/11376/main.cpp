#include <iostream>
#include <vector>
#define nMAX 1001
#define mMAX 1001
using namespace std;

int n, m;
bool adj[nMAX][mMAX];
vector<int> mMatch; // ÀÛ¾÷
vector<bool> visited;

bool dfs(int human)
{
	if (visited[human])
		return false;

	visited[human] = true;

	for (int work = 1; work <= m; work++)
	{
		if (adj[human][work])
		{
			if (mMatch[work] == -1 || dfs(mMatch[work]))
			{
				mMatch[work] = human;
				return true;
			}
		}
	}
	return false;
}

int biPartiteMatching()
{
	mMatch = vector<int>(m + 1, -1);

	int cnt = 0;

	for (int human = 1; human <= n; human++)
	{
		for (int j = 0; j < 2; j++)
		{
			visited = vector<bool>(n + 1, false);
			if (dfs(human))
				++cnt;
		}
	}
	return cnt;
}

int main()
{
	int cnt, work;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin >> work;
			adj[i][work] = true;
		}
	}

	cout << biPartiteMatching();

	return 0;
}