#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct knight {
	int x, y;
	int d;
};
int dir[8][2] = {
	{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, 
	{1, -2}, {1, 2}, {2, -1}, {2, 1}
};
int n;
int sx, sy, dx, dy;

int find_drc() {
	queue<knight> que;
	bool visit[300][300] = {0, };
	que.push({ sx, sy, 0 });

	while (!que.empty()) {
		knight cur = que.front(); que.pop();
		if (cur.x == dx && cur.y == dy)
			return cur.d;

		for (int i = 0; i < 8; i++) {
			if (cur.x + dir[i][0] < 0 || cur.y + dir[i][1] < 0)
				continue;
			else if (cur.x + dir[i][0] > n - 1 || cur.y + dir[i][1] > n - 1)
				continue;
			else if (!visit[cur.x + dir[i][0]][cur.y + dir[i][1]]) {
				visit[cur.x + dir[i][0]][cur.y + dir[i][1]] = true;
				que.push({ cur.x + dir[i][0], cur.y+dir[i][1], cur.d+1 });
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;

	cin >> t;
	while (t--) {
		cin >> n;
		cin >> sx >> sy >> dx >> dy;

		cout << find_drc() << '\n';
	}

	return 0;
}