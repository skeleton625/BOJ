#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<int> mat[1001];
bool visit[1001];

void bfs(int start) {
	queue<int> que;
	que.push(start);

	int pre;
	while (!que.empty()) {
		pre = que.front(); que.pop();

		int nex;
		for (int i = 0; i < mat[pre].size(); i++) {
			nex = mat[pre][i];

			if (!visit[nex]) {
				visit[nex] = true;
				que.push(nex);
			}
		}
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			c++;
			bfs(i);
		}
	}

	cout << c;

	return 0;
}