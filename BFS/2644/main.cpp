#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 101

int n, m, s, e;
bool visit[NMAX];
vector<int> mat[NMAX];

void bfs() {
	/* BFS 알고리즘을 실행하기 위한 queue 자료형 정의 */
	queue<pair<int, int>> que;
	/* 시작 점과 초기 촌수를 정의해 queue에 입력 */
	que.push({ s, 0 });

	int cur, curd, nex;
	/* BFS 알고리즘 싦행 */
	while (!que.empty()) {
		/* 현재 대상과 이동한 정점 수를 입력 */
		cur = que.front().first;
		curd = que.front().second;
		que.pop();

		/* 목적지 대상에 도착할 경우 지금까지 이동한 정점 수 출력 */
		if (cur == e) {
			cout << curd;
			return;
		}
		/* 아니면 현재 대상을 방문했을 경우 넘어감 */
		else if (visit[cur]) continue;
		/* 방문하지 않았을 경우 방문했음을 표시 */
		visit[cur] = true;

		/*
			현재 대상과 연결되어 있는 가족들을 파악
			방문하지 않은 가족에 대해 queue에 입력함
		*/
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			if (!visit[nex]) que.push({ nex, curd + 1 });
		}
	}
	/* 만일 목적지 대상까지 도달하지 못할 경우 "-1"을 출력 */
	cout << -1;
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 가족의 수, 시작 대상, 목적지 대상, 가족 관계 수를 입력 */
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		/* 가족 관계 정보를 입력 */
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* BFS 알고리즘 실행 */
	bfs();
	return 0;
}