#include <iostream>
#include <vector>
#include <queue>
#define NMAX 1001	/* ������ �ִ� ���� ���� */
using namespace std;

int n, m;				/* ����, ���� ���� ���� ���� ���� */
int matc[NMAX];			/* �� �������� ���� ���� �迭 ���� */
vector<int> res;		/* ���� ���� �迭 ���� */
vector<int> mat[NMAX];	/* ���� �׷��� �迭 ���� */

void bfs() {
	queue<int> que;
	/* ���� ������ ť�� �Է� */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) que.push(i);
	}

	/* BFS �˰��� ���� */
	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();
		res.push_back(cur);

		/* ����� �� �������� �湮�� */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			matc[nex]--;	/* ���� ������ ����Ǿ� �ִ� ���� ���� */
			/* ���� ������ ����� ��� �������� �湮�� ��� �ش� ������ ť�� �Է� */
			if (matc[nex] == 0) que.push(nex);
		}
	}

	/* 
		��� ������ ������� �湮�� �� �ִ� ��츦 �ľ�
		�׷��� ���� ���, 0�� �����.
	*/
	for (int i = 1; i <= n; i++) {
		if (matc[i] != 0) {
			cout << 0;
			return;
		}
	}

	/* ��� ������ ������� �湮�� ��� ������ ������� ��� */
	for (auto it : res)
		cout << it << '\n';
}

int main() {
	int c, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);
	/* ���� ����, ������ ���� �Է� ���� �Է� */
	cin >> n >> m;
	
	/* ������ ���� �Է� */
	for (int i = 0; i < m; i++) {
		/* �� �ٿ� �ԷµǴ� ���� ��, ù ��° ���� ��ȣ �Է� */
		cin >> c >> a;
		/* �� �ٿ� �ԷµǴ� ������ ��ȣ�� ���� ������ ��ȣ�� �Է� �޾� �׷����� ���� */
		for (int j = 1; j < c; j++) {
			cin >> b;
			mat[a].push_back(b);
			matc[b]++;	/* ����� ������ ������ ������ */
			a = b;		/* ���� ������ ���� ������ �������ֱ� ���� */
		}
	}

	bfs();
	return 0;
}