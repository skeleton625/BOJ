#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y, z, d;
};
int dir [6][3] = { 
	{-1,0,0}, {0,-1,0}, {0,0,-1}, 
	{1, 0, 0}, {0,1,0}, {0,0,1}
};
int mat[100][100][100];
int m, n, h, zc, prd;
queue<tomato> que;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> mat[i][j][k];
				if (mat[i][j][k] == 1)
					que.push({ i, j, k, 0 });
				else if (mat[i][j][k] == 0)
					zc++;
			}
		}
	}

	while (!que.empty()) {
		tomato cur = que.front(); que.pop();
		int tx = cur.x, ty = cur.y, tz = cur.z, td = cur.d;
		if (prd != td) prd++;
		for (int i = 0; i < 6; i++) {
			if (tx + dir[i][0] < 0 || ty + dir[i][1] < 0 || tz + dir[i][2] < 0)
				continue;
			else if (tx + dir[i][0] > h - 1 || ty + dir[i][1] > n - 1 || tz + dir[i][2] > m - 1)
				continue;
			else if (mat[tx + dir[i][0]][ty + dir[i][1]][tz + dir[i][2]] == 1 ||
				mat[tx + dir[i][0]][ty + dir[i][1]][tz + dir[i][2]] == -1)
				continue;
			
			zc--;
			mat[tx + dir[i][0]][ty + dir[i][1]][tz + dir[i][2]] = 1;
			que.push({ tx + dir[i][0], ty + dir[i][1], tz + dir[i][2], td + 1 });
		}
	}
	if(zc == 0) cout << prd;
	else cout << -1;
	return 0;
}