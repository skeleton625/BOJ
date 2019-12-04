#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> mat;
bool visit[100001];

int main() {
	int n, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	mat = vector<vector<int>>(n + 1, vector<int>(0, 0));
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	vector<bool> visit(n + 1, false);
	vector<int> result(n + 1, 0);
	queue<int> que;
	que.push(1);

	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) continue;
		visit[cur] = true;

		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			if (!visit[nex]) {
				result[nex] = cur;
				que.push(nex);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << result[i] << '\n';

	return 0;
}