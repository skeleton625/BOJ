#include <iostream>
#include <vector>
#include <queue>
#define NMAX 32001
using namespace std;

int n, m;
int matc[NMAX];			/* 정점에 간선이 연결된 개수 배열 */
vector<int> mat[NMAX];	/* 정점 연결 그래프 */

void bfs() {
	queue<int> que;
	
	/* 해당 정점에 연결되어 있는 정점의 개수가 0인, 즉 시작 정점을 큐에 입력 */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) que.push(i);
	}

	int cur, nex;
	/* BFS 알고리즘 실행 */
	while (!que.empty()) {
		cur = que.front(); que.pop();
		/* 현재 정점은 큐 내에서 가장 작은 정점이므로 출력 */
		cout << cur << ' ';

		/* 현재 정점과 연결되어 있는 정점들을 확인 */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			/* 현재 연결된 정점은 방문했으므로 연결된 간선의 개수를 감소시킴 */
			matc[nex]--;
			/* 만일 다음 정점의 간선 개수가 0, 즉 시작 정점이 되었을 때 큐에 입력 */
			if (matc[nex] == 0) que.push(nex);
		}
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 각 정점의 개수와 간선의 개수를 입력 */
	cin >> n >> m;
	/* 그래프에 대한 정보를 입력 */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		matc[b]++;	/* 해당 정점에 연결된 간선의 개수를 세어줌 */
	}

	bfs();
	return 0;
}