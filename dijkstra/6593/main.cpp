#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 31

struct ver {
	int x, y, z, d;
};

int d, r, l;
int dir[6][3] = {
	{1, 0, 0}, {-1, 0, 0},
	{0, 1, 0}, {0, -1, 0},
	{0, 0, 1}, {0, 0, -1}
};
char mat[NMAX][NMAX][NMAX];
vector<vector<vector<bool>>> visit;

void bfs(int *start) {
	/* ���ͽ�Ʈ�� �˰����� ������ �ڷᱸ�� ť ���� */
	queue<ver> que;
	/* �׷����� ������ �湮�ߴ��� �ľ��� 3���� �迭 ���� */
	visit = vector<vector<vector<bool>>>(d, vector<vector<bool>>(r, vector<bool>(l, false)));
	
	/* ���� ������ ť�� �Է��ϰ� �湮 ǥ�ø� ���� */
	que.push({ start[0], start[1], start[2] });
	visit[start[0]][start[1]][start[2]] = true;
	
	ver cur;
	int nx, ny, nz, nd;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		/* ť ���� ù ��° ���� ���� */
		cur = que.front(); que.pop();

		/* ���� ���� �������� �ⱸ�� ��� �ɸ� �ð��� ����ϰ� ���� */
		if (mat[cur.x][cur.y][cur.z] == 'E') {
			cout << "Escaped in " << cur.d << " minute(s).\n";
			return;
		}
		
		/* �����¿����ķ� ���� �������� �̵���Ŵ */
		for (int i = 0; i < 6; i++) {
			/* ���� ������ ��ġ�� ��ǥ�� ��� */
			nx = cur.x + dir[i][0], ny = cur.y + dir[i][1], nz = cur.z + dir[i][2];

			/* �̵��� �Ұ����� ���� ��� �ǳ� �� */
			if (nx < 0 || ny < 0 || nz < 0 || nx > d - 1 || ny > r - 1 || nz > l - 1)
				continue;
			/* �̵��ϴ� ������ ���� ��� �ǳ� �� */
			else if (mat[nx][ny][nz] == '#')
				continue;
			/* 
				�� �̿ܿ� �湮���� ���� ������ ��� �� ������ �湮�ߴ� ǥ��
				���� �������� �̵��� ���� �ð��� ����� ���� ��ǥ�� ���� ť�� �Է�
			*/
			else if (!visit[nx][ny][nz]) {
				visit[nx][ny][nz] = true;
				nd = cur.d + 1;
				que.push({ nx, ny, nz, nd });
			}
		}
	}

	/* ��� �������� �̵��ص� �ⱸ�� �������� ���� ��� ���� ������ ��� */
	cout << "Trapped!\n";
}

int main() {
	int start[3], end[3];
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ����ü�� x, y, z ���� �Է� */
	cin >> d >> r >> l;
	/* �ԷµǴ� x, y, z ���̰� ��� 0�� �� ������ �ݺ� */
	while (d || r || l) {
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < l; k++) {
					cin >> mat[i][j][k];
					/* ����ü���� ���� ��ġ�� ���� */
					if (mat[i][j][k] == 'S') {
						start[0] = i, start[1] = j, start[2] = k;
					}
				}
			}
		}

		/* BFS �˰��� ���� */
		bfs(start);
		/* �ٽ� ����ü�� x, y, z ���� �Է� */
		cin >> d >> r >> l;
	}
	return 0;
}