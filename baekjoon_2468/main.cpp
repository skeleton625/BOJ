#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ( a < b ? b : a );
#define min(a, b) ( a < b ? a : b );
using namespace std;

struct ver {
	int x, y;
};
int n, maxdep, resdep;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int mat[100][100];
vector<vector<bool>> space;

void bfs(int sx, int sy) {
	queue<ver> que;
	que.push({ sx, sy });

	int nx, ny;
	ver cur;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++) {
			nx = dir[i][0] + cur.x, ny = dir[i][1] + cur.y;

			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;

			if (!space[nx][ny]) {
				space[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
	}
}

bool find_space() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!space[i][j]) {
				bfs(i , j);
				cnt++;
			}
		}
	}
	if (resdep < cnt) {
		resdep = cnt;
		return false;
	}
	else return true;
}

void set_water_space(int dep) {
	space = vector<vector<bool>>(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] <= dep) 
				space[i][j] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			maxdep = max(maxdep, mat[i][j]);
		}
	}

	for (int i = 0; i < maxdep; i++) {
		set_water_space(i);
		find_space();
	}
	
	cout << resdep;
	return 0;
}