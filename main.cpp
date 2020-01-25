#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define DMAX 500000
using namespace std;

typedef pair<int, int> ver;

int n, m, s, e;
vector<int> dist;
vector<vector<bool>> visit;

void dijkstra(vector<ver> *mat) {
	priority_queue<ver, vector<ver>, greater<ver>> que;
	dist = vector<int>(n, DMAX);
	
	dist[s] = 0;
	que.push({ 0, s });

	int pn, pd;
	while (!que.empty()) {
		pn = que.top().second;
		pd = que.top().first;
		que.pop();

		if (dist[pn] < pd)
			continue;

		int nn, nd;
		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].second;
			nd = pd + mat[pn][i].first;

			if (dist[nn] > nd && !visit[pn][nn]) {
				dist[nn] = nd;
				que.push({ nd, nn });
			}
		}
	}
}

void remove_line(vector<ver> *back) {
	queue<int> que;
	que.push(e);

	while (!que.empty()) {
		int cur = que.front(); que.pop();

		if (cur == s)
			continue;

		for (int i = 0; i < back[cur].size(); i++) {
			int next = back[cur][i].second;

			if (dist[cur] == dist[next] + back[cur][i].first) {
				visit[next][cur] = true;
				que.push(next);
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (n != 0 && m != 0) {
		vector<ver> go[500];
		vector<ver> back[500];
		visit = vector<vector<bool>>(n, vector<bool>(n, false));

		cin >> s >> e;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			go[a].push_back({ c, b });
			back[b].push_back({ c, a });
		}

		dijkstra(go);
		remove_line(back);
		dijkstra(go);

		if (dist[e] == DMAX) cout << -1 << '\n';
		else cout << dist[e] << '\n';
		cin >> n >> m;
	}
	return 0;
}