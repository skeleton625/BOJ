#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef unsigned long long ll;

struct enemy {
	int x, y, r;
};
enemy tower[3000];
bool is_conn[3000];
int n, t, c;

ll getLen(int sx, int sy, int dx, int dy) {
	int rx = dx - sx;
	int ry = dy - sy;
	return (ll)(rx*rx) + (ll)(ry*ry);
}


void group_find(enemy st) {
	queue<enemy> que;
	que.push(st);

	while (!que.empty()) {
		enemy cur = que.front(); que.pop();

		for (int i = 0; i < n; i++) {
			if (!is_conn[i]) {
				ll rr = cur.r + tower[i].r;
				if (getLen(cur.x, cur.y, tower[i].x, tower[i].y) <= rr * rr) {
					is_conn[i] = true;
					que.push(tower[i]);
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> t;
	while (t--) {

		c = 0;
		cin >> n;
		memset(is_conn, 0, sizeof(bool)*n);
		for (int i = 0; i < n; i++)
			cin >> tower[i].x >> tower[i].y >> tower[i].r;

		for (int i = 0; i < n; i++) {
			if (!is_conn[i]) {
				is_conn[i] = true;
				group_find(tower[i]);
				c++;
			}
		}
		cout << c << '\n';
	}

	return 0;
}