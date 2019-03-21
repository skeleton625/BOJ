#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) (a < b ? b : a)
#define NMAX 10001		/* 정점의 최대 개수 정의 */
#define INF 100			/* 비용 최대 값 정의 */
using namespace std;

int n, res;
int matc[NMAX];
int cost[NMAX], costmax[NMAX];
vector<int> mat[NMAX];

void bfs() {
	queue<int> que;
	
	/* 
		현재 정점이 시작 정점(정점으로 가는 간선이 없는 경우)일 경우 큐에 추가 
		또한, 그래프에 시작 정점밖에 존재하지 않을 수도 있기 때문에 먼저 최대 시간을 비교해줌
	*/
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) {
			que.push(i);
			costmax[i] = cost[i];
			res = max(res, cost[i]);
		}
	}

	int cur, nex;
	/* BFS 알고리즘을 실행해 그래프를 순회 */
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* 현재 정점과 연결되어 있는 정점을 파악 */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			/* 다음 정점으로 가는 간선 수 제거 */
			matc[nex]--;
			/* 정점까지 가는 최대 비용(시간) 갱신 */
			costmax[nex] = max(costmax[nex], cost[nex] + costmax[cur]);
			/* 
				더이상 연결된 간선이 없을 경우(다음 정점까지 가는 모든 간선을 이용한 경우)
				다음 정점을 큐에 입력
			*/
			if (matc[nex] == 0) {
				que.push(nex);
				/* 최대로 걸리는 시간을 파악하기 위해 현재까지 최대 비용 비교 */
				res = max(res, costmax[nex]);
			}
		}
	}
}

int main() {
	int a;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 작업 개수 입력 */
	cin >> n;
	/* 각 작업(정점)에 대한 정보 입력 */
	for (int i = 1; i <= n; i++) {
		cin >> cost[i] >> matc[i];
		for (int j = 0; j < matc[i]; j++) {
			cin >> a;
			/* i번 작업을 진행하기 위해 a번을 먼저 해야 하므로 a번에 연결해줌 */
			mat[a].push_back(i);
		}
	}

	bfs();
	cout << res;
	return 0;
}