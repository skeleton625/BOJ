#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define NMAX 1001

int n, m, v;
vector<bool> visit;
bool mat[NMAX][NMAX];

void bfs() {
	queue<int> que;
	visit = vector<bool>(n+1, 0);

	que.push(v);
	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) continue;
		visit[cur] = true;
		cout << cur << ' ';

		for (int i = 1; i <= n; i++) {
			nex = mat[cur][i];
			if (nex && !visit[i]) que.push(i);
		}
	}
}

void dfs() {
	stack<int> sta;
	int cur, nex;
	bool flag;
	visit = vector<bool>(n+1, 0);

	sta.push(v);
	visit[v] = true;
	cout << v << ' ';
	while (!sta.empty()) {
		cur = sta.top();
		flag = true;

		for (int i = 1; i <= n; i++) {
			nex = mat[cur][i];
			if (nex && !visit[i]) {
				visit[i] = true;
				flag = false;
				cout << i << ' ';
				sta.push(i);
				break;
			}
		}

		if (flag) sta.pop();
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = true;
		mat[b][a] = true;
	}

	dfs();
	cout << '\n';
	bfs();

	return 0;
}