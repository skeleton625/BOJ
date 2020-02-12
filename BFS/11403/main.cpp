#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<bool> visit;
bool mat[100][100];
bool result[100][100];

void bfs(int s) {
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int cur = que.front(); que.pop();

		for (int i = 0; i < n; i++) {
			if (mat[cur][i]&&!visit[i]) {
				visit[i] = true;
				result[s][i] = true;
				que.push(i);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	for (int i = 0; i < n; i++) {
		visit = vector<bool>(n, 0);
		bfs(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}