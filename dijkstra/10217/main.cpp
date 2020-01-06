#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 100000
using namespace std;

typedef pair<pair<int, int>, int> pai;

struct ver {
	int e, co, di;
};
/* 공항 수, 총 지원비용, 티켓 정보 수*/
int n, m, k;
/* 각 항공과 비용에 대한 최단거리 배열 */
vector<vector<int>> dist;

int dijkstra(vector<ver> *mat) {
	/* 정해진 비용 내에서 목적지까지의 최단거리 변수 정의 */
	int result = INF;
	/* 구조체 pai에 대한 우선순위 큐 자료형 선언 */
	priority_queue<pai, vector<pai>, greater<pai>> que;
	/* 출발지와 비용에 따른 최단거리 초기화 -> 출발지 1 ( 비용, 거리는 0 ) */
	dist[1][0] = 0;
	/* 순서대로 최단거리, 출발지, 비용 -> 최단 거리를 파악하기 위해 최단거리로 정렬 */
	que.push({ {0, 1}, 0 });

	/* 다익스트라 알고리즘 실행 */
	int pn, pc, pd;
	while (!que.empty()) {
		/* 현재 출발지의 좌표, 최단거리, 비용 정의 */
		pn = que.top().first.second;
		pd = que.top().first.first;
		pc = que.top().second;
		que.pop();

		/* 출발지와 비용에 따른 최단거리가 갱신된 경우 다음 점으로 넘어감 */
		if (dist[pn][pc] < pd) continue;

		int nn, nc, nd;
		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].e; /* 목적지 항공 좌표 */
			nc = pc + mat[pn][i].co; /* 출발지에 따른 목적지의 비용 */
			/* 현재 출발지에서 목적지까지 비용이 정해진 비용을 넘는지 확인 */
			if (nc <= m) {
				nd = pd + mat[pn][i].di; /* 출발지에 따른 목적지 최단거리 */
				/* 만일 출발지와 비용에 따른 최단거리가 갱신될 여지가 있을 경우 갱신해주고 우선순위 큐에 입력 */
				if (dist[nn][nc] > nd) {
					dist[nn][nc] = nd;
					/* 현재 위치가 목적지일 경우, 목적지까지의 최단거리 갱신(현재보다 갱신된 거리가 더 짧을 경우)*/
					if (nn == n && result > nd) result = nd;
					que.push({ {nd, nn}, nc });
				}
			}
		}
	}
	return result;
}

int main() {
	/* 출발지, 도착지, 비용, 시간, 테스트 케이스 수*/
	int u, v, c, d, t;

	cin >> t;
	while (t--) {
		vector<ver> mat[101];
		cin >> n >> m >> k;
		/* 출발지와 목적지에 대한 경로 정보를 입력 */
		for (int i = 0; i < k; i++) {
			cin >> u >> v >> c >> d;
			mat[u].push_back({ v, c, d });
		}

		/* 비용에 따른 최단 경로 초기화 */
		dist = vector<vector<int>>(n + 1, vector<int>(10001, INF));
		/* 비용에 따른 목적지까지의 최단 거리 계산 */
		int result = dijkstra(mat);

		/* 
			목적지 까지 정해진 비용으로 갈 수 있을 경우 최단 거리를 출력
			그렇지 못할 경우 "Poor KCM" 출력
		*/
		if (result == INF) cout << "Poor KCM" << '\n';
		else cout << result << '\n';
	}
	return 0;
}