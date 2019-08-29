#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<bool> isVisit;

int BFS()
{
	queue<pair<int, int>> que;
	que.push({ s, 0 });

	int pn, pc;
	while (!que.empty())
	{
		pn = que.front().first;
		pc = que.front().second;
		que.pop();

		if (pn == g)
		{
			return pc;
		}

		if (!isVisit[pn])
		{
			isVisit[pn] = true;
			if (pn + u <= f)
			{
				que.push({ pn + u, pc + 1 });
			}
			if (pn - d >= 1)
			{
				que.push({ pn - d,pc + 1 });
			}
		}
	}

	return -1;
}

int main()
{

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> f >> s >> g >> u >> d;
	isVisit = vector<bool>(f + 1, false);

	int res = BFS();

	if (res == -1)
		cout << "use the stairs";
	else
		cout << res;

	return 0;
}