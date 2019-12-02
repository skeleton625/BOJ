#include <iostream>
#define max(a, b) (a < b ? b : a)
using namespace std;

int mat[10001];
int res[10001];

int main() {
	int n;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* ������ �Է� */
	for (int i = 1; i <= n; i++)
		cin >> mat[i];

	/* �� ��ġ�� �ִ밪 �ʱ�ȭ */
	res[1] = mat[1];
	res[2] = mat[1] + mat[2];

	/* �ִ밪 ��� */
	for (int i = 3; i <= n; i++) {
		/* ���� ������ ������ ���� ���� ���� ���ΰ� ���� ������ ���� ����� �ִ밪 */
		res[i] = max(res[i - 2] + mat[i], res[i - 3] + mat[i - 1] + mat[i]);
		/* ���� �ִ밪���� ������ �ִ밪�� �� Ŭ �� �����Ƿ� ��(�ι����̳� ������ �� �������� �ֱ� ����) */
		res[i] = max(res[i], res[i - 1]);
	}

	cout << res[n];
	return 0;
}