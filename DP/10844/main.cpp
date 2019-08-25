#include <iostream>
#define REST 1000000000	// 
#define IMAX 101		// ���ڿ� �ִ� ����
#define NMAX 10			// �� �ڸ��� ���ڵ�
using namespace std;

/* �� ���ڿ����� ù ��° �ڸ� ���ڵ��� ����� �� */
int nums[IMAX][NMAX];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	/* ù ��° �ڸ��� �ʱ�ȭ */
	for (int i = 1; i < NMAX; i++)
		nums[1][i] = 1;

	/* �� ��° �ڸ����� ��� ���� */
	for (int i = 2; i <= n; i++)
	{
		/* ���� �ڸ� ������ 0�� ��쿡 �� */
		nums[i][0] = nums[i - 1][1];
		/* ���� �ڸ� ������ 1~ 8�� ��쿡 �� */
		for (int j = 1; j < NMAX; j++)
		{
			nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j + 1];
			nums[i][j] %= REST;
		}
		/* ���� �ڸ� ������ 9�� ��쿡 �� */
		nums[i][NMAX - 1] = nums[i - 1][NMAX-2];
	}
	/* ���� �ڸ� �������� ��� ����� �� ��� */
	int res = 0;
	for (int i = 0; i < NMAX; i++)
	{
		res += nums[n][i];
		res %= REST;
	}

	cout << res;
	return 0;
}