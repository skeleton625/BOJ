#include <iostream>
#include <stack>
using namespace std;
#define NMAX 200001
#define swap(a, b) { int t = a; a = b; b = t; }

/* ������ ���� �θ� ���, ������ ��ü �θ� ��� �迭 ���� */
int parent[NMAX], graph[NMAX];
/* �� ������ Ʈ�� ����, ���ǿ� ���� ������ ���� �迭 ���� */
int prank[NMAX], query[NMAX*2][2];

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
	int n, q, a;
	stack<bool> res; /* ���� ����� �����ϴ� stack */
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ������ ������ ���� ���� �Է� */
	cin >> n >> q;
	/* 
		��Ʈ�� �׻� 1�̹Ƿ� 1�� ���� �θ�� �������� ����
		������ ���̱� ���� 2���� ����
	*/
	graph[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		parent[i] = i;	/* ���� ������ �θ� ���� �ʱ�ȭ */
		graph[i] = a;	/* ������ �θ� ���� �Է� */
	}

	/* ���ǿ� ���� ������ �迭�� �Է� */
	for (int i = 1; i <= n + q - 1; i++) {
		cin >> a;
		/* 
			ù ��° �Է� ���� 1�� ��� �Է� �� 2 ��
			-> �� ������ �����ϴ� ������ �����ϴ°�
		*/
		if (a) cin >> query[i][0] >> query[i][1];
		/*
			ù ��° �Է� �� �� 0�� ��� �Է� �� 1 ��
			-> ������ �θ� ������ ������ ����
		*/
		else cin >> query[i][0];
	}

	/* Ʈ�� ���� ���� ������ �ݴ�� ������ Ʈ���� ������ �������� ���� */
	for (int i = n + q - 1; i; i--) {
		/* 
			���� ���ǿ��� ù ��° �Է��� 1�� ���
			-> �� ������ �����ϴ� ������ �����ϴ��� Ȯ���ϴ� ����
		*/
		if (query[i][1]) {
			/* �� ������ ���� Ʈ�� ���� ������ ��� ������ �����ϴ� ���� */
			if (find(query[i][0]) == find(query[i][1])) res.push(true);
			/* ���� Ʈ�� ���� �������� ���� ��� ������ �������� ���� */
			else res.push(false);
		}
		/* 
			���� ���ǿ��� ù ��° �Է��� 0�� ���
			-> ���� ������ �θ� �������� ������ ����
			-> ���� �ݺ������� ���� ������ �ݴ�� �����ϰ� �����Ƿ� �ٽ� ������
		*/
		else
			merge(query[i][0], graph[query[i][0]]);
	}

	/* �Էµ� ���ǿ� ���� �ݴ�� ���� �Է������Ƿ� stack�� ���� �Էµ� �ݴ�� ��� */
	while (!res.empty()) {
		cout << (res.top() ? "YES" : "NO") << '\n';
		res.pop();
	}

	return 0;
}

