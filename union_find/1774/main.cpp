#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 1001
#define swap(a, b) { int t = a; a = b; b = t; }

/* ���� ������ ���� ���� ���� */
struct ver {
	int x, y;
};
/* �� ���� ���� ���� ���� ���� */
struct god {
	int g1, g2;
	double len;
	bool operator < (const god &g) { return len < g.len; }
};

/* �� ����, �̹� ����� ���� ���� ���� ���� */
int n, m;
/* �� ������ ���� ������ ��Ʈ ���� ��ȣ �迭, ���� �迭 ���� */
int parent[NMAX], prank[NMAX];
/* �� �ŵ��� ��ǥ �迭 ���� */
ver dots[NMAX];
/* ��� ���� ���� �迭 ���� */
vector<god> dist;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;
	if (prank[a] > prank[b]) swap(a, b);
	parent[a] = b;
	if (prank[a] == prank[b]) ++prank[b];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* �� �ŵ��� ��ǥ �Է�, �� �ŵ��� ���� ���� �ʱ�ȭ */
	for (int i = 1; i <= n; i++) {
		cin >> dots[i].x >> dots[i].y;
		parent[i] = i;
	}

	int a, b;
	/* �̹� ����� �ŵ��� ���� ��ȣ �Է�. ������ �պ����� */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	/* �� �������� �����ؼ� ���� �� �ִ� ��� ������ ���� */
	double lx, ly, len;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			lx = dots[i].x - dots[j].x;
			ly = dots[i].y - dots[j].y;

			len = sqrt(lx * lx + ly * ly);
			dist.push_back({ i, j, len });
		}
	}

	/* ������ ��� �������� ������������ ���� */
	sort(dist.begin(), dist.end());

	double res = 0;
	/* 
		������ ��� �������� �ּҺ��� ������� �պ�����
		�ش� ������ �̹� ���� ���� ������ ��� �պ� ����
	*/
	for (god now : dist) {
		if (find(now.g1) != find(now.g2)) {
			merge(now.g1, now.g2);
			/* ���� �պ��� ��� ���� ���� �߰� */
			res += now.len;
		}
	}

	/* ���� �������� ������ ���� ��� */
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << res;
	return 0;
}