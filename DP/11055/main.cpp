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

	/* 수열의 길이 입력 */
	cin >> n;
	/* 수열 입력 */
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	/* 증가하는 부분 수열의 합 최대값 */
	int res = 0;
	/* 수열의 모든 원소 칸에 대해 반복 */
	for (int i = 0; i < n; i++)
	{
		/* 각 원소의 dp를 자기 자신의 값으로 초기화 */
		dp[i] = mat[i];
		/* 첫 번째 원소의 dp부터 시작 */
		for (int j = 0; j < i; j++)
		{
			/*
				현재 원소가 기준이 되는 원소보다 작을 경우,
				그리고 기준이 되는 원소의 dp가 현재 원소의 dp에 기준 원소 값을 더한 값보다 작을 경우
			*/
			if (mat[j] < mat[i] && dp[i] < dp[j] + mat[i])
				/* 그 값을 새로 정의 */
				dp[i] = dp[j] + mat[i];
		}
		/* 현재 원소의 dp가 현재까지의 최대값보다 큰지 확인 후, 갱신 */
		res = MAX(res, dp[i]);
	}

	/* 최대값 출력 */
	cout << res;
	return 0;
}