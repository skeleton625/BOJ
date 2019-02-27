#include <iostream>
#include <queue>
#define min(a, b)(a < b ? a : b)
using namespace std;

int n, result;
bool visit[1000001];

int bfs() {
	queue<pair<int, int>> que;
	/* ���۰� �Է� */
	que.push({ n, 0 });

	int pn, pd;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		pn = que.front().first;		/* ���� ���� ��ġ ����  */
		pd = que.front().second;	/* ���� ���ڿ� ���� ���� Ƚ�� ���� */
		que.pop();

		/* ���� ���ڸ� �湮�ߴٴ� ���� ǥ���� */
		visit[pn] = true;

		if (pn == 1)	/* ���ʷ� �����ϴ� ��尡 Ƚ���� ���� ���� ����̹Ƿ� ��ȯ */
			return pd;
		/* i-1 ���ڸ� �湮���� �ʾ��� ��� (1�� ���� ����) ť�� ���� Ƚ���� �������� �Է� */
		if (!visit[pn - 1])
			que.push({ pn - 1, pd + 1 });
		/* 
			i/2 ���ڸ� �湮���� �ʰ� 2�� �������� ��� 
			(2�� �������� ����) ť�� ���� Ƚ���� �������� �Է� 
		*/
		if (!visit[pn / 2] && pn % 2 == 0)
			que.push({ pn / 2, pd + 1 });
		/* 
			i/3 ���ڸ� �湮���� �ʰ� 3���� �������� ��� 
			(3���� �������� ����) ť�� ���� Ƚ���� �������� �Է�
		*/
		if (!visit[pn / 3] && pn % 3 == 0)
			que.push({ pn / 3, pd + 1 });
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� Ƚ���� Ȯ���� ���� �Է� */
	cin >> n;
	cout << bfs();
	return 0;
}