#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 20001	/* 정점의 최대 개수 정의 */
#define DMAX 200000	/* 정점 연결선의 최대 가중치 정의 */

typedef pair<int, int> ver;

int v, e, k;
vector<int> len;
vector<ver> mat[NMAX];

void dijkstra() {
	priority_queue<ver> que;

	/* 시작 점에 대해서 가중치 초기화 */
	len[k] = 0;
	/* 현재 점 번호, 가중치, 다음 점 번호, 가중치 변수 선언 */
	int curn, curd, nexn, nexd;
	/* 우선순위 큐에 시작 정점 입력 */
	que.push({ 0, k });
	while (!que.empty()) {
		curn = que.top().second;
		curd = -que.top().first;
		que.pop();

		/* 현재 위치릐 정점 가중치가 실제 가중치보다 클 경우 넘어감 */
		if (len[curn] < curd) continue;

		/* 현재 정점과 연결된 정점들에 대해서 가중치 계산 */
		for (int i = 0; i < mat[curn].size(); i++) {
			nexn = mat[curn][i].second;
			nexd = curd + mat[curn][i].first;
			/*
				만일 새로 계산된 다음 점들의 가중치가 입력된 가중치보다 작을 경우 갱신해줌
				갱신한 점과 연결된 다른 점들의 가중치도 갱신해주기 위해 우선순위 큐에 입력
			*/
			if (len[nexn] > nexd) {
				len[nexn] = nexd;
				que.push({ -nexd, nexn });
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 정점의 개수, 간선 개수, 시작점 번호 입력 */
	cin >> v >> e >> k;
	len = vector<int>(v + 1, DMAX);
	/* 간선에 대한 정보 입력 */
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ c, b });
	}

	/* 다익스트라 알고리즘 실행 */
	dijkstra();
	/* 결과 가중치 출력 */
	for (int i = 1; i <= v; i++) {
		if (len[i] == DMAX) cout << "INF\n";
		else cout << len[i] << '\n';
	}

	return 0;
}