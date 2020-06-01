#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct fri {
	int x, d;
};
vector<int> mat[101];
vector<bool> visit;
vector<int> result;
int n, m;
int n1, n2, conn_min = 5001;

int bfs(int st) {
	int c = 0;
	queue<fri> que;
	que.push({ st, 0 });
	while (!que.empty()) {
		fri cur = que.front(); que.pop();
		for (int i = 0; i < mat[cur.x].size(); i++) {
			if (!visit[mat[cur.x][i]]) {
				visit[mat[cur.x][i]] = true;
				que.push({ mat[cur.x][i], cur.d+1});
				c += cur.d+1;
			}
		}
	}
	return c;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		mat[n1].push_back(n2);
		mat[n2].push_back(n1);
	}

	result = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		visit = vector<bool>(n + 1, 0);
		visit[i] = true;
		result[i] = bfs(i);
		conn_min = min(conn_min, result[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (conn_min == result[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}