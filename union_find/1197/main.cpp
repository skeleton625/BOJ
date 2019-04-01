#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define NMAX 10001
#define swap(a, b) { int t = a; a = b; b = t; }

/* �� ������ ���� ���� �ڷ��� ���� */
struct edge{
	int v1, v2, cost;
	bool operator < (const edge &ed) {
		return cost < ed.cost;
	}
};
int v, e;	/* ���� ����, ���� ���� ���� ���� */
int parent[NMAX], prank[NMAX]; /* ������ �θ� ��� �迭, �θ� Ʈ�� ���� �迭 ���� */
vector<edge> vers; /* �����鿡 ���� ���� �迭 ���� */

/* Ʈ���� ��Ʈ�� ã�� �Լ� */
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

/* �־��� �� ������ ���� Ʈ���� �����ִ� �Լ� */
void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;
	if (prank[a] > prank[b]) swap(a, b);
	parent[a] = b;
	if (prank[a] == prank[b]) ++prank[b];
}

/* �ּ� ���� Ʈ���� ����ġ ��ȯ �Լ� */
int kruskal() {
	long long res = 0;
	/* �� ���� ������ ����ġ�� ���� */
	sort(vers.begin(), vers.end());
	/* �� ������ �θ� ��� �ʱ�ȭ -> �ڱ� �ڽ����� */
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	/* ���� ���� ����ġ���� ������ ������ Ʈ���� �������� */
	for (edge now : vers) {
		/* ���� ������ �ٸ� ����(Ʈ��)�� ��� ���� */
		if (find(now.v1) != find(now.v2)) {
			res += now.cost;	/* �ּ� ����ġ�� ���ϱ� ���� ��� */
			merge(now.v1, now.v2);
		}
	}
	return res;
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �� ������ ����, ������ ���� �Է� */
	cin >> v >> e;
	/* Ʈ���� ���� ���� �Է� */
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vers.push_back({ a, b, c });
	}

	/* �Էµ� �׷����� �ּ� ���� Ʈ�� ����ġ ��� */
	cout << kruskal();
	return 0;
}