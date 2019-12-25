#include <iostream>
#include <vector>
#include <queue>
#define INF -(1LL << 60)
using namespace std;

typedef long long ll;

int n, m, s, e;
/* 그래프의 정보를 저장할 행렬 선언 */
vector <pair<int, int>> mat[100];
/* 사이클이 있을 경우 int 범위를 넘어설 수 있으므로 long long으로 정의 */
vector<ll> dist, cost;

/* 사이클이 목적지 까지 연결되어 있는지 확인하기 위한 BFS 함수 */
bool bfs(queue<int> que) {
	int cur, nex;
	/* BFS 방문 초기화 */
	vector<bool> visit(n+1, false);

	/* BFS 알고리즘 실행 */
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) continue;
		visit[cur] = true;

		if (cur == e) break;

		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i].first;
			if (!visit[nex]) que.push(nex);
		}
	}
	return visit[e];
}

/* 벨만포드 함수 */
void belman_ford() {
	/* 각 도시에 따른 최소 비용 초기화 */
	dist = vector<ll>(n+1, INF);
	/* 시작 마을에서 벌 수 있는 돈으로 초기화 */
	dist[s] = cost[s];
	/* BFS 알고리즘을 위한 큐 선언 */
	queue<int> cycle;

	/* 계산된 값이 int 범위를 넘어설 수 있으므로 long long으로 선언 */
	ll nd;
	int cnt = 0, nn;
	bool update = true; /* 최소 비용을 갱신하는지 확인하기 위한 변수 */
	/* 벨만포드 알고리즘 실행 */
	while (update&&cnt < n) {
		update = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				/* 현재 도시의 최소 비용이 갱신되지 이전일 경우 무시 */
				if (dist[i] != INF) {
					/* 다음 도시의 위치와 다음 도시로 이동할 때 벌 수 있는 금액 계산 */
					nn = mat[i][j].first, nd = dist[i] + cost[nn] - mat[i][j].second;
					/* 벌 수 있는 금액이 기존 금액보다 클 경우 갱신 */
					if (dist[nn] < nd) {
						dist[nn] = nd;
						update = true;
						/* 만일 사이클 내에 존재하는 도시일 경우 큐에 입력 */
						if (cnt == n - 1) cycle.push(i);
					}
				}
			}
		}
		cnt++;
	}

	if (dist[e] == INF)
		cout << "gg";
	else if (bfs(cycle))
		cout << "Gee";
	else
		cout << dist[e];

}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 그래프에 대한 간선 정보, 비용 입력*/
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
	}

	/* 도시를 방문할 때마다 얻을 수 있는 금액 입력 */
	cost = vector<ll>(n+1, 0);
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	belman_ford();
	return 0;
}