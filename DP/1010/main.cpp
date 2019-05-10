#include <iostream>
using namespace std;
#define NMAX 31

int ncr[NMAX][NMAX];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ���� 1�� �� ���, ����, ������ �� ������ ������ ��� �ٸ� ���� �ʱ�ȭ */
	for (int i = 1; i < NMAX; i++) {
		ncr[1][i] = i;
		ncr[i][i] = 1;
	}

	/* ��� ����, ������ �� ������ ���� �ٸ��� ������ ��� */
	for (int i = 1; i < NMAX; i++) {
		for (int j = i + 1; j < NMAX; j++) {
			for (int k = j; k >= i; k--)
				ncr[i][j] += ncr[i-1][k-1];
		}
	}

	int t, a, b;
	/* �׽�Ʈ ���̽� �� �Է� */
	cin >> t;
	while (t--) {
		/* ����, ������ �� ���� �Է� */
		cin >> a >> b;
		/* �׿� ���� ��ü �ٸ� ����� �� ��� */
		cout << ncr[a][b] << '\n';
	}

	return 0;
}