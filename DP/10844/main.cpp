#include <iostream>
#define REST 1000000000	// 
#define IMAX 101		// 숫자열 최대 개수
#define NMAX 10			// 각 자리의 숫자들
using namespace std;

/* 각 숫자열에서 첫 번째 자리 숫자들의 경우의 수 */
int nums[IMAX][NMAX];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	/* 첫 번째 자리의 초기화 */
	for (int i = 1; i < NMAX; i++)
		nums[1][i] = 1;

	/* 두 번째 자리부터 계산 시작 */
	for (int i = 2; i <= n; i++)
	{
		/* 현재 자리 수에서 0의 경우에 수 */
		nums[i][0] = nums[i - 1][1];
		/* 현재 자리 수에서 1~ 8의 경우에 수 */
		for (int j = 1; j < NMAX; j++)
		{
			nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j + 1];
			nums[i][j] %= REST;
		}
		/* 현재 자리 수에서 9의 경우에 수 */
		nums[i][NMAX - 1] = nums[i - 1][NMAX-2];
	}
	/* 최종 자리 수에서의 모든 경우의 수 계산 */
	int res = 0;
	for (int i = 0; i < NMAX; i++)
	{
		res += nums[n][i];
		res %= REST;
	}

	cout << res;
	return 0;
}