#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mat;
vector<vector<int>> sum;

int main() {
	int r, c, n;
	int x1, x2, y1, y2;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c >> n;
	mat = vector<vector<int>>(r+1, vector<int>(c+1, 0));
	sum = vector<vector<int>>(r+1, vector<int>(c+1, 0));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mat[i][j];
			sum[i][j] += mat[i][j] + sum[i][j-1];
		}
	}
	for (int i = 0; i < n; i++) {
		int re = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++)
			re += sum[j][y2] - sum[j][y1-1];
		cout << re / ((x2 - x1 + 1) * (y2 - y1 + 1)) << '\n';
	}
	return 0;
}