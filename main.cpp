#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int res[500][500], mat[500][500];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n1, n2;
	/* �ﰢ���� ũ��� �ﰢ�� ����� ���� �Է� */
	cin >> n >> mat[0][0];
	/* �ﰢ���� ����� �ִ밪�� �ʱ�ȭ���� */
	res[0][0] = mat[0][0];
	for (int i = 1; i < n; i++) {
		/* �ﰢ���� �� ���� ������ �Է� */
		for (int j = 0; j <= i; j++)
			cin >> mat[i][j];

		/* �� ���� �ִ밪���� �������� ���� ���� �ִ밪�� ��� */
		for (int j = 0; j < i; j++) {
			n1 = res[i - 1][j] + mat[i][j];
			n2 = res[i - 1][j] + mat[i][j + 1];
			if (res[i][j] < n1) res[i][j] = n1;
			if (res[i][j + 1] < n2) res[i][j + 1] = n2;
		}
	}

	/* ������ �ٿ��� �ִ밪�� �ľ�, �ִ밪�� ����� */
	sort(res[n - 1], res[n - 1] + n);
	cout << res[n - 1][n - 1];

	return 0;
}