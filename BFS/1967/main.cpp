#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> ver;
int n;
vector<ver> mat[10001];
vector<bool> visit;
vector<int> dist;

ver dijkstra(int start) {
	dist = vector<int>(n + 1, 0);
	visit = vector<bool>(n + 1, false);
	queue<ver> que;
	que.push({ start, 0 });
	ver ver_max = { start, 0 };

	int pn, pd, nn, nd;
	while (!que.empty()) {
		pn = que.front().first;
		pd = que.front().second;
		que.pop();

		if (visit[pn]) continue;
		visit[pn] = true;

		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].first;
			if (!visit[nn]) {
				nd = dist[pn] + mat[pn][i].second;
				dist[nn] = nd;
				que.push({ nn, nd });
				if (ver_max.second < nd) {
					ver_max.first = nn;
					ver_max.second = nd;
				}
			}
		}
	}

	return ver_max;
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
		mat[b].push_back({ a, c });
	}

	ver n1 = dijkstra(1);
	ver n2 = dijkstra(n1.first);

	cout << n2.second;
	return 0;
}