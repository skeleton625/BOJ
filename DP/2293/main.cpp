#include <iostream>
using namespace std;

int cost[100];	/* 동전의 가치 배열 */
int dp[10001];	/* 동전 가치를 통해 만들 수 있는 동전 경우의 수 배열 */

int main() {
	int n, k;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 동전 개수와 경우의 수를 구할 동전 가치 입력 */
	cin >> n >> k;
	/* 동전 가치 정보 입력 */
	for (int i = 0; i < n; i++) cin >> cost[i];

	/* 시작 위치 초기화 */
	dp[0] = 1;
	/* 동전 경우의 수 계산 */
	for (int i = 0; i < n; i++) {
		for (int j = cost[i]; j <= k; j++)
			dp[j] += dp[j - cost[i]];
	}

	/* 목적 가치의 경우의 수 출력 */
	cout << dp[k];
	return 0;
}