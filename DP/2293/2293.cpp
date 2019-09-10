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

	// 동전 수, 구하고자 하는 가격 입력
	cin >> n >> k;
	/*
		DP 배열의 의미
			동전들을 사용해 만들 수 있는 가격( 배열 번호 )의 경우에 수
		dp[0]은 동전 없이도 만들 수 있으므로 1로 초기화
	*/
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		/* 입력된 동전 개수만큼 동전의 가치 입력*/
		cin >> val;
		/* 
			입력된 동전 가치를 기준으로 점화식 실행
			dp[j] += dp[j - val] 점화식의 의미
				가격 ( 배열 번호 ) j는 동전 val를 통해 가격 j - val에서 동전 val을 더하는 것으로 가격 j를 
				만들 수 있음. 즉, 가격 j - val를 만들 수 있는 경우에 수들은 동전 val를 사용해 가격 j를 
				만드는데 사용될 수 있다는 것을 의미함
			ex) 첫 번째 동전 가치가 2일 경우,
				dp[2] += dp[0]; (1)
				dp[3] += dp[1]; (0)
				dp[4] += dp[2]; (1)
				dp[5] += dp[3]; (0)
				...
				두 번째 동전 가치가 5일 경우,
				dp[5] += dp[0]; (1)
				dp[6] += dp[1]; (0)
				dp[7] += dp[2]; (1) -> 2와 5의 조합
				dp[8] += dp[3]; (1) -> 2의 경우에 수
				dp[9] += dp[4]; (1) -> 2와 5의 조합
				dp[10] += dp[5]; (2) -> 2, 5 각각의 경우의 수
				...
		*/
		for (int j = val; j <= k; j++)
			dp[j] += dp[j - val];
	}

	/* 계산이 완료된 경우의 수를 출력 */
	cout << dp[k];
	return 0;
}