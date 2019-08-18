#include <iostream>
#define REST 10007
#define NMAX 1001
using namespace std;

int dp[NMAX][NMAX];

int main()
{
	int n, k;
	cin.tie(0);
	ios::sync_with_stdio(false);

	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	cin >> n >> k;
	/* ���� ��� ù ��° ����� �� */
	for (int i = 1; i <= n; i++)
	{
		/* ���� ��� �� ��° ����� �� */
		for (int j = 0; j <= i; j++)
		{
			/* ����� ù ��°�� ���� 1�� ���� */
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
			{
				/* �߰��� ���� ���� ����� ���� ��� - ��ȭ�� */
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][j] %= REST;
			}
		}
	}
	/* �Էµ� ���� ����� ����� ��� */
	cout << dp[n][k];
	return 0;
}