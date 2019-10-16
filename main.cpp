#include <algorithm>
#include <iostream>
#include <vector>
#define max(a, b) (a < b ? b : a);
using namespace std;

int n;
int dist[10001];
vector<int> mat[10001];
vector<int> vers;
vector<vector<int>> acc;

/* ������ ������ �ִ밪�� ����ϴ� �Լ� */
int dfs(int prev, int here, bool visit) {
	/* visit�� ���� ������ ���� ����ġ �ּ� ���� */
	int &ret = acc[here][visit];

	/* �̹� ������ �� ��� */
	if (ret != -1)
		return ret;

	/* ���� �湮�ؾߵǴ� ���� ���� ������ ����ġ ���� */
	if (visit) ret = dist[here];
	/* �湮���� ���ƾ� �ϴ� ������ ��� 0�� ���� */
	else ret = 0;

	/* ����� �����鰣�� Ȯ�� */
	for (auto next : mat[here]) {
		/* �湮�ߴ� ������ �ٽ� �湮�Ϸ� �� ��� ���� */
		if (prev == next) continue;

		/* ���� ������ �湮�ؾ��� ���, ���� ������ �湮�ϸ� �ȵǹǷ� visit�� 0���� ������ ��� ���� */
		if (visit)
			ret += dfs(here, next, 0);
		/* ���� ������ �湮�ϸ� �ȵ� ���, ���� ������ �湮�ϰų� �湮���� ���� ��� �� �ִ밪�� �Է� */
		else
			ret += max(dfs(here, next, 0), dfs(here, next, 1));
	}

	return ret;
}

/* �ִ밪 ��꿡 ���Ǵ� ������ ã�� �Լ� */
void trace(int prev, int here, int visit) {
	/*
		�ش� ������ �湮�ϴ� ��� �ִ� ���� �迭�� ������ �Է�
		����� ���� ������ ã��
	*/
	if (visit) {
		vers.push_back(here);
		for (auto next : mat[here]) {
			/* �湮�ߴ� ������ �ٽ� �湮���� �ʵ��� ���� */
			if (prev == next) continue;
			trace(here, next, 0);
		}
	}
	/*
		�ش� ������ �湮���� ���� ���
		���� ������ �湮�� �Ϳ� �湮���� ���� �� ��, �� ū ���� ã��
		�ش� �������� �̵�
	*/
	else {
		for (auto next : mat[here]) {
			if (prev == next) continue;

			/* ���� ������ �湮���� ���� ���� �� Ŭ ���, �湮���� ���� */
			if (acc[next][0] >= acc[next][1])
				trace(here, next, 0);
			/* ���� ������ �湮�ϴ� ���� �� Ŭ ���. �湮�� */
			else
				trace(here, next, 1);
		}
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ������ ���� �Է�, �� ������ ���� ����ġ �ʱ�ȭ */
	cin >> n;
	acc = vector<vector<int>>(n + 1, vector<int>(2, -1));
	/* �� ������ ����ġ �Է� */
	for (int i = 1; i <= n; i++)
		cin >> dist[i];

	/* Ʈ���� ���� �Է� */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* ���� 1�� �ִ밪 ��꿡 ����� ��� */
	int v = dfs(-1, 1, 1);
	/* ���� 1�� �ִ밪 ��꿡 ������� ���� ��� */
	int nv = dfs(-1, 1, 0);

	/* ���� 1�� �湮�� ���� �� Ŭ ���, ���� 1�� �ִ� ���� �迭�� ������ �ٸ� ������ ã�� */
	if (v >= nv) {
		cout << v << '\n';
		trace(-1, 1, 1);
	}
	/* ���� 1�� �湮���� �ʴ� ���� �� Ŭ ���, ���� 1�� ����� �ٸ� �ִ� ������ ã�� */
	else {
		cout << nv << '\n';
		trace(-1, 1, 0);
	}

	/* �ִ� ���� �迭�� ������������ ���� */
	sort(vers.begin(), vers.end());
	/* �ִ� ���� �迭 ��� */
	for (auto ver : vers)
		cout << ver << ' ';

	return 0;
}