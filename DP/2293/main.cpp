#include <iostream>
using namespace std;

int cost[100];	/* ������ ��ġ �迭 */
int dp[10001];	/* ���� ��ġ�� ���� ���� �� �ִ� ���� ����� �� �迭 */

int main() {
	int n, k;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ������ ����� ���� ���� ���� ��ġ �Է� */
	cin >> n >> k;
	/* ���� ��ġ ���� �Է� */
	for (int i = 0; i < n; i++) cin >> cost[i];

	/* ���� ��ġ �ʱ�ȭ */
	dp[0] = 1;
	/* ���� ����� �� ��� */
	for (int i = 0; i < n; i++) {
		for (int j = cost[i]; j <= k; j++)
			dp[j] += dp[j - cost[i]];
	}

	/* ���� ��ġ�� ����� �� ��� */
	cout << dp[k];
	return 0;
}