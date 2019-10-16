#include <algorithm>
#include <iostream>
#include <vector>
#define max(a, b) (a < b ? b : a);
using namespace std;

int n;
int dist[10001];
vector<int> mat[10001];
vector<int> vers;
vector<vector<int>> acc;

/* 정점을 연결한 최대값을 계산하는 함수 */
int dfs(int prev, int here, bool visit) {
	/* visit에 따른 정점의 누적 가중치 주소 정의 */
	int &ret = acc[here][visit];

	/* 이미 갱신이 된 경우 */
	if (ret != -1)
		return ret;

	/* 만일 방문해야되는 경우면 현재 정점의 가중치 정의 */
	if (visit) ret = dist[here];
	/* 방문하지 말아야 하는 정점의 경우 0을 정의 */
	else ret = 0;

	/* 연결된 정점들간의 확인 */
	for (auto next : mat[here]) {
		/* 방문했던 정점을 다시 방문하려 할 경우 제외 */
		if (prev == next) continue;

		/* 현재 정점을 방문해야할 경우, 다음 정점은 방문하면 안되므로 visit을 0으로 정의해 재귀 실행 */
		if (visit)
			ret += dfs(here, next, 0);
		/* 현재 정점을 방문하면 안될 경우, 다음 정점을 방문하거나 방문하지 않을 경우 중 최대값을 입력 */
		else
			ret += max(dfs(here, next, 0), dfs(here, next, 1));
	}

	return ret;
}

/* 최대값 계산에 사용되는 정점을 찾는 함수 */
void trace(int prev, int here, int visit) {
	/*
		해당 정점을 방문하는 경우 최대 정점 배열에 정점을 입력
		연결된 다음 정점을 찾음
	*/
	if (visit) {
		vers.push_back(here);
		for (auto next : mat[here]) {
			/* 방문했던 정점을 다시 방문하지 않도록 제외 */
			if (prev == next) continue;
			trace(here, next, 0);
		}
	}
	/*
		해당 정점을 방문하지 않은 경우
		다음 정점을 방문한 것와 방문하지 않은 것 중, 더 큰 값을 찾아
		해당 정점으로 이동
	*/
	else {
		for (auto next : mat[here]) {
			if (prev == next) continue;

			/* 다음 정점을 방문하지 않은 것이 더 클 경우, 방문하지 않음 */
			if (acc[next][0] >= acc[next][1])
				trace(here, next, 0);
			/* 다음 정점을 방문하는 것이 더 클 경우. 방문함 */
			else
				trace(here, next, 1);
		}
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 정점의 개수 입력, 각 정점의 누적 가중치 초기화 */
	cin >> n;
	acc = vector<vector<int>>(n + 1, vector<int>(2, -1));
	/* 각 정점의 가중치 입력 */
	for (int i = 1; i <= n; i++)
		cin >> dist[i];

	/* 트리의 정보 입력 */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* 정점 1을 최대값 계산에 사용할 경우 */
	int v = dfs(-1, 1, 1);
	/* 정점 1을 최대값 계산에 사용하지 않을 경우 */
	int nv = dfs(-1, 1, 0);

	/* 정점 1을 방문한 것이 더 클 경우, 정점 1을 최대 정점 배열에 포함해 다른 정점을 찾음 */
	if (v >= nv) {
		cout << v << '\n';
		trace(-1, 1, 1);
	}
	/* 정점 1을 방문하지 않는 것이 더 클 경우, 정점 1과 연결된 다른 최대 정점을 찾음 */
	else {
		cout << nv << '\n';
		trace(-1, 1, 0);
	}

	/* 최대 정점 배열을 오름차순으로 정렬 */
	sort(vers.begin(), vers.end());
	/* 최대 정점 배열 출력 */
	for (auto ver : vers)
		cout << ver << ' ';

	return 0;
}