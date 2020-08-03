#include <iostream>
#include <queue>
using namespace std;

struct ball {
	int d, rx, ry, bx, by;
};
int mat[10][10];
int a, b;
bool visit[10][10][10][10];
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char in[11];

void marble_move(int& x, int& y, int i) {
	while (1) {
		x += dir[i][0], y += dir[i][1];
		if (mat[x][y] == 1) {
			x -= dir[i][0], y -= dir[i][1];
			break;
		} else if(mat[x][y] == 2){
			break;
		}
	}
}

int main() {
	int prx, pry, pbx, pby, dx, dy, re = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> in;
		for (int j = 0; j < b; j++) {
			switch (in[j]) {
			case '#':
				mat[i][j] = 1;
				break;
			case '.':
				mat[i][j] = 0;
				break;
			case 'O':
				mat[i][j] = 2;
				dx = i, dy = j;
				break;
			case 'R':
				prx = i, pry = j;
				break;
			case 'B':
				pbx = i, pby = j;
				break;
			}
		}
	}

	queue<ball> que;
	que.push({0,prx,pry,pbx,pby});
	visit[prx][pry][pbx][pby] = true;
	while (!que.empty()) {
		ball cur = que.front(); que.pop();

		if (cur.d > 10) {
			break;
		} else if (cur.rx == dx && cur.ry == dy) {
			re = 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int rx = cur.rx; int ry = cur.ry;
			int bx = cur.bx; int by = cur.by;
			marble_move(rx, ry, i); marble_move(bx, by, i);

			if (bx == dx && by == dy) continue;
			else if (rx == bx && ry == by) {
				switch (i) {
				case 0:
					cur.rx < cur.bx ? bx++ : rx++;
					break;
				case 1:
					cur.ry < cur.by ? by++ : ry++;
					break;
				case 2:
					cur.rx < cur.bx ? rx-- : bx--;
					break;
				case 3:
					cur.ry < cur.by ? ry-- : by--;
					break;
				}
			}

			if (!visit[rx][ry][bx][by]) {
				que.push({ cur.d+1, rx, ry, bx, by });
				visit[rx][ry][bx][by] = true;
			}
		}
	}
	cout << re;
	return 0;
}