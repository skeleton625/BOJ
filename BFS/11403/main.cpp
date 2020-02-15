#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 100

int n;
vector<bool> visited;
bool mat[NMAX][NMAX], res[NMAX][NMAX];

// 경로 파악에 대한 BFS 함수
void BFS(int s)
{
	queue<int> que;
	que.push(s);

	// 시작 번호 s를 시작으로 모든 번호에 접근할 수 있는지 파악
	int cur;
	while(!que.empty())
	{
		cur = que.front();
		que.pop();

		// 현재 번호 cur이 각 번호와 연결되어 있는지 파악
		for(int i = 0; i < n; i++)
		{
			if(mat[cur][i]&&!visited[i])
			{
				// 연결된 번호 i를 방문 했음을 표시
				visited[i] = true;
				// 시작 번호 s에서 i를 접근할 수 있음을 표시
				res[s][i] = true;

				// 번호 i와 연결된 번호들도 접근할 수 있는지
				// 파악하기 위해 queue에 추가
				que.push(i);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 그래프의 크기 입력
	cin >> n;
	
	// 그래프의 연결 유무 입력 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	// 모든 번호를 시작 번호로 정의해 경로 파악 알고리즘 진행
	for(int i = 0; i < n; i++)
	{
		// 방문 배열 초기화 및 BFS 알고리즘 실행
		visited = vector<bool>(n, false);
		BFS(i);
	}

	// 위 알고리즘 실행 결과 모든 번호에 대해 접근할 수 있는 번호 출력
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
