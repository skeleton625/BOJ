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
	/* 이항 계수 첫 번째 계수의 값 */
	for (int i = 1; i <= n; i++)
	{
		/* 이항 계수 두 번째 계수의 값 */
		for (int j = 0; j <= i; j++)
		{
			/* 계수의 첫 번째와 끝은 1로 정의 */
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
			{
				/* 중간의 값을 이전 계수를 통해 계산 - 점화식 */
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][j] %= REST;
			}
		}
	}
	/* 입력된 이항 계수의 결과값 출력 */
	cout << dp[n][k];
	return 0;
}