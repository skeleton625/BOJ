#include <iostream>
#include <vector>
#include <queue>
#define NMAX 32001
using namespace std;

int n, m;
int matc[NMAX];			/* ������ ������ ����� ���� �迭 */
vector<int> mat[NMAX];	/* ���� ���� �׷��� */

void bfs() {
	queue<int> que;
	
	/* �ش� ������ ����Ǿ� �ִ� ������ ������ 0��, �� ���� ������ ť�� �Է� */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) que.push(i);
	}

	int cur, nex;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		cur = que.front(); que.pop();
		/* ���� ������ ť ������ ���� ���� �����̹Ƿ� ��� */
		cout << cur << ' ';

		/* ���� ������ ����Ǿ� �ִ� �������� Ȯ�� */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			/* ���� ����� ������ �湮�����Ƿ� ����� ������ ������ ���ҽ�Ŵ */
			matc[nex]--;
			/* ���� ���� ������ ���� ������ 0, �� ���� ������ �Ǿ��� �� ť�� �Է� */
			if (matc[nex] == 0) que.push(nex);
		}
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �� ������ ������ ������ ������ �Է� */
	cin >> n >> m;
	/* �׷����� ���� ������ �Է� */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		matc[b]++;	/* �ش� ������ ����� ������ ������ ������ */
	}

	bfs();
	return 0;
}