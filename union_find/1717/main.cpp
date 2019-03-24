#include <iostream>
#define NMAX 1000001 /* ����� �ִ� ���� */
using namespace std;

int n, m;
/* �� ��忡 ���� ������ �θ� ��带 ������ �迭 ���� */
int mat[NMAX], prank[NMAX];

int find(int a) {
	/* ���� ����� �θ� ��尡 �ڱ� �ڽ��� ���, �� ��Ʈ ��� */
	if (a == mat[a]) return a;
	/* ���� ��Ʈ ��尡 �ƴϹǷ� �θ� ���� �̵� */
	return mat[a] = find(mat[a]);
}

void merge(int a, int b) {
	/* �Ű����� a, b ����� ��Ʈ ��带 ã�� */
	int n1 = find(a), n2 = find(b);

	/* ��Ʈ ��尡 ���� ���, ���� ���տ� ���� �����Ƿ� �պ� ���� */
	if (n1 == n2) return;
	
	/* �� ���� ��, ������ ���̰� �� ū ���� �ľ��� */
	if (prank[n1] > prank[n2]) swap(n1, n2);
	/* ���̰� �� ū ���տ� ���� ������ ������ */
	mat[n1] = n2;
	/* �� ������ ũ�Ⱑ ���� ��� �������� ���� ���̸� 1 �������� �� */
	if (prank[n1] == prank[n2]) ++prank[n1];
}

int main() {
	int u, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ������ �ִ� ����, ���� ����� ã�� ���� ���� �Է� */
	cin >> n >> m;
	/* �� ����� �θ� ��带 �ڱ� �ڽ����� �ʱ�ȭ */
	for (int i = 1; i <= n; i++) mat[i] = i;

	/* ���� ���� */
	for (int i = 0; i < m; i++) {
		cin >> u >> a >> b;
		/* ó�� ���� 0�� ��� �պ� �õ� */
		if (u == 0) {
			merge(a, b);
		} 
		/* ó�� ���� 1�� ��� �Էµ� �� ��� ��ȣ�� ���� ���տ� �ִ��� Ȯ�� */
		else {
			/* ���� ��� "YES"�� ��� */
			if (find(a) == find(b)) cout << "YES\n";
			/* �׷��� ���� ��� "NO"�� ��� */
			else cout << "NO\n";
		}
	}
	return 0;
}