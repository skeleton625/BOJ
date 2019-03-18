#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ver{
	int x, y;
};
int n, color_space, none_color_space;
int dir[4][2] = { {-1, 0}, { 0, -1}, {1, 0}, {0, 1} };
bool c_visit[101][101], nc_visit[101][101];
char mat[101][101];

void c_bfs(int sx, int sy, char c) {
	queue<ver> que;
	que.push({ sx, sy });

	c_visit[sx][sy] = true;

	ver cur;
	int nx, ny;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++) {
			nx = dir[i][0] + cur.x, ny = dir[i][1] + cur.y;

			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
			if (!c_visit[nx][ny] && c == mat[nx][ny]) {
				c_visit[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
	}
	color_space++;
}

void nc_bfs(int sx, int sy, char c) {
	queue<ver> que;
	que.push({ sx, sy });

	nc_visit[sx][sy] = true;

	int nx, ny;
	ver cur;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++) {
			nx = dir[i][0] + cur.x, ny = dir[i][1] + cur.y;

			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;

			if (!nc_visit[nx][ny]) {
				if (c == mat[nx][ny]) {
					nc_visit[nx][ny] = true;
					que.push({ nx, ny });
				}
				else if (
					(c == 'R' && mat[nx][ny] == 'G') ||
					(c == 'G' && mat[nx][ny] == 'R')) {
					nc_visit[nx][ny] = true;
					que.push({ nx, ny });
				}
			}
		}
	}

	none_color_space++;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!c_visit[i][j])
				c_bfs(i, j, mat[i][j]);
			if(!nc_visit[i][j])
				nc_bfs(i, j, mat[i][j]);
		}
	}

	cout << color_space << ' ' << none_color_space;
	return 0;
}