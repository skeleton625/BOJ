#include <cstdio>
#include <vector>
#include <queue>
#define max(a, b) (a < b ? b : a);
using namespace std;

struct ver {
	int x, y;
};
int a, b, walnum, maxlen;
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int mat[8][8];
vector<ver> vi;
vector<vector<bool>> visit;

void bfs() {
	queue<ver> que;
	visit = vector<vector<bool>>(a, vector<bool>(b, false));
	for (int i = 0; i < vi.size(); i++) {
		que.push(vi[i]);
		visit[vi[i].x][vi[i].y] = true;
	}

	ver cur;
	int nx, ny, cnt = a*b;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++) {
			nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
			if (nx < 0 || ny < 0 || nx > a - 1 || ny > b - 1) continue;

			if (!visit[nx][ny] && mat[nx][ny] != 1) {
				cnt--;
				visit[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
	}
	cnt -= (walnum + 3 + vi.size());
	maxlen = max(maxlen, cnt);
}

void chos_wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	} else {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (mat[i][j] == 0) {
					mat[i][j] = 1;
					chos_wall(cnt + 1);
					mat[i][j] = 0;
				}
			}
		}
	}
}

int main() {

	scanf_s("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf_s("%d", &mat[i][j]);
			if (mat[i][j] == 1) walnum++;
			if (mat[i][j] == 2) vi.push_back({ i, j });
		}
	}

	chos_wall(0);
	printf("%d", maxlen);
	return 0;
}