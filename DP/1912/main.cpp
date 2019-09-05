#include <iostream>
#include <algorithm>
#define NMAX 100000
using namespace std;

/* 연속합 배열 */
int nsum[NMAX];

int main()
{
	int n, nums;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 연속 숫자 수 입력 및 연속 수 첫 번째 수 입력 */
	cin >> n >> nums;
	/* 첫 번째 연속합 초기화 */
	nsum[0] = nums;
	for (int i = 1; i < n; i++)
	{
		cin >> nums;
		/* 현재 연속합과 현재 입력된 숫자 중 최대 값을 연속합에 입력 */
		nsum[i] = max(nums, nsum[i - 1] + nums);
	}

	/* 입력된 연속합 정렬 */
	sort(nsum, nsum + n);
	/* 연속합 최대값 출력 */
	cout << nsum[n - 1];

	return 0;
}