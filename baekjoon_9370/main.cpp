#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pai;
int n, m, t;
int s, g, h;
vector<pai> sline, gline, hline;

void dijkstra(int s, vector<pai> *mat, vector<pai> &line) {
	priority_queue<pai, vector<pai>, greater<pai>> que;
	line[s] = make_pair(0, 0);
	que.push({0, s});

	int pn, pd;
	while (!que.empty()) {
		pn = que.top().second;
		pd = que.top().first;
		que.pop();

		if (line[pn].first < pd)
			continue;
		
		int nn, nd;
		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].second;
			nd = pd + mat[pn][i].first;

			if (line[nn].first > nd) {
				line[nn].first = nd;
				line[nn].second = pn;
				que.push({ nd, nn });
			}
		}
	}
}

int main() {
	int a, b, c, tc;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		vector<pai> mat[2001];
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;

			mat[a].push_back({ c, b });
			mat[b].push_back({ c, a });
		}

		sline = vector<pai>(n + 1, { 2000000, 0 });
		gline = vector<pai>(n + 1, { 2000000, 0 });
		hline = vector<pai>(n + 1, { 2000000,0 });
		dijkstra(s, mat, sline);
		dijkstra(g, mat, gline);
		dijkstra(h, mat, hline);
		
		int num, c1, c2;
		priority_queue<int, vector<int>, greater<int>> poss;
		for (int i = 0; i < t; i++) {
			cin >> num;
			c1 = sline[g].first + gline[h].first + hline[num].first;
			c2 = sline[h].first + hline[g].first + gline[num].first;
			if (c1 == sline[num].first || c2 == sline[num].first)
				poss.push(num);
		}

		while (!poss.empty()) {
			cout << poss.top() << ' ';
			poss.pop();
		}
		cout << '\n';
	}
	return 0;
}