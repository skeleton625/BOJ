#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 31

struct ver {
	int x, y, z, d;
};

int d, r, l;
int dir[6][3] = {
	{1, 0, 0}, {-1, 0, 0},
	{0, 1, 0}, {0, -1, 0},
	{0, 0, 1}, {0, 0, -1}
};
char mat[NMAX][NMAX][NMAX];
vector<vector<vector<bool>>> visit;

void bfs(int *start) {
	/* 다익스트라 알고리즘을 실행할 자료구조 큐 선언 */
	queue<ver> que;
	/* 그래프의 정점을 방문했는지 파악할 3차원 배열 정의 */
	visit = vector<vector<vector<bool>>>(d, vector<vector<bool>>(r, vector<bool>(l, false)));
	
	/* 시작 정점을 큐에 입력하고 방문 표시를 해줌 */
	que.push({ start[0], start[1], start[2] });
	visit[start[0]][start[1]][start[2]] = true;
	
	ver cur;
	int nx, ny, nz, nd;
	/* BFS 알고리즘 실행 */
	while (!que.empty()) {
		/* 큐 내의 첫 번째 정점 정의 */
		cur = que.front(); que.pop();

		/* 만일 현재 정정점이 출구일 경우 걸린 시간을 출력하고 종료 */
		if (mat[cur.x][cur.y][cur.z] == 'E') {
			cout << "Escaped in " << cur.d << " minute(s).\n";
			return;
		}
		
		/* 상하좌우전후로 현재 정점에서 이동시킴 */
		for (int i = 0; i < 6; i++) {
			/* 다음 정점이 위치할 좌표를 계산 */
			nx = cur.x + dir[i][0], ny = cur.y + dir[i][1], nz = cur.z + dir[i][2];

			/* 이동이 불가능한 곳일 경우 건너 뜀 */
			if (nx < 0 || ny < 0 || nz < 0 || nx > d - 1 || ny > r - 1 || nz > l - 1)
				continue;
			/* 이동하는 정점이 벽일 경우 건너 뜀 */
			else if (mat[nx][ny][nz] == '#')
				continue;
			/* 
				그 이외에 방문하지 않은 정점일 경우 그 정점을 방문했다 표시
				다음 정점으로 이동할 때의 시간을 계산해 다음 좌표와 같이 큐에 입력
			*/
			else if (!visit[nx][ny][nz]) {
				visit[nx][ny][nz] = true;
				nd = cur.d + 1;
				que.push({ nx, ny, nz, nd });
			}
		}
	}

	/* 모든 방향으로 이동해도 출구에 도달하지 못할 경우 도달 못함을 출력 */
	cout << "Trapped!\n";
}

int main() {
	int start[3], end[3];
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 육면체의 x, y, z 길이 입력 */
	cin >> d >> r >> l;
	/* 입력되는 x, y, z 길이가 모두 0이 될 때가지 반복 */
	while (d || r || l) {
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < l; k++) {
					cin >> mat[i][j][k];
					/* 육면체에서 시작 위치를 저장 */
					if (mat[i][j][k] == 'S') {
						start[0] = i, start[1] = j, start[2] = k;
					}
				}
			}
		}

		/* BFS 알고리즘 실행 */
		bfs(start);
		/* 다시 육면체의 x, y, z 길이 입력 */
		cin >> d >> r >> l;
	}
	return 0;
}