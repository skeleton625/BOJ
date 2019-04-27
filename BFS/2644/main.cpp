#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 101

int n, m, s, e;
bool visit[NMAX];
vector<int> mat[NMAX];

void bfs() {
	/* BFS �˰����� �����ϱ� ���� queue �ڷ��� ���� */
	queue<pair<int, int>> que;
	/* ���� ���� �ʱ� �̼��� ������ queue�� �Է� */
	que.push({ s, 0 });

	int cur, curd, nex;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		/* ���� ���� �̵��� ���� ���� �Է� */
		cur = que.front().first;
		curd = que.front().second;
		que.pop();

		/* ������ ��� ������ ��� ���ݱ��� �̵��� ���� �� ��� */
		if (cur == e) {
			cout << curd;
			return;
		}
		/* �ƴϸ� ���� ����� �湮���� ��� �Ѿ */
		else if (visit[cur]) continue;
		/* �湮���� �ʾ��� ��� �湮������ ǥ�� */
		visit[cur] = true;

		/*
			���� ���� ����Ǿ� �ִ� �������� �ľ�
			�湮���� ���� ������ ���� queue�� �Է���
		*/
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			if (!visit[nex]) que.push({ nex, curd + 1 });
		}
	}
	/* ���� ������ ������ �������� ���� ��� "-1"�� ��� */
	cout << -1;
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ������ ��, ���� ���, ������ ���, ���� ���� ���� �Է� */
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		/* ���� ���� ������ �Է� */
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* BFS �˰��� ���� */
	bfs();
	return 0;
}