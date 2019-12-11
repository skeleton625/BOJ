#include <iostream>
#include <vector>
#define INF 400
#define min(a, b) (a < b ? a: b)
using namespace std;

int main() {
	int n, k, a, b, s;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	vector<vector<int>> mat(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		mat[i][i] = 0;
	
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		if (mat[a][b] != INF)
			cout << -1 << '\n';
		else if (mat[b][a] != INF)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}