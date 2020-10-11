#include <iostream>
#include <cstring>
using namespace std;

int n, c;
/* ��, ���� �밢��, ������ �밢��*/
/*
	queen�� ��,�� �밢���� ��, ���� �̵��� �� �ִ�
	���⼭ queen_col�� �ش� ��(��)���� queen�� ��ġ�� ��ȣ,
	queen_right_up�� �ش� ��(��)���� queen�� ������ �밢������ ������ �� �ִ� ĭ,
		-> ����� �ش� �밢�� ĭ�� �ش� ���� + queen�� ��ġ�� �� ��ȣ �̴�.
	queen_left_up�� �ش� ��(��)���� queen�� ���� �밢������ ������ �� �ִ� ĭ �̴�.
		-> ����� �ش� �밢�� ĭ�� ��ü ���� - 1 + (�ش� ���� - queen�� ��ġ�� �� ��ȣ) �̴�.
*/
/* ü����(2�����迭)���� ��, �� �밢���� ������ ���� 2*n-1�� */
bool *queen_col, *queen_right_up, *queen_left_up;

void count_queen_pos(int floor) {
	if (floor == n) {
		c++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (queen_col[i] || queen_right_up[floor + i] || queen_left_up[n - 1 + floor - i])
			continue;
		queen_col[i] = queen_right_up[floor + i] = queen_left_up[n - 1 + floor - i] = 1;
		count_queen_pos(floor+1);
		queen_col[i] = queen_right_up[floor + i] = queen_left_up[n - 1 + floor - i] = 0;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	queen_col = new bool[n];
	queen_right_up = new bool[2 * n - 1];
	queen_left_up = new bool[2 * n - 1];

	memset(queen_col, 0, sizeof(bool)*n);
	memset(queen_right_up, 0, sizeof(bool)*(2*n-1));
	memset(queen_left_up, 0, sizeof(bool)*(2*n-1));

	count_queen_pos(0);
	cout << c;

	return 0;
}