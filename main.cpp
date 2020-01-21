#include <iostream>
#include <algorithm>
using namespace std;

int n;
int mat[1000][3];
int pre_cost[3], next_cost[3];

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �� ���� �� ���� RGB ���� ����� �Է� */
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i][0] >> mat[i][1] >> mat[i][2];

	/* ���� �� RGB�� ���� ��� �ʱ�ȭ */
	pre_cost[0] = mat[0][0];
	pre_cost[1] = mat[0][1];
	pre_cost[2] = mat[0][2];

	/* ���� ���� ���� ���� ���� ���� ĥ������ �ʵ��� �ϸ鼭 �ּҰ� �ǵ��� ��� */
	for (int i = 1; i < n; i++) {
		next_cost[0] = min(pre_cost[1], pre_cost[2]) + mat[i][0];
		next_cost[1] = min(pre_cost[0], pre_cost[2]) + mat[i][1];
		next_cost[2] = min(pre_cost[0], pre_cost[1]) + mat[i][2];
		for (int j = 0; j < 3; j++)
			pre_cost[j] = next_cost[j];
	}

	/* ���� ����� ���� ���� ���� ��� */
	cout << min({ pre_cost[0], pre_cost[1], pre_cost[2] });

	return 0;
}