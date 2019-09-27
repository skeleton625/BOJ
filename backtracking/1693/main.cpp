#include <algorithm>
#include <iostream>
#include <vector>
#define LMAX 100001		/* �ִ� ��� ���� ���� */
#define COLOR 18		/* �� ���� ���� �� �ִ� �ִ� �� ���� ���� */
#define INF 987654321	/* ������ ���� �ִ밪 ���� */
using namespace std;

int n;
int cache[LMAX][COLOR];
vector<int> mat[LMAX];

void dfs(int prev, int here) {
	/* ���� ���� ��� ��ġ �ʱⰪ �ʱ�ȭ */
	cache[here][0] = INF;
	/* ���� ��ġ���� �� ���� ���� ��� �ʱ�ȭ */
	for (int i = 1; i < COLOR; i++) cache[here][i] += i;
	/* ���� ���� ����Ǿ� �ִ� ��� ��ȸ */
	for (auto next : mat[here]) {
		/* ���� ���� ��尡 �θ� ����� ��� ���� */
		if (prev == next) continue;
		
		/* dfs �˰����� ���� �ڽ� ���� ��� */
		dfs(here, next);
		/* ���� ���� �� ��ȣ, �� �������� ���� �� ��ȣ ���� */
		int fst = 0, snd = 0;
		/* ���� ���� ���� ����� ���� ���� ���� �� ��ȣ�� �� �������� ���� �� ��ȣ�� ���� */
		for (int i = 1; i < COLOR; i++) {
			if (cache[next][snd] > cache[next][i]) snd = i;
			if (cache[next][fst] > cache[next][snd]) swap(fst, snd);
		}

		/* �� ���� ���� ����� ������ (�ּҰ��� �� �� �ֵ��� ���) */
		for (int i = 1; i < COLOR; i++) cache[here][i] += cache[next][i != fst ? fst : snd];
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* Ʈ�� ���� ���� */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* Ʈ���� ��ȸ�� dfs �˰��� ���� */
	dfs(0, 1);
	/* ��� Ʈ���� ��ȸ�ϰ� ������ ���� ���� �ּҰ��� ��� */
	cout << *min_element(cache[1] + 1, cache[1] + 18);
	return 0;
}