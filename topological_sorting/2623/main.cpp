#include <iostream>
#include <vector>
#include <queue>
#define NMAX 1001	/* 정점의 최대 개수 정의 */
using namespace std;

int n, m;				/* 정점, 간선 정보 개수 변수 선언 */
int matc[NMAX];			/* 각 정점들의 간선 개수 배열 선언 */
vector<int> res;		/* 최종 순서 배열 선언 */
vector<int> mat[NMAX];	/* 정점 그래프 배열 선언 */

void bfs() {
	queue<int> que;
	/* 시작 정점을 큐에 입력 */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) que.push(i);
	}

	/* BFS 알고리즘 실행 */
	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();
		res.push_back(cur);

		/* 연결된 각 정점들을 방문함 */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			matc[nex]--;	/* 다음 정점과 연결되어 있는 개수 감소 */
			/* 다음 정점과 연결된 모든 간선들을 방문한 경우 해당 정점을 큐에 입력 */
			if (matc[nex] == 0) que.push(nex);
		}
	}

	/* 
		모든 정점을 순서대로 방문할 수 있는 경우를 파악
		그렇지 못할 경우, 0을 출력함.
	*/
	for (int i = 1; i <= n; i++) {
		if (matc[i] != 0) {
			cout << 0;
			return;
		}
	}

	/* 모든 정점을 순서대로 방문한 경우 정점을 순서대로 출력 */
	for (auto it : res)
		cout << it << '\n';
}

int main() {
	int c, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);
	/* 정점 개수, 간선의 정보 입력 개수 입력 */
	cin >> n >> m;
	
	/* 간선의 정보 입력 */
	for (int i = 0; i < m; i++) {
		/* 한 줄에 입력되는 정점 수, 첫 번째 정점 번호 입력 */
		cin >> c >> a;
		/* 한 줄에 입력되는 정점의 번호에 따라 정점의 번호를 입력 받아 그래프에 정의 */
		for (int j = 1; j < c; j++) {
			cin >> b;
			mat[a].push_back(b);
			matc[b]++;	/* 연결된 간선의 개수를 세어줌 */
			a = b;		/* 현재 정점에 다음 정점을 연결해주기 위함 */
		}
	}

	bfs();
	return 0;
}