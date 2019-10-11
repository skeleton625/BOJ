#include <iostream>
#include <vector>
#define max(a , b) ( a < b ? b : a);
using namespace std;

/* �� ������ �α� �� */
int dist[10001];
/* ���� �׷��� */
vector<int> mat[10001];

/* ��� ������ �ִ� �α����� ���� dfs �Լ� */
int dfs(int prev, int here, bool visit) {
	int ret = 0;

	/* ��� ������ �����ؾ��� ������ ��� �ش� ������ �α��� �Է� */
	if (visit) ret = dist[here];

	/* ���� ������ ����� ���� ��ȸ */
	for (auto next : mat[here]) {
		/* �湮�ߴ� ������ �ٽ� �湮�Ϸ� �� ��� ���� */
		if (prev == next) continue;
		
		/* 
			���� ������ ��� ������ �����ؾ��� ���
			���� ������ ��� ������ �������� ����
		*/
		if (visit) ret += dfs(here, next, 0);
		/*
			���� ������ ��� ������ �������� ���� ��� 
			���� ������ ��� ������ ������ ����� ��� ������ �������� ���� ��� ��, �ִ밪�� ã����
		*/
		else
			ret += max(dfs(here, next, 0), dfs(here, next, 1));
	}

	/* ���� ��� ������ ���� ������ �ִ� �α����� ��ȯ */
	return ret;
}

int main() {
	int n, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ���� ������ �α��� �Է� */
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dist[i];

	/* ���� ���� �� ����(Ʈ�� ����) �Է� */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		/* ������ �׷����̹Ƿ� �������� ���� */
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* ���� 1�� ������ ��� ������ �������� ���� ������ ���� �ִ� �α��� */
	int v = dfs(-1, 1, 1);
	int nv = dfs(-1, 1, 0);

	/* �� �ִ� �α��� ��� */
	cout << max(v, nv);
	return 0;
}