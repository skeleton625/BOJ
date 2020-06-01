#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int x, d;
};
vector<int> mat[500001];
vector<bool> visit;
bool conn;
int n, n1, n2;

int bfs(int st) {
	int c = 0;
	queue<node> que;
	que.push({ st, 0 });
	while (!que.empty()) {
		conn = false;
		node cur = que.front(); que.pop();
		for (int i = 0; i < mat[cur.x].size(); i++) {
			if (!visit[mat[cur.x][i]]) {
				visit[mat[cur.x][i]] = true;
				que.push({ mat[cur.x][i], cur.d + 1 });
				conn = true;
			}
		}
		if (!conn) {
			c += cur.d;
		}
	}
	return c;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> n1 >> n2;
		mat[n1].push_back(n2);
		mat[n2].push_back(n1);
	}
	
	visit = vector<bool>(n + 1, 0);
	visit[1] = true;
	if (bfs(1) % 2 == 1)  cout << "Yes";
	else cout << "No";

	return 0;
}