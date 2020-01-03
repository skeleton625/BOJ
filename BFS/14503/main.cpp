#include <queue>
#include <iostream>
using namespace std;
#define NMAX 50

int n, m;
// 방향 2차원 배열 0 - 북, 1 - 동, 2 - 남, 3 - 서
// 배열의 상(북) 하(남) 좌(서) 우(동)
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool mat[NMAX][NMAX], visited[NMAX][NMAX];

// 로봇 청소기의 현재 위치 및 방향 구조체
struct ver
{
	int x, y, d;
};

int calc_clean_count(int x, int y, int d)
{
	// 로봇 청소 위치 개수
	int cnt = 0;
	queue<ver> que;
	// 초기 로봇 청소기 위치 입력
	que.push({ x, y, d });

	bool flag;
	int px, py, pd, nx, ny, nd;
	while (!que.empty())
	{
		// 로봇 청소기의 현재 위치 입력
		px = que.front().x;
		py = que.front().y;
		pd = que.front().d;
		que.pop();

		// 현재 위치가 청소하지 않은 구역일 경우, 표시 및 개수 카운트 증가
		if (!visited[px][py])
		{
			visited[px][py] = true;
			++cnt;
		}

		// 현재 위치를 기준으로 회전 탐색 시작
		nd = pd;
		flag = true;
		for (int i = 0; i < 4; i++)
		{
			// 현재 방향에서 왼쪽으로 회전 ( 북 -> 서 -> 남 -> 동 순)
			nd = nd - 1 >= 0 ? nd - 1 : 3;
			nx = px + dir[nd][0], ny = py + dir[nd][1];
			// 다음 위치가 벽일 경우 패스
			if (mat[nx][ny])
				continue;
			// 다음 위치가 청소하지 않은 구역일 경우, 청소할 것을 표시 및 위치 이동
			else if (!visited[nx][ny])
			{
				flag = false;
				que.push({ nx, ny, nd });
				// 현재 위치 외에 다음 회전 위치들로 이동하지 않도록 중단
				break;
			}
		}

		// 만일 모든 방향의 위치가 청소 되었거나 벽일 경우
		// 바라보는 방향을 유지한 체 바라보는 방향의 뒤로 이동
		nx = px - dir[pd][0], ny = py - dir[pd][1];
		if (!mat[nx][ny] && flag)
			que.push({ nx, ny, pd });
	}

	return cnt;
}


int main()
{
	int r, c, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	// 방의 크기, 로봇 청소기의 위치, 방향 입력
	cin >> n >> m;
	cin >> r >> c >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	// 입력된 방 내의 청소 위치 개수 출력
	cout << calc_clean_count(r, c, b);
	return 0;
}