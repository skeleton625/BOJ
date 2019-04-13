#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 1000001
#define EMP 100

int n;
/* ���� Ƚ�� �迭 ���� */
int dp[NMAX] = { 0, 0, 1, 1 };
/* ���� ��� �迭 ���� */
int trace[NMAX] = { 0, 0, 1, 1 };

/* 
	i�� ���� �������� DP ���̽��� �� �ټ������� ������
	1. (i-1)�� 2�� ���� �������� ���
	2. i�� 6���� ���� �������� ��� -> �� ���� 3���� ������ ���� Ƚ���� ���� �� ����
	3. i�� 2�� ���� �������� ���
	4. i�� 3���� ���� �������� ���
	5. �� �� i�� 2, 3 ���� ���� �������� �ʴ� ���̽�
		i - 1, i - 2, (i - 1)/2 -> 1 ���� �������Ƿ� ����
*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ���̽� ���� 5�� ���� */
	int a, b, c, d, e;
	cin >> n;
	/* 3������ ���ǵǾ� �����Ƿ� 4���� ���� */
	for (int i = 4; i <= n; i++) {
		/* 5���� ���̽� �ʱ�ȭ */
		a = EMP, b = EMP, c = EMP, d = EMP, e = EMP;
		/* ù ��° ���̽� */
		if ((i - 1) % 3 == 0) a = dp[(i - 1) / 3] + 2;
		/* �� ��° ���̽� */
		if (i % 6 == 0) b = dp[i / 3] + 1;
		/* �� ��° ���̽� */
		if (i % 2 == 0) c = dp[i / 2] + 1;
		/* �� ��° ���̽� */
		if (i % 3 == 0) d = dp[i / 3] + 1;
		/* �ټ� ��° ���̽� */
		e = min({ dp[i - 1] + 1, dp[i - 2] + 2, dp[(i - 1) / 2] + 2, EMP });
		/* 5���� ���̽� �� �ּҰ��� ���� dp�� ���� */
		dp[i] = min({ a, b, c, d, e });

		/* ���� dp�� �´� ���̽��� trace�� �������� */
		if (dp[i] == a) {
			trace[i] = i - 1;
			trace[i-1] = (i - 1)/3;
		}
		else if (dp[i] == b) trace[i] = i / 3;
		else if (dp[i] == c) trace[i] = i / 2;
		else if (dp[i] == d) trace[i] = i / 3;
		else if (dp[i] == e) {
			if (e == dp[i - 1] + 1) trace[i] = i - 1;
			else if (e == dp[i - 2] + 2) {
				trace[i] = i - 1;
				trace[i - 1] = i - 2;
			}
			else {
				trace[i] = i - 1;
				trace[i - 1] = (i - 1) / 2;
			}
		}
	}

	cout << dp[n] << '\n';
	while (n != 1) {
		cout << n << ' ';
		n = trace[n];
	}
	cout << 1;
	return 0;
}