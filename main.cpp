#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> re;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int mat[101][101];
int n, k, s;

int move(int x, int y) {
	int dp = 0;
	if (mat[x][y] == 1 || mat[x][y] == 2 ||
		x < 0 || y < 0 || x > n - 1 || y > k - 1) {
		return 0;
	} else {
		mat[x][y] = 2;
		dp++;
		for (int i = 0; i < 4; i++) {
			dp += move(x+dir[i][0], y+dir[i][1]);
		}
		return dp;
	}
}

int main() {
	int sx, sy, ex, ey;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> k >> n >> s;
	for (int i = 0; i < s; i++) {
		cin >> sx >> sy >> ex >> ey;
		for (int j = sx; j < ex; j++) {
			for (int k = sy; k < ey; k++)
				mat[j][k] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (!(mat[i][j] == 1 || mat[i][j] == 2))
				re.push_back(move(i, j));
		}
	}
	sort(re.begin(), re.end());
	cout << re.size() << '\n';
	for (int i = 0; i < re.size(); i++)
		cout << re[i] << ' ';

	return 0;
}