#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 20001

int n, m;
vector<int> len;
vector<int> mat[NMAX];

void dijkstra() {
	priority_queue<pair<int, int>> que;
	len[1] = 0;
	que.push({ 0, 1 });

	/* 현재 헛간 번호, 현재 헛간 가중치, 다음 헛간 가중치 변수 선언 */
	int cur, curd, nexd;
	/* 가장 멀리 있는 가장 작은 번호의 헛간, 최대 헛간 가중치, 가장 멀리 있는 헛간 개수 변수 정의 */
	int minnum = 0, maxlen = 0, cnt= 0;
	/* 다익스트라 알고리즘 실행 */
	while (!que.empty()) {
		/* 현재 헛간 번호와 가중치 입력 */
		cur = que.top().second;
		curd = -que.top().first;
		que.pop();

		/*
			현재 헛간의 갱신된 가중치보다 현재 가중치가 더 클 경우 넘어감 
			-> 최단거리를 구해야 하기 때문에 가중치가 늘어나는 것을 방지
		*/
		if (len[cur] < curd) continue;

		/* 현재 헛간과 연결된 다른 헛간들에 대해서 가중치 계산 */
		for (auto next : mat[cur]) {
			nexd = curd + 1;
			if (len[next] > nexd) {
				/* 전체 헛간의 최대 가중치 파악 */
				if (maxlen < nexd) maxlen = nexd;
				len[next] = nexd;
				que.push({ -nexd, next });
			}
		}
	}

	/* 가장 멀리있는 헛간들 중 가장 작은 번호의 헛간을 찾음 */
	for (int i = 1; i <= n; i++) {
		if (len[i] == maxlen) {
			minnum = i;
			break;
		}
	}

	/* 가장 작은 번호의 헛간부터 헛간들의 개수를 파악 */
	for (int i = minnum; i <= n; i++) {
		if (len[i] == maxlen) cnt++;
	}
	/* 최장 헛간 최소 번호, 최장 헛간 가중치, 최장 헛간 개수 출력 */
	cout << minnum << ' ' << maxlen << ' ' << cnt;
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 헛간의 개수, 헛간간의 간선 개수 입력 */
	cin >> n >> m;
	/* 헛간의 최소 가중치 초기화 */
	len = vector<int>(n + 1, NMAX);
	/* 헛간간의 간선 정보 입력 */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	dijkstra();
	return 0;
}