#include <iostream>
using namespace std;
// 입력 최대값
#define NMAX 16
// 두 매개변수에 대한 최대값 반환 매크로
#define MAX(a, b) ( a < b ? b : a )

// 날짜 수 변수
int n, res;
// 각 일에 대한 소요 시간과 비용 배열
pair<int, int> dp[NMAX];

// 날짜 매개변수에 따라 일 실행 여부를 파악하는 재귀 함수
void tracking(int day, int money)
{
	// 만일 현재 날짜가 퇴사 날짜 이후일 경우 현재까지 벌은 금액과 최대 금액을 비교
	if (day >= n + 1)
		res = MAX(res, money);
	// 아직 퇴사 날짜가 아닐 경우
	else
	{
		// 현재 날짜에 할 수 있는 일을 퇴사 날짜 전까지 할 수 있는 경우
		if (day + dp[day].first <= n + 1)
			// 진행한 날짜와 금액을 매개변수로 재귀함수 실행
			tracking(day + dp[day].first, money + dp[day].second);
		// 현재 날짜에 할 수 있는 일을 안하고 다음 날로 갈 경우의 재귀함수 실행
		tracking(day + 1, money);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 총 날짜 수 입력
	cin >> n;
	// 각 일에 대한 소요 시간, 비용을 입력 
	for (int i = 1; i <= n; i++)
		cin >> dp[i].first >> dp[i].second;

	// 1일부터 최대 금액 파악 함수 실행
	tracking(1, 0);
	// 최대 금액 출력
	cout << res;
	return 0;
}