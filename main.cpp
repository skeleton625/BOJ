#include <algorithm>
#include <iostream>
#include <vector>
#define LMAX 100001		/* 최대 노드 개수 정의 */
#define COLOR 18		/* 한 번에 사용될 수 있는 최대 색 개수 정의 */
#define INF 987654321	/* 정수형 변수 최대값 정의 */
using namespace std;

int n;
int cache[LMAX][COLOR];
vector<int> mat[LMAX];

void dfs(int prev, int here) {
	/* 비교할 현재 노드 위치 초기값 초기화 */
	cache[here][0] = INF;
	/* 현재 위치에서 각 색에 대한 비용 초기화 */
	for (int i = 1; i < COLOR; i++) cache[here][i] += i;
	/* 현재 노드와 연결되어 있는 노드 순회 */
	for (auto next : mat[here]) {
		/* 만약 다음 노드가 부모 노드일 경우 무시 */
		if (prev == next) continue;
		
		/* dfs 알고리즘을 통해 자식 노드로 재귀 */
		dfs(here, next);
		/* 가장 작은 색 번호, 그 다음으로 작은 색 번호 정의 */
		int fst = 0, snd = 0;
		/* 색에 대한 현재 비용을 비교해 가장 작은 색 번호와 그 다음으로 작은 색 번호를 구함 */
		for (int i = 1; i < COLOR; i++) {
			if (cache[next][snd] > cache[next][i]) snd = i;
			if (cache[next][fst] > cache[next][snd]) swap(fst, snd);
		}

		/* 각 색에 대한 비용을 더해줌 (최소값이 될 수 있도록 계산) */
		for (int i = 1; i < COLOR; i++) cache[here][i] += cache[next][i != fst ? fst : snd];
	}
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 트리 간선 정의 */
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	/* 트리를 순회할 dfs 알고리즘 실행 */
	dfs(0, 1);
	/* 모든 트리를 순회하고 결정된 색에 대한 최소값을 출력 */
	cout << *min_element(cache[1] + 1, cache[1] + 18);
	return 0;
}