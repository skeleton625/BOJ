#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#define NMAX 125	// ���� �迭�� �� �� ũ��
#define DMAX 1250	// ���� �迭 ������ �ִ� ���
using namespace std;

typedef pair<int, int> pai;
typedef pair<int, pai> vertex;

int n;
int mat[NMAX][NMAX];
const int dir[4][2] = { {-1, 0}, {0,-1}, {1, 0}, {0, 1} };
vector<int> dist[NMAX];

/* ���ͽ�Ʈ�� �˰��� �Լ� */
void dijkstra() {
	/* ���ͽ�Ʈ�� �˰��� ����� que ���� */
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;
	/* ���� ���� �ʱ�ȭ ���� */
	dist[0][0] = mat[0][0];
	que.push({ mat[0][0], {0, 0} });

	int px, py, pd;
	/* ���ͽ�Ʈ�� �˰��� ���� */
	while (!que.empty()) {
		/* ���� ������ x, y ��ġ�� �ִ� ����� ���� */
		px = que.top().second.first, py = que.top().second.second;
		pd = que.top().first;
		que.pop();

		/* ���� ��ġ�� �ִ� �ִ� ����� �̹� ���ŵǾ��� ��� ���� ��ġ�� �̵� */
		if (dist[px][py] < pd)
			continue;

		int nx, ny, nd;
		/* �������� �̵� ������ 4���� ������ ��� �õ� */
		for (int i = 0; i < 4; i++) {
			/* �������� �̵��� x, y ��ġ�� ���� */
			nx = px + dir[i][0], ny = py + dir[i][1];
			/* �̵��� ��ġ�� ���� ��� ���� ������ ���� */
			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1)
				continue;

			/* 
				�̵� ������ �������� �̵� ���� ��� �ش� ��ġ�� �ּ� ����� ���� �������� �ľ�
				������ ��� �ش� ��ġ�� �켱���� ť�� �Է�
			*/
			nd = mat[nx][ny] + pd;
			if (dist[nx][ny] > nd) {
				dist[nx][ny] = nd;
				que.push({ nd, {nx, ny} });
			}
		}
	}
}

int main() {
	int c = 1;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* �׽�Ʈ ���� */
	while (n) {
		/* ���� �迭�� ���� ���� �Է� */
		for (int i = 0; i < n; i++) {
			dist[i] = vector<int>(n, DMAX);
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		}

		dijkstra();
		/* ���� ��� ���� �Ծ��� ��� ����� �� ���� ���� ��� */
		cout << "Problem " + to_string(c) + ": " << dist[n-1][n-1] << '\n';
		c++;
		cin >> n;
	}
	return 0;
}