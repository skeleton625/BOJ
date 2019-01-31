#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool mat[1001][1001];
bool visit_dfs[1001], flag;
bool visit_bfs[1001];
int n, m, v, n1, n2;

void bfs(int start) {
	int w;
	queue<int> pre;

	pre.push(start);
	visit_bfs[start] = 1;

	while (!pre.empty()) {
		w = pre.front();
		pre.pop();
		cout << w << ' ';
		for (int i = 1; i <= n; i++) {
			if (mat[w][i] && !visit_bfs[i]) {
				visit_bfs[i] = true;
				pre.push(i);
			}
		}
	}
}

void dfs(int start) {
	int w;
	stack<int> pre;

	pre.push(start);
	visit_dfs[start] = 1;
	cout << start << ' ';

	while (!pre.empty()) {
		w = pre.top();
		flag = false;

		for (int i = 1; i <= n; i++) {
			if (mat[w][i] && !visit_dfs[i]) {
				visit_dfs[i] = true;
				cout << i << ' ';
				pre.push(i);
				flag = true;
				break;
			}
		}

		if (!flag) {
			pre.pop();
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		mat[n1][n2] = true;
		mat[n2][n1] = true;
	}

	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}