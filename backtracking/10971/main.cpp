#include <iostream>
#include <vector>
#define MIN(a, b) ( a < b ? a : b )
#define NMAX 100000001
using namespace std;

int n, start, ans = NMAX;
int mat[10][10];
bool visited[10];

void dfs(int p, int cnt, int cost) {
	// 마지막 도시까지 방문한 경우
	if (cnt == n) {
		// 마지막 방문 도시에서 시작 도시로 이동하는 경로가 존재하는지 확인
		if (mat[p][start])
			// 있을 경우 경로의 비용을 포함해 최소 비용을 갱신
			ans = MIN(ans, cost + mat[p][start]);
		return;
	}
	// DFS 백트래킹 알고리즘 실행
	for (int i = 0; i < n; i++) {
		// 방문하지 않은 도시면서 경로가 존재할 경우
		if (!visited[i] && mat[p][i]) {
			// 방문한 도시로 표시
			visited[i] = true;
			// 다음 도시로 이동
			dfs(i, cnt + 1, cost + mat[p][i]);
			// 백트래킹이 끝났으면 이동한 도시 방문 초기화
			visited[i] = false;
		}
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	// 도시의 개수 입력
	cin >> n;
	// i도시에서 j도시로 이동하는 이동 비용을 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	// 모든 도시를 대상으로 시작 도시로 선정해 DFS 알고리즘을 실행
	for (int i = 0; i < n; i++) {
		start = i;
		visited[start] = true;
		dfs(start, 1, 0);
		visited[start] = false;
	}

	// 모든 도시에 대한 순회 비용 중, 최소 비용을 출력
	cout << ans;

	return 0;
}