#include <iostream>
#include <vector>
#define max(a , b) ( a < b ? b : a);
using namespace std;

/* 각 마을의 인구 수 */
int dist[10001];
/* 마을 그래프 */
vector<int> mat[10001];

/* 우수 마을의 최대 인구수를 구할 dfs 함수 */
int dfs(int prev, int here, bool visit) {
	int ret = 0;

	/* 우수 마을로 선택해야할 마을일 경우 해당 마을의 인구수 입력 */
	if (visit) ret = dist[here];

	/* 현재 마을과 연결된 마을 순회 */
	for (auto next : mat[here]) {
		/* 방문했던 마을을 다시 방문하려 할 경우 제외 */
		if (prev == next) continue;
		
		/* 
			현재 마을을 우수 마을로 지정해야할 경우
			다음 마을은 우수 마을로 지정하지 않음
		*/
		if (visit) ret += dfs(here, next, 0);
		/*
			현재 마을을 우수 마을로 지정하지 않을 경우 
			다음 마을울 우수 마을로 지정한 결과와 우수 마을로 지정하지 않은 결과 중, 최대값을 찾아줌
		*/
		else
			ret += max(dfs(here, next, 0), dfs(here, next, 1));
	}

	/* 현재 우수 마을로 지정 가능한 최대 인구수를 반환 */
	return ret;
}

int main() {
	int n, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 마을 수와 마을의 인구수 입력 */
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dist[i];

	/* 마을 간의 길 정보(트리 정보) 입력 */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		/* 무방향 그래프이므로 양쪽으로 연결 */
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* 각각 1번 마을을 우수 마을로 지정했을 때와 안했을 때의 최대 인구수 */
	int v = dfs(-1, 1, 1);
	int nv = dfs(-1, 1, 0);

	/* 총 최대 인구수 출력 */
	cout << max(v, nv);
	return 0;
}