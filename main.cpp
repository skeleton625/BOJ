#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int x, t;
};
int n, k;
int dir[3] = { -1, 0, 1 };
bool visit[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	queue<pos> que;
	visit[n] = true;
	que.push({ n,0 });

	while (!que.empty()) {
		pos cur = que.front();
		que.pop();

		if (cur.x == k) {
			cout << cur.t;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (dir[i] != 0) {
				next = cur.x + dir[i];
			} else {
				next = 2 * cur.x;
			}
			if (0 <= next && next <= 100000) {
				if (!visit[next]) {
					visit[next] = true;
					que.push({ next, cur.t + 1 });
				}
			}
		}
	}
	return 0;
}