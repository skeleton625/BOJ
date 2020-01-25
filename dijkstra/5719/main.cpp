#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define DMAX 500000
using namespace std;

typedef pair<int, int> ver;

int n, m, s, e;
vector<int> line;
vector<vector<bool>> visit;

/* 다익스트라 함수 */
void dijkstra(vector<ver>* mat) {
	/* 목적지에 따른 최단거리 배열 초기화 */
	line = vector<int>(n, DMAX);
	/* 다익스트라를 시작하기 위한 변수 초기화 */
	priority_queue<ver, vector<ver>, greater<ver>> que;
	line[s] = 0;
	que.push({ 0, s });

	int pn, pd;
	while (!que.empty()) {
		pn = que.top().second, pd = que.top().first;
		que.pop();

		/* 큐에 입력한 다음 최단거리가 변경되었을 경우 현재 케이스는 무시 */
		if (line[pn] < pd)
			continue;

		int nn, nd;
		/* 연결되어 있는 교차로들에 대한 정보를 확인 */
		for (int i = 0; i < mat[pn].size(); i++) {

			/* 현재 연결된 교차로의 번호와 최단 거리를 계산 */
			nn = mat[pn][i].second;
			nd = pd + mat[pn][i].first;

			/* 이전 최단 경로보다 현재 최단 경로가 더 짧을 경우 갱신 */
			/* 최단 경로 제거 때 제거된 도로이면 건너 뜀(처음엔 상관없음) */
			if (line[nn] > nd && !visit[pn][nn]) {
				line[nn] = nd;
				/* 갱신된 최단 경로에 대해서 연결된 다른 교차로의 최단 경로를 갱신해줌 */
				que.push({ nd, nn });
			}
		}
	}
}

/* 현재 최단거리 경로를 삭제하는 함수(BFS) */
void remove_line(vector<ver>* mat) {
	queue<int> que;
	que.push(e);

	int pre;
	/* BFS 알고리즘 시작 */
	while (!que.empty()) {
		pre = que.front(); que.pop();

		/* 만일 현재 위치가 시작점일 경우 무시 */
		if (pre == s) continue;

		int nex;
		/* 목적지에서 출발지로 이동하며 최단거리 경로에 있는 도로를 찾음 */
		for (int i = 0; i < mat[pre].size(); i++) {
			nex = mat[pre][i].second;
			if (line[pre] == line[nex] + mat[pre][i].first) {
				/* 다익스트라에서 최단 경로를 찾을 때와 반대로 접근하므로 뒤집어서 입력 */
				visit[nex][pre] = true;
				que.push(nex);
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 교차로와 도로 수를 입력 */
	cin >> n >> m;
	while (n != 0 && m != 0) {
		/* 출발지에서 목적지까지의 길 배열 정의 */
		vector<ver> go[500];
		/* 목적지에서 출발지까지의 길 배열 정의 */
		vector<ver> back[500];
		/* 출발지와 목적지 위치 입력 */
		cin >> s >> e;
		/* 도로에 대한 정보 입력 */
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			/* 각각의 기준에 따라서 길 배열 정의 */
			go[a].push_back({ c, b });
			back[b].push_back({ c, a });
		}

		/* 최단거리 방문 배열 초기화 */
		visit = vector<vector<bool>>(n, vector<bool>(n, false));

		/* 먼저 최단거리를 찾고 최단 거리 경로에 있는 도로들을 제거함 */
		dijkstra(go);
		remove_line(back);
		/* 최단거리 경로에 있는 도로를 제거하고 다시 다익스트라 실행 */
		dijkstra(go);

		/* 거의 최단 경로를 출력(경로가 없으면 -1 출력) */
		if (line[e] == DMAX) cout << -1 << '\n';
		else cout << line[e] << '\n';

		/* 다음 테스트 케이스를 받음 */
		cin >> n >> m;
	}
	return 0;
}
