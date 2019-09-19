#include <iostream>
using namespace std;
#define INF 1001
#define MAX( a, b ) ( a < b ? b : a )

int main()
{
	int n;
	cin.tie(0);
	ios::sync_with_stdio(0);

	int mat[INF], dp[INF];

	/* ������ ���� �Է� */
	cin >> n;
	/* ���� �Է� */
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	/* �����ϴ� �κ� ������ �� �ִ밪 */
	int res = 0;
	/* ������ ��� ���� ĭ�� ���� �ݺ� */
	for (int i = 0; i < n; i++)
	{
		/* �� ������ dp�� �ڱ� �ڽ��� ������ �ʱ�ȭ */
		dp[i] = mat[i];
		/* ù ��° ������ dp���� ���� */
		for (int j = 0; j < i; j++)
		{
			/*
				���� ���Ұ� ������ �Ǵ� ���Һ��� ���� ���,
				�׸��� ������ �Ǵ� ������ dp�� ���� ������ dp�� ���� ���� ���� ���� ������ ���� ���
			*/
			if (mat[j] < mat[i] && dp[i] < dp[j] + mat[i])
				/* �� ���� ���� ���� */
				dp[i] = dp[j] + mat[i];
		}
		/* ���� ������ dp�� ��������� �ִ밪���� ū�� Ȯ�� ��, ���� */
		res = MAX(res, dp[i]);
	}

	/* �ִ밪 ��� */
	cout << res;
	return 0;
}