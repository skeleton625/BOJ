#include <iostream>
#include <vector>
#define MMAX 16
#define NMAX 1000000001
#define MIN(a, b) ( a < b ? a : b )
using namespace std;

int n;
vector<vector<int>> mat, cash;

// ��� ���ø� ��ȸ�ϴ� ����� �ּ� ���� ����ϴ� �Լ�
int calcMinPath(int p, int path) {
	// ���� ��� ��θ� ��ȸ�� ���
	if (path == (1 << n) - 1)
		// ���� ���÷� �̵��ϴ� ��ΰ� ���� ��� �� �����, �׷��� ���� ��� �ִ밪�� ��ȯ
		return mat[p][0] ? mat[p][0] : NMAX;
	// ���� ���ÿ� ��ο� ���� ��� ĭ�� ������
	int& ret = cash[p][path];
	// ���� ���� ��� ĭ�� ���� ������ ��� �ּҰ��̹Ƿ� ��ȯ
	if (ret != -1) return ret;
	// �׷��� ���� ��� �ִ밪���� �ʱ�ȭ
	ret = NMAX;
	for (int i = 0; i < n; i++) {
		// ���� ���� ���ð� ������ ���ðų� ��ΰ� �������� ���� ��� ����
		if ((path & 1 << i) || mat[p][i] == 0) continue;
		// ó�� �̵��ϴ� ������ ���,���� ��ΰ� �ϼ��� ���� ���� ����� ���� �ּҰ��� �Է�
		ret = MIN(ret, calcMinPath(i, path | 1 << i)+mat[p][i]);
	}
	// ���� ���� ����� �ּҰ��� ��ȯ
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	// ������ �̵���� �迭 �ʱ�ȭ
	mat = vector<vector<int>>(n, vector<int>(n, 0));
	// i ���ÿ��� j ���÷� �̵��ϴ� ��� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	// �� ���÷� �̵��ϴ� ����� ����� �� �ʱ�ȭ
	cash = vector<vector<int>>(n, vector<int>(1 << n, -1));

	// ��� ���ø� ��ȸ�ϴ� �ּ� ����� ���
	cout << calcMinPath(0, 1);
	return 0;
}