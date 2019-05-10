#include <iostream>
using namespace std;
#define NMAX 100000
#define MAX(a, b) ( (a) < (b) ? (b) : (a) )

int main() {
	int t, n;
	/* ��ƼĿ ���� �迭, �ش�ĭ ��ƼĿ ���� �ִ밪 �迭 ���� */
	int mat[2][NMAX], ans[2][NMAX];
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �׽�Ʈ ���̽� �� �Է� */
	cin >> t;
	while (t--) {
		/* �� ���� ��ƼĿ �� �Է� */
		cin >> n;
		/* ��ƼĿ ���� ���� �Է� */
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		}

		/* �ʱ�ĭ ��ƼĿ ���� �ִ밪 �ʱ�ȭ */
		ans[0][0] = mat[0][0], ans[1][0] = mat[1][0];
		ans[0][1] = ans[1][0] + mat[0][1], ans[1][1] = ans[0][0] + mat[1][1];

		/* ��ƼĿ ���� �ִ밪 ��� */
		for (int i = 2; i < n; i++) {
			/*2���� ��ƼĿ�� �������� ��, �ִ밪 ��� */
			ans[0][i] = mat[0][i] + MAX(ans[1][i - 1], ans[1][i - 2]);	/* ���� �밢�� Ȥ�� �� ���� �� ��, ���� ū ���� ������ */
			ans[1][i] = mat[1][i] + MAX(ans[0][i - 1], ans[0][i - 2]);
		}

		/* ���������� ������ �� ���� �ִ밪 �� ���� ū ���� ��� */
		cout << MAX(ans[0][n - 1], ans[1][n - 1]) << '\n';
	}

	return 0;
}