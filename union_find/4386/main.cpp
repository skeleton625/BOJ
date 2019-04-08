#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 101
#define swap(a, b) { int t = a; a = b; b = t; }

/* �� ���� �ڷ��� ���� */
struct ver {
	double x, y;
};

/* �� �� ������ ���� ���� �ڷ��� ���� */
struct star {
	int s1, s2;
	double len;
	/* �������� ������ ���� operator ���� */
	bool operator < (const star &s) { return len < s.len; }
};

int n;
/* 
	union find�� �����ϱ� ����
	������ ���� ������ ��Ʈ ��ȣ �迭
	������ ���� ������ Ʈ�� ���� �迭
*/
int parent[NMAX], prank[NMAX];
ver info[NMAX];
vector<star> mat;

/* �� ���� a�� ���� ������ ��Ʈ ��ȣ�� ��ȯ�ϴ� �Լ� */
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

/* �� ���� a, b�� ���� �� ������ �����ִ� �Լ� */
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

	/* ���� ���� �Է� */
	cin >> n;
	/* �� ������ ��ġ �Է� */
	for (int i = 1; i <= n; i++) {
		cin >> info[i].x >> info[i].y;
		parent[i] = i;
	}

	double lx, ly, len;
	/* ��� �����鿡�� ���� �� �ִ� ���� ��� */
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			lx = info[i].x - info[j].x;
			ly = info[i].y - info[j].y;

			len = sqrt(lx*lx + ly * ly);
			mat.push_back({ i, j, len });
		}
	}

	/* ��� �������� ������������ ���� */
	sort(mat.begin(), mat.end());

	double res = 0;
	/* 
		��� �����鿡 ���ؼ� ���̰� �ּ��� �������� �������� ����
		�������� ������ ������ ���̸� ������
	*/
	for (star now : mat) {
		if (find(now.s1) != find(now.s2)) {
			merge(now.s1, now.s2);
			res += now.len;
		}
	}

	/* �ϼ��� ���ڸ� ������ ���� ��� */
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << res;
	return 0;
}