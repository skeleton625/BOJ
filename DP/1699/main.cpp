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

	/* 최소 제곱수의 합 개수를 구하고자 하는 숫자를 입력 */
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		/* 숫자 i에 대한 최소 제곱수의 합 개수를 i로 초기화 */
		dp[i] = i;
		/* 숫자 i보다 작은 제곱수를 통해 최소 제곱수를 구함 */
		for (int j = 1; j * j <= i; j++)
			dp[i] = dp[i - j * j] + 1);
	}

	cout << dp[n];
	return 0;
}