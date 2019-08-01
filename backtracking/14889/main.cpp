#include <iostream>
#include <vector>
#define MIN(a, b) ( a < b ? a : b)
#define ABS(a) ( a < 0 ? -a : a)
#define NMAX 21
using namespace std;

int n, len, ans = 987654213;
int mat[NMAX][NMAX];

void dfs(int pre, vector<int> start) {
	if (start.size() == len) {
		vector<bool> visit(n + 1, 0);
		vector<int> link;

		for (int i = 0; i < start.size(); i++)
			visit[start[i]] = true;

		for (int i = 1; i <= n; i++)
			if (!visit[i]) link.push_back(i);

		int ssum = 0, lsum = 0;
		for (int i = 0; i < start.size() - 1; i++) {
			for (int j = i + 1; j < start.size(); j++) {
				ssum += mat[start[i]][start[j]] + mat[start[j]][start[i]];
				lsum += mat[link[i]][link[j]] + mat[link[j]][link[i]];
			}
		}
		ssum -= lsum;
		ans = MIN(ans, ABS(ssum));
		return;
	}
	for (int i = pre; i <= n; i++) {
		start.push_back(i);
		dfs(i + 1, start);
		start.pop_back();
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	len = n / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> mat[i][j];
	}

	vector<int> v;
	dfs(1, v);
	cout << ans;
	return 0;
}