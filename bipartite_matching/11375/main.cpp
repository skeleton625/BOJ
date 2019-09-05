#include <iostream>
#include <vector>
#define nMAX 1001	// 최대 사람 수
#define mMAX 1001	// 최대 일 수
using namespace std;

int n, m;					// 직원, 일 개수 변수
bool poss[nMAX][mMAX];		// 직원이 할 수 잇는 일 연결 배열
vector<int> nMatch, mMatch;	// 직원-일, 일-직원 백터
vector<bool> visited;		// 현재 직원에게 일을 배분했는지 백터

bool dfs(int human)
{
	/* 일이 이미 배분된 사람일 경우 건너 뜀 */
	if (visited[human])
		return false;

	visited[human] = true;

	/* 깊이 우선 탐색 실행 */
	for (int work = 1; work <= m; work++)
	{
		/* 해당 사람이 이 일을 할 수 있는지 여부 파악 */
		if (poss[human][work])
		{
			if (mMatch[work] == -1 || dfs(mMatch[work]))
			{
				nMatch[human] = work;
				mMatch[work] = human;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatching()
{
	/* 직원, 일 백터 초기화 (-1 -> 할당 안된 상태) */
	nMatch = vector<int>(n + 1, -1);
	mMatch = vector<int>(m + 1, -1);

	/* 배분된 일의 최대 수 */
	int cnt = 0;

	/* 모든 사람에 대해 일 배분 */
	for (int human = 1; human <= n; human++)
	{
		/* 해당 사람에게 일울 배분했는지 초기화 */
		visited = vector<bool>(n + 1, 0);

		/* 깊이 우선 탐색 실행 */
		if (dfs(human))
			++cnt;
	}

	return cnt;
}

int main()
{
	int cnt, work;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 직원 수, 일 수 입력 */
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		/* 해당 직원이 할 수 있는 일 개수 입력 */
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			/* 할 수 있는 일 번호 입력 및, 연결 표시 */
			cin >> work;
			poss[i][work] = true;
		}
	}

	cout << bipartiteMatching();
	return 0;
}