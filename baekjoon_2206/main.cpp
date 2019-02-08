#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
	int x, y, d;
	bool is_crash;
};
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char mat[1000][1000];
int visit[1000][1000];
int n, m;

int find_min() {
	int path_min = 1000001;
	queue<pos> que;
	que.push({ 0, 0, 1, false });
	visit[0][0] = true;
	while (!que.empty()) {
		pos cur = que.front(); que.pop();
		
		if (cur.x == n - 1 && cur.y == m - 1) {
			return cur.d;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int px = cur.x + dir[i][0], py = cur.y + dir[i][1];
			if (px < 0 || py < 0 || px > n - 1 || py > m - 1)
				continue;
			else if (mat[px][py] == '1') {
				if (!cur.is_crash) {
					visit[px][py] = 2;
					que.push({px, py, cur.d+1, true});
				} else continue;
			}
			else if (visit[px][py] != 1 && visit[px][py] != 2) {
				if(!cur.is_crash) visit[px][py] = 1;
				else visit[px][py] = 2;
				que.push({px, py, cur.d+1, cur.is_crash});
			}
			else if (visit[px][py] == 2 && !cur.is_crash) {
				visit[px][py] = 1;
				que.push({px, py, cur.d+1, cur.is_crash});
			}
		}
	}
	return path_min;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	int result = find_min();
	if (result == 1000001) { cout << -1; }
	else { cout << result; }
	return 0;
}