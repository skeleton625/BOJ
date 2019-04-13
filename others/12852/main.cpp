#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 1000001
#define EMP 100

int n;
/* 연산 횟수 배열 정의 */
int dp[NMAX] = { 0, 0, 1, 1 };
/* 연산 경로 배열 정의 */
int trace[NMAX] = { 0, 0, 1, 1 };

/* 
	i로 가는 문제에서 DP 케이스는 총 다섯가지가 존재함
	1. (i-1)이 2로 나눠 떨어지는 경우
	2. i가 6으로 나눠 떨어지는 경우 -> 이 경우는 3으로 나누면 연산 횟수를 줄일 수 있음
	3. i가 2로 나눠 떨어지는 경우
	4. i가 3으로 나눠 떨어지는 경우
	5. 그 외 i가 2, 3 으로 나눠 떨어지지 않는 케이스
		i - 1, i - 2, (i - 1)/2 -> 1 감소 시켰으므로 가능
*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 연산 케이스 변수 5개 정의 */
	int a, b, c, d, e;
	cin >> n;
	/* 3까지는 정의되어 있으므로 4부터 시작 */
	for (int i = 4; i <= n; i++) {
		/* 5가지 케이스 초기화 */
		a = EMP, b = EMP, c = EMP, d = EMP, e = EMP;
		/* 첫 번째 케이스 */
		if ((i - 1) % 3 == 0) a = dp[(i - 1) / 3] + 2;
		/* 두 번째 케이스 */
		if (i % 6 == 0) b = dp[i / 3] + 1;
		/* 세 번째 케이스 */
		if (i % 2 == 0) c = dp[i / 2] + 1;
		/* 네 번째 케이스 */
		if (i % 3 == 0) d = dp[i / 3] + 1;
		/* 다섯 번째 케이스 */
		e = min({ dp[i - 1] + 1, dp[i - 2] + 2, dp[(i - 1) / 2] + 2, EMP });
		/* 5가지 케이스 중 최소값을 현재 dp로 결정 */
		dp[i] = min({ a, b, c, d, e });

		/* 현재 dp에 맞는 케이스를 trace로 지정해줌 */
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