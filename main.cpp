#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct pos {
	int cx, cy;
};
bool mat[50][50];
bool visit[50][50];
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int m, n, t;

void worm_count(int x, int y) {
	queue<pos> que;
	
	que.push({ x,y });
	visit[x][y] = true;
	while (!que.empty()) {
		pos cur = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur.cx + dir[i][0], py = cur.cy + dir[i][1];
			if (px < 0 || py < 0 || px > m - 1 || py > n - 1)
				continue;
			else if (!mat[px][py])
				continue;
			else if (!visit[px][py]) {
				visit[px][py] = true;
				que.push({ px, py });
			}
		}
	}
}

int main() {
	int k, x, y, count;
	cin >> t;
	while (t--) {
		count = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			memset(mat[i], 0, sizeof(bool)*n);
			memset(visit[i], 0, sizeof(bool)*n);
		}

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			mat[x][y] = true;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] && !visit[i][j]) {
					worm_count(i, j);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}