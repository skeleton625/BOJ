#include <iostream>
#include <queue>
using namespace std;
#define NMAX 101

struct ver {
	int x, y, val;
};

int n, m;
int dir[4][2] = { { -1, 0}, {0, -1}, {1, 0}, {0, 1} };
char mat[NMAX][NMAX];
bool visit[NMAX][NMAX];

void bfs() {
	queue<ver> que;
	/*
		시작 위치 입력
		첫 번째 칸이므로 val 값은 1을 입력
	*/
	que.push({ 0, 0, 1 });
	
	int px, py, pd, nx, ny;
	/* BFS 알고리즘 실행 */
	while (!que.empty()) {
		/* 현재 위치와 이동했던 개수 정의 */
		px = que.front().x;
		py = que.front().y;
		pd = que.front().val;
		que.pop();
		
		/* 만약 목적지에 도착할 경우 이동했던 칸 수를 출력하고 종료 */
		if (px == n - 1 && py == m - 1) {
			cout << pd;
			break;
		}

		/* 방문했던 칸일 경우 넘어감 */
		if (visit[px][py]) continue;
		/* 현재 칸 방문 표시 */
		visit[px][py] = true;

		/* 현재 칸에서 이동 가능한 위치 계산 */
		for (int i = 0; i < 4; i++) {
			nx = px + dir[i][0], ny = py + dir[i][1];

			/* 미로를 벗어나는 위치일 경우 넘어감 */
			if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
			/* 이동 불가능한 칸일 경우 넘어감 */
			else if (mat[nx][ny] == '0') continue;
			/* 두 조건에 맞지 않고 방문하지 않은 칸일 경우 방문하고 방문 횟수를 증가시킴 */
			else if (!visit[nx][ny]) que.push({ nx, ny, pd + 1 });
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 가로, 세로 길이 입력 */
	cin >> n >> m;
	/* 미로 입력 */
	for (int i = 0; i < n; i++) cin >> mat[i];

	/* BFS 알고리즘 실행 */
	bfs();
	return 0;
}