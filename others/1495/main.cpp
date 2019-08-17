#include <iostream>
using namespace std;

int vols[101][1001];
int n, s, m;

int main()
{
	int pre, plus, minus;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> pre;
		for (int j = 0; j <= m; j++)
		{
			/* ���� ������ �ƴ� ������ �ǳ� �� */
			if (!vols[i][j]) continue;
			/* ���� ������ ���� ���Ҹ� ����( 0~m ���� ) */
			plus = pre + j;
			minus = pre - j;
			if (plus <= m) vols[i][plus] = true;
			if (minus >= 0) vols[i][minus] = true;
		}
	}

	/* ������ �������� ���� ���� ���� ��� ��� */
	for (int i = m; i >= 0; i--)
	{
		if (vols[n][i]) {
			cout << i;
			return 0;
		}
	}
	/* ���� ��� -1�� ��� */
	cout << -1;
	return 0;
}