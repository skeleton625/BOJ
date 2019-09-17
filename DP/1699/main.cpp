#include <iostream>
#define INF 100001
#define MIN(a, b) ( a < b ? a : b )
using namespace std;

int dp[INF];

int main()
{
	int n;
	cin.tie(0);
	ios::sync_with_stdio(0);

	/* �ּ� �������� �� ������ ���ϰ��� �ϴ� ���ڸ� �Է� */
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		/* ���� i�� ���� �ּ� �������� �� ������ i�� �ʱ�ȭ */
		dp[i] = i;
		/* ���� i���� ���� �������� ���� �ּ� �������� ���� */
		for (int j = 1; j * j <= i; j++)
			dp[i] = dp[i - j * j] + 1);
	}

	cout << dp[n];
	return 0;
}