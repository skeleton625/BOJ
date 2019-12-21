#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mat[101];
vector<bool> visit;

int main() {
	int n, m, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	visit = vector<bool>(n + 1, false);
	queue<int> que;
	que.push(1);

	int cur, nex, c = 0;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) continue;
		visit[cur] = true;
		c++;

		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			if (!visit[nex])
				que.push(nex);
		}
	}

	cout << (c-1);
	return 0;
}