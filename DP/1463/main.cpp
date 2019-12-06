#include <iostream>
#define min(a, b)(a < b ? a : b)
using namespace std;

int n, mat[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� Ƚ���� Ȯ���� ���� �Է� */
	cin >> n;
	/* 1���� ������� ���� Ƚ���� ��� */
	for (int i = 2; i <= n; i++) {
		/* 1�� ���� ���� */
		mat[i] = mat[i - 1] + 1;
		/* 2�� ������ ��� 2�� ������ ���� */
		if (i % 2 == 0) mat[i] = min(mat[i], mat[i / 2] + 1);
		/* 3���� ������ ��� 3���� ������ ���� */
		if (i % 3 == 0) mat[i] = min(mat[i], mat[i / 3] + 1);
	}
	
	cout << mat[n];
	return 0;
}