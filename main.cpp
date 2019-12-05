#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, n, m;
bool is_graph;
vector<bool> visit;

void bfs(vector<int> *mat, int s) {
	queue<int> que;

	int cur, nex;
	que.push(s);
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) {
			is_graph = true;
			break;
		}
		visit[cur] = true;

		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			if (!visit[nex]) que.push(nex);
		}
	}
}

int main() {
	int a, b;
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		is_graph = false;
		vector<int> mat[1001];
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			mat[a].push_back(b);
			mat[b].push_back(a);
		}

		visit = vector<bool>(n + 1, false);
		bfs(mat, a);
		
		for (int i = 1; (i <= n&&!is_graph); i++) {
			if (!visit[i])is_graph = true;
		}

		if (is_graph) cout << "graph" << '\n';
		else cout << "tree" << '\n';
	}

	return 0;
}