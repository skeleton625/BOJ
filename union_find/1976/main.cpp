#include <iostream>
#define NMAX 201
#define swap(a, b) { int t = a; a = b; b = t; }
using namespace std;

int n, m;
int parent[NMAX];	/* �� ��忡 ���� ��Ʈ ��� �迭  */
int prank[NMAX];	/* �� ��忡 ���� �ڽ� ���� �迭 */

int find(int a) {
	/* ���� ����� ��Ʈ ��尡 �ڱ� �ڽ��� ��� �ְ� ����� ����� */
	if (a == parent[a]) return a;
	/* 
		�ƴ� ��� �θ� ���� �̵��� ��Ʈ ��带 ã��
		����, �ڽ��� �θ� ��带 �ش� Ʈ���� ��Ʈ ���� ��������
			-> Ž�� �ӵ��� �� ������ ���ֱ� ����.
	*/
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	/* ��� a, b�� ��Ʈ ��带 ã���� */
	int n1 = find(a), n2 = find(b);
	
	/* �� ����� ��Ʈ ��尡 ���� ��� ���� Ʈ���� ���ߴٴ� ���̹Ƿ� ��� ���� */
	if (n1 == n2) return;
	/* �� ��Ʈ ��� ��, ���̰� �� ū ������ �պ��� ������ */
	if (prank[n1] > prank[n2]) swap(n1, n2);
	parent[n1] = n2;

	/* ���� �� ����� ���̰� ���� ���, �պ��� ������ ����� ���̸� �������� �� */
	if (prank[n1] == prank[n2]) ++prank[n2];
}

int main() {
	int c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* �� ���鿡 ���� ��Ʈ ��带 �ʱ�ȭ */
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	/* ��� �׷����� ���� ���� �Է� */
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> c;
			/* i�� j���� ���� ���� ���� ��忡�� ���� ������ �Է��� ��� */
			if (j > i && c == 1) merge(i, j);
		}
	}

	/* ����� ������ �Է� */
	cin >> c;
	/* ������ �θ� ������  �ľ��ϱ� ���� ��Ʈ ��带 ���� */
	int root = find(c);
	for (int i = 1; i < m; i++) {
		cin >> c;
		/* ��Ʈ ��尡 �ٸ� ��� "NO"�� ��� */
		if (root != find(c)) {
			cout << "NO";
			return 0;
		}
	}

	/* ��� ����� ��Ʈ ��尡 ���� ��� "YES"�� ��� */
	cout << "YES";
	return 0;
}