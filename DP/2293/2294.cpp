#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 100
#define CMAX 10001
#define MIN(a, b) ( a < b ? a : b )

int n, k;
vector<int> val, dp;

void BFS()
{
	/* 
		BFS 알고리즘을 위한 visit 배열 정의 
		dp 배열에 대해 BFS 알고리즘을 적용하기 위해 배열 크기를 CMAX로 정의
	*/
	vector<bool> visit(CMAX, false);
	/* BFS 알고리즘을 위한 queue 객체 정의 */
	queue<int> que;
	/* 가장 초기 상태인 가격 0을 입력 */
	que.push(0);
	/* 
		가격 0에 대한 동전 최대 개수는 0
			-> 동전을 추가할 필요가 없음
	*/
	dp[0] = 0;

	int pn;
	while (!que.empty())
	{
		/* queue의 현재 첫 번째 값을 가져옴 */
		pn = que.front();
		que.pop();

		/* 
			현재 가격이 주어진 가격일 경우 BFS 알고리즘 종료.
			BFS 알고리즘에 의해 가장 처음으로 종료 조건에 도착했을 때의 동전 
			개수가 최소 동전 개수이기 때문.
		*/
		if (pn == k)
			break;

		/* 
			만약 이전에 방문한 가격일 경우, BFS 알고리즘에서 제외함.
			현재 가격에서 동전 가치를 추가해 만든 가격들에 대한 최소 동전 
			개수는 이미 이전 BFS 알고리즘 과정을 통해 정해져 있기 때문.
		*/
		if (visit[pn])
			continue;
		/* 현재 가격을 방문했으므로 방문함을 표시 */
		visit[pn] = true;

		/* 모든 동전들에 대해 반복*/
		for (int i = 0; i < n; i++)
		{
			/*
				현재 동전 val[i]에 과 현재 가격을 더했을 때, 주어진 가격 k보다 작을 경우
				k를 넘어서는 값에 경우, 최소 동전을 구할 필요가 없으므로 제외
			*/
			if (pn + val[i] <= k)
			{
				/* 
					현재 가격 pn에 동전 val[i]를 더한 가격에 대해 최소 개수를 갱신
					이미 계산된 동전 개수 dp[pn+val[i]] 와 현재 가격에 현재 동전을 추가한 개수
					dp[pn] + 1를 비교해 더 작은 값을 가격 pn + val[i]의 최소 동전 개수로 정의
				*/
				dp[pn + val[i]] = MIN(dp[pn + val[i]], dp[pn] + 1);
				/*
					가격 pn + val[i]의 동전 개수를 갱신했으므로 queue에 추가함

				*/
				que.push(pn + val[i]);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	/* 동전 수, 구하고자 하는 가격 입력 */
	cin >> n >> k;
	/* 동전, 가격에 대한 배열 초기화 */
	val = vector<int>(NMAX, 0);
	/*
		CMAX로 초기화 하는 이유
			모든 동전의 최대 개수는 10000개를 넘을 수 없음
			( 1원을 기준으로 생길 수 있는 최대 수 )
	*/
	dp = vector<int>(CMAX, CMAX);
	
	/* 동전 가격 입력 */
	for (int i = 0; i < n; i++)
		cin >> val[i];

	/* BFS 알고리즘 실행 */
	BFS();
	
	/*
		BFS 알고리즘 실행 이후 가격 k의 최소 동전 개수가 CMAX일 경우
		즉, 동전 개수가 갱신되지 않았을 경우이므로 주어진 동전으로
		만들 수 없는 가격이기 때문에 -1을 출력
	*/
	if (dp[k] == CMAX)
		cout << -1;
	/*
		그렇지 않을 경우, 주어진 동전으로 만들 수 있는 가격이므로
		최소 동전 개수를 출력함
	*/
	else
		cout << dp[k];

	return 0;
}