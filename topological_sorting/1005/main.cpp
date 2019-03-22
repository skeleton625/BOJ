#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) (a < b ? b : a)
#define NMAX 1001		/* 정점의 최대 개수 정의 */
#define TMAX 100000		/* 시간 최대 값 정의 */
using namespace std;

typedef long long ll;

int n, k, e;
vector<int> cost, matc;		/* 각 정점의 비용, 정점에 연결된 간선 개수 배열 선언 */
vector<ll> costmax;			/* 각 정점까지 연결된 최대 값 배열 선언 */
vector<vector<int>> mat;	/* 정점 그래프 선언 */

void bfs() {
	queue<int> que;

	/* 시작 정점을 파악해 큐에 입력 */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) {
			que.push(i);
			costmax[i] = cost[i];
		}
	}

	/* BFS 알고리즘 실행 */
	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* 
			현재 정점과 연결된 다음 정점들을 파악
			정점까지 가는 최대 비용 갱신
			현재 정점과 연결된 간선 이외에 다른 간선을 이미 방문한 경우, 그 정점을 큐에 입력
		*/
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			matc[nex]--;
			costmax[nex] = max(costmax[nex], costmax[cur] + (ll)cost[nex]);
			if (matc[nex] == 0) {
				/* 만약 다음 방문할 정점이 최종 정점일 경우 알고리즘 종료 */
				if (nex == e) return;
				que.push(nex);
			}
		}
	}
}

int main() {
	int x, y, t;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 테스트 케이스 실행 */
	cin >> t;
	while (t--) {
		/* 현재 테스트의 정점 개수, 간선 개수 입력 */
		cin >> n >> k;
		/* 입력된 값에 따른 그래프, 비용, 각 정점의 개수 배열 정의 */
		mat = vector<vector<int>>(n + 1, vector<int>(0, 0));
		costmax = vector<ll>(n + 1, 0);
		cost = vector<int>(n + 1, 0);
		matc = vector<int>(n + 1, 0);
		/* 각 정점의 비용 입력 */
		for (int i = 1; i <= n; i++) cin >> cost[i];
		/* 그래프 정보 입력  */
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			mat[x].push_back(y);
			matc[y]++;
		}
		/* 최종 거쳐야 할 정점 번호 입력 */
		cin >> e;

		/* BFS 위상 정렬 함수 실행 */
		bfs();
		/* 최종 점까지으 최소 비용(시간) 출력 */
		cout << costmax[e] << '\n';
	}

	return 0;
}