#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int x, y, d;
};
int m, n;
int dir[4][2] = { {-1, 0}, {0, -1}, {1,0}, {0,1} };
char mat[101][101];
vector<int> mat_min[100];

void dijkstra() {
	queue<pos> que;
	mat_min[0][0] = 0;
	que.push({ 0,0,0 });

	int px, py, pd;
	while (!que.empty()) {
		px = que.front().x, py = que.front().y, pd = que.front().d;
		que.pop();

		if (mat_min[px][py] < pd)
			continue;

		int nx, ny, nd;
		for (int i = 0; i < 4; i++) {
			nx = px + dir[i][0], ny = py + dir[i][1];
			if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1)
				continue;
			
			nd = pd;
			if (mat[nx][ny] == '1') nd++;
			if (mat_min[nx][ny] > nd) {
				mat_min[nx][ny] = nd;
				que.push({ nx,ny,nd });
			}
		}
	}
	cout << mat_min[n-1][m-1];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		mat_min[i] = vector<int>(m, 10000);
		cin >> mat[i];
	}

	dijkstra();
	return 0;
}