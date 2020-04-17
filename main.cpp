#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#define NMAX 125	// 동굴 배열의 한 줄 크기
#define DMAX 1250	// 동굴 배열 원소의 최대 비용
using namespace std;

typedef pair<int, int> pai;
typedef pair<int, pai> vertex;

int n;
int mat[NMAX][NMAX];
const int dir[4][2] = { {-1, 0}, {0,-1}, {1, 0}, {0, 1} };
vector<int> dist[NMAX];

/* 다익스트라 알고리즘 함수 */
void dijkstra() {
	/* 다익스트라 알고리즘에 사용할 que 선언 */
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;
	/* 시작 점을 초기화 해줌 */
	dist[0][0] = mat[0][0];
	que.push({ mat[0][0], {0, 0} });

	int px, py, pd;
	/* 다익스트라 알고리즘 실행 */
	while (!que.empty()) {
		/* 현재 동굴의 x, y 위치와 최단 비용을 정의 */
		px = que.top().second.first, py = que.top().second.second;
		pd = que.top().first;
		que.pop();

		/* 현재 위치에 있는 최단 비용이 이미 갱신되었을 경우 다음 위치로 이동 */
		if (dist[px][py] < pd)
			continue;

		int nx, ny, nd;
		/* 동굴에서 이동 가능한 4개의 방향을 모두 시도 */
		for (int i = 0; i < 4; i++) {
			/* 다음으로 이동할 x, y 위치를 정의 */
			nx = px + dir[i][0], ny = py + dir[i][1];
			/* 이동할 위치가 없을 경우 다음 방향을 설정 */
			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1)
				continue;

			/* 
				이동 가능한 방향으로 이동 했을 경우 해당 위치의 최소 비용을 갱신 가능한지 파악
				가능할 경우 해당 위치를 우선순위 큐에 입력
			*/
			nd = mat[nx][ny] + pd;
			if (dist[nx][ny] > nd) {
				dist[nx][ny] = nd;
				que.push({ nd, {nx, ny} });
			}
		}
	}
}

int main() {
	int c = 1;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 테스트 시작 */
	while (n) {
		/* 동굴 배열에 대한 정보 입력 */
		for (int i = 0; i < n; i++) {
			dist[i] = vector<int>(n, DMAX);
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		}

		dijkstra();
		/* 도둑 루비를 적게 먹었을 경우 뺏기게 될 루피 개수 출력 */
		cout << "Problem " + to_string(c) + ": " << dist[n-1][n-1] << '\n';
		c++;
		cin >> n;
	}
	return 0;
}