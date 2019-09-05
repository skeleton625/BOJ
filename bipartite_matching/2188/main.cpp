#include <iostream>
#include <vector>
#define nMAX 201 // 소 최대 개수
#define mMAX 201 // 축사 최대 개수
using namespace std;

int n, m;					// 소, 축사 개수 변수
int adj[nMAX][mMAX];		// 소, 축사 간의 연결 관계 배열
vector<bool> visited;		// 깊이 우선 탐색 전용 소 방문 백터
vector<int> nMatch, mMatch; // 소와 연결된 축사, 축사와 연결된 소 번호 입력 백터

bool dfs(int cow)
{
	/* 만약 방문한 소 번호일 경우, 거짓을 반환 -> 재귀를 통한 무한 반복을 막기 위함 */
	if (visited[cow])
		return false;

	/* 해당 소는 방문했음을 표시 */
	visited[cow] = true;

	/* 모든 축사에 대해 소가 들어갈 수 있는지 파악 */
	for (int cage = 1; cage <= m; cage++)
	{
		/* 현재 축사에 소가 들어가기 원할 경우 */
		if (adj[cow][cage])
		{
			/* 현재 축사에 소가 없거나 들어가 있는 소를 다른 축사로 옮길 수 있는 경우 */
			if (mMatch[cage] == -1 || dfs(mMatch[cage]))
			{
				/* 소, 축사에 대해 연결 관계 설정 */
				nMatch[cow] = cage;
				mMatch[cage] = cow;
				/* 소가 들어갈 수 있으므로 참을 반환 */
				return true;
			}
		}
	}

	/* 모든 축사에 대해 소가 들어갈 수 없으므로 거짓을 반환 */
	return false;
}

int biParticleMatching()
{
	/* 소-축사 번호 입력 배열 초기화 */
	nMatch = vector<int>(n + 1, -1);
	mMatch = vector<int>(m + 1, -1);

	/* 소가 원하는 축사에 들어간 개수 변수 */
	int cnt = 0;

	/* 모든 소들에 대해 깊이 우선 탐색을 진행 */
	for (int s = 1; s <= n; s++)
	{
		/* 방문 백터 초기화 */
		visited = vector<bool>(n + 1, false);

		/* 깊이 우선 탐색을 통해 접근이 가능한 축사인지 확인 */
		if (dfs(s))
			cnt++;
	}

	return cnt;
}

int main()
{
	int cnt, cage;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 소, 축사 개수 입력 */
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		/* 현재 소 번호가 원하는 축사 번호 입력 */
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			/* 축사 번호를 입력, 현재 소와 입력된 숫자와 연결 관계 정의 */
			cin >> cage;
			adj[i][cage] = true;
		}
	}

	cout << biParticleMatching();
	return 0;
}