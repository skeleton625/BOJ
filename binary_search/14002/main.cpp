#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define NMAX 1000001

int n;				/* ���� ���� ���� ���� ���� */
int mat[NMAX];	/* ���� �迭 ���� */
int lst[NMAX];

int main() {
	int cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* ���� ���� �Է� */
	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
		lst[i] = NMAX;
	}

	/* LIS �˰��� ���� */
	for (int i = 0; i < n; ++i) {
		/* �̺� Ž���� ���� ���� ���� ���Һ��� �۰ų� ���� ���� ��ġ�� ã�� */
		auto it = lower_bound(lst, lst + cnt, mat[i]) - lst;
		/* ���� ���Ұ� ����� ���� ���ҵ� �� ���� Ŭ ���, ũ�� ���� */
		if (lst[it] == NMAX) cnt++;
		lst[it] = mat[i];
	}

	/* ���� �� ���ҵ��� ������ �ľ��� */
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (lst[i] == NMAX) break;
		++cnt;
	}

	cout << cnt;
	return 0;
}