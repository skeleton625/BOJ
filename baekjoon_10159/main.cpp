#include <iostream>
#include <vector>
#define INF 100
#define min(a, b) (a < b ? a : b)
using namespace std;

int main() {
	int n, m, a, b;
	/* �׷��� ������ ������ �迭 ���� */
	vector<vector<int>> mat;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	/* �׷��� �迭 �ʱ�ȭ */
	mat = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		mat[i][i] = 0;

	/* �׷��� �迭 ���� �Է� */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
	}

	/* �÷��̵� �ͼ� �˰��� ���� */
	for (int k = 1; k <= n; k++) { /* �����, ������ ���̿� ���� �ִ��� ��� ���� �Է� */
		for (int i = 1; i <= n; i++) { /* ��� ���� ������� �Է� */
			for (int j = 1; j <= n; j++) /* ��� ���� �������� �Է� */
				/* �� ���� �ִܰŸ� ���� -> �� �࿡�� ���ŵ� ��ȣ���� ����Ǿ� �ִ� ��ȣ�� */
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		}
	}

	/* �� ���� ����Ǿ� �ִ� ������ ������ */
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != INF) {
				/* mat[i][j]�� �ʱ� ���� �ƴϹǷ� i�� j�� ����Ǿ� �ִ� ���� */
				result[i]++;
				result[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << (n - result[i] + 1) << '\n';

	return 0;
}