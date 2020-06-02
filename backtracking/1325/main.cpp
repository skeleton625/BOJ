#include <iostream>
#include <algorithm>
#include <vector>
#define NUMMAX 10001
using namespace std;

vector<int> mat[NUMMAX];
vector<bool> visit;
vector<int> hack;
bool is_conn;
int n, m;
int n1, n2, hack_max;

void dfs(int start) {

	hack[start]++;
	hack_max = max(hack_max, hack[start]);

	for (int i = 0; i < mat[start].size(); i++) {
		int next = mat[start][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		mat[n1].push_back(n2);
	}

	hack = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		visit = vector<bool>(n + 1, 0);
		visit[i] = true;
		dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (hack_max == hack[i])
			cout << i << ' ';
	}
	return 0;
}
