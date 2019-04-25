#include <iostream>
#include <queue>
using namespace std;
#define NMAX 101

struct ver {
	int x, y, val;
};

int n, m;
int dir[4][2] = { { -1, 0}, {0, -1}, {1, 0}, {0, 1} };
char mat[NMAX][NMAX];
bool visit[NMAX][NMAX];

void bfs() {
	queue<ver> que;
	/*
		���� ��ġ �Է�
		ù ��° ĭ�̹Ƿ� val ���� 1�� �Է�
	*/
	que.push({ 0, 0, 1 });
	
	int px, py, pd, nx, ny;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		/* ���� ��ġ�� �̵��ߴ� ���� ���� */
		px = que.front().x;
		py = que.front().y;
		pd = que.front().val;
		que.pop();
		
		/* ���� �������� ������ ��� �̵��ߴ� ĭ ���� ����ϰ� ���� */
		if (px == n - 1 && py == m - 1) {
			cout << pd;
			break;
		}

		/* �湮�ߴ� ĭ�� ��� �Ѿ */
		if (visit[px][py]) continue;
		/* ���� ĭ �湮 ǥ�� */
		visit[px][py] = true;

		/* ���� ĭ���� �̵� ������ ��ġ ��� */
		for (int i = 0; i < 4; i++) {
			nx = px + dir[i][0], ny = py + dir[i][1];

			/* �̷θ� ����� ��ġ�� ��� �Ѿ */
			if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
			/* �̵� �Ұ����� ĭ�� ��� �Ѿ */
			else if (mat[nx][ny] == '0') continue;
			/* �� ���ǿ� ���� �ʰ� �湮���� ���� ĭ�� ��� �湮�ϰ� �湮 Ƚ���� ������Ŵ */
			else if (!visit[nx][ny]) que.push({ nx, ny, pd + 1 });
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ����, ���� ���� �Է� */
	cin >> n >> m;
	/* �̷� �Է� */
	for (int i = 0; i < n; i++) cin >> mat[i];

	/* BFS �˰��� ���� */
	bfs();
	return 0;
}