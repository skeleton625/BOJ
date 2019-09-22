#include <iostream>
#define NMAX 100
#define CMAX 10001
using namespace std;

int dp[CMAX];

int main()
{
	int n, k, val;
	cin.tie(0);
	ios::sync_with_stdio(0);

	// ���� ��, ���ϰ��� �ϴ� ���� �Է�
	cin >> n >> k;
	/*
		DP �迭�� �ǹ�
			�������� ����� ���� �� �ִ� ����( �迭 ��ȣ )�� ��쿡 ��
		dp[0]�� ���� ���̵� ���� �� �����Ƿ� 1�� �ʱ�ȭ
	*/
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		/* �Էµ� ���� ������ŭ ������ ��ġ �Է�*/
		cin >> val;
		/* 
			�Էµ� ���� ��ġ�� �������� ��ȭ�� ����
			dp[j] += dp[j - val] ��ȭ���� �ǹ�
				���� ( �迭 ��ȣ ) j�� ���� val�� ���� ���� j - val���� ���� val�� ���ϴ� ������ ���� j�� 
				���� �� ����. ��, ���� j - val�� ���� �� �ִ� ��쿡 ������ ���� val�� ����� ���� j�� 
				����µ� ���� �� �ִٴ� ���� �ǹ���
			ex) ù ��° ���� ��ġ�� 2�� ���,
				dp[2] += dp[0]; (1)
				dp[3] += dp[1]; (0)
				dp[4] += dp[2]; (1)
				dp[5] += dp[3]; (0)
				...
				�� ��° ���� ��ġ�� 5�� ���,
				dp[5] += dp[0]; (1)
				dp[6] += dp[1]; (0)
				dp[7] += dp[2]; (1) -> 2�� 5�� ����
				dp[8] += dp[3]; (1) -> 2�� ��쿡 ��
				dp[9] += dp[4]; (1) -> 2�� 5�� ����
				dp[10] += dp[5]; (2) -> 2, 5 ������ ����� ��
				...
		*/
		for (int j = val; j <= k; j++)
			dp[j] += dp[j - val];
	}

	/* ����� �Ϸ�� ����� ���� ��� */
	cout << dp[k];
	return 0;
}