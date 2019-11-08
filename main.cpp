#include <iostream>
using namespace std;

int n;
/* ��� ��ȣ�� ��ġ, ����Ʈ ���� �迭 ���� */
int pos[100001], post[100001];

void put_pre_order(int is, int ie, int ps, int pe) {
	/* �ο���, ����Ʈ���� ������ ���� �ʰ��� ��� ���� */
	if (is > ie || ps > pe) return;

	/* ���� ��ġ�� ��Ʈ ��� ��� */
	int root = post[pe];
	cout << root << ' ';

	/*
		Ʈ���� ����, ������ ���  ��ȸ ����
		�ο��� ���� ��� ����(is ~ pos[root] - 1), ������ ��� ����(pos[root] + 1, ie)
		����Ʈ���� ���� ��� ����(ps ~ ps + pos[root] - is - 1), ������ ��� ����(ps + pos[root] - is, pe - 1)
	*/
	put_pre_order(is, pos[root] - 1, ps, ps + pos[root] - is - 1);
	put_pre_order(pos[root] + 1, ie, ps + pos[root] - is, pe - 1);
}

int main() {
	int in;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* Ʈ���� �ο��� ������ �Է� */
	for (int i = 0; i < n; i++) {
		cin >> in;
		pos[in] = i;
	}

	/* Ʈ���� ����Ʈ���� ������ �Է� */
	for (int i = 0; i < n; i++)
		cin >> post[i];

	/* Ʈ���� �������� ��� */
	put_pre_order(0, n - 1, 0, n - 1);
	return 0;
}