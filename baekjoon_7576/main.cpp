#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y, d;
};
int mat[1000][1000];
int dir[4][2] = { {-1,0}, {0,-1},{1,0},{0,1} };
int m, n, zc;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int prd = 0;
	cin >> n >> m;
	queue<tomato> que;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1)
				que.push({ i,j, 0 });
			else if (mat[i][j] == 0)
				zc++;
		}
	}

	while (!que.empty()) {
		tomato cur = que.front(); que.pop();
		int tx = cur.x, ty = cur.y, td = cur.d;
		if (prd != td) {
			prd++;
		}
		for (int i = 0; i < 4; i++) {
			if (tx + dir[i][0] < 0 || ty + dir[i][1] < 0
				|| tx + dir[i][0] > m - 1 || ty + dir[i][1] > n - 1) {
				continue;
			}
			else if (mat[tx + dir[i][0]][ty + dir[i][1]] == 1 ||
				mat[tx + dir[i][0]][ty + dir[i][1]] == -1) {
				continue;
			}
			zc--;
			mat[tx + dir[i][0]][ty + dir[i][1]] = 1;
			que.push({ tx + dir[i][0], ty + dir[i][1], td+1 });
		}
	}
	if(zc == 0) cout << prd;
	else cout << -1;
	return 0;
}