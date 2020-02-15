#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pai;
int n, m, t;
int s, g, h;
vector<int> line;

void dijkstra(int s, vector<pai> *mat) {
	priority_queue<pai, vector<pai>, greater<pai>> que;
	line[s] = 0;
	que.push({0, s});

	int pn, pd;
	while (!que.empty()) {
		pn = que.top().second;
		pd = que.top().first;
		que.pop();

		if (line[pn] < pd)
			continue;
		
		int nn, nd;
		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].second;
			nd = pd + mat[pn][i].first;

			if (line[nn] > nd) {
				line[nn] = nd;
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
			if ((a == g && b == h) || (a == h && b == g)) c = 2 * c - 1;
			else c *= 2;
			mat[a].push_back({ c, b });
			mat[b].push_back({ c, a });
		}

		line = vector<int>(n + 1, 4000000);
		dijkstra(s, mat);

		int num;
		priority_queue<int, vector<int>, greater<int>> poss;
		for (int i = 0; i < t; i++) {
			cin >> num;
			if (line[num] % 2) poss.push(num);
		}

		while (!poss.empty()) {
			cout << poss.top() << ' ';
			poss.pop();
		}
		cout << '\n';
	}
	return 0;
}