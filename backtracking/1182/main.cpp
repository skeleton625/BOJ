#include <iostream>
using namespace std;

int mat[20];
int n, s, cnt;

void dfs(int len, int res) {
	for (int i = len; i < n; i++) {
		res += mat[i];
		if (res == s) ++cnt;
		dfs(i + 1, res);
		res -= mat[i];
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	dfs(0, 0);
	cout << cnt;

	return 0;
}