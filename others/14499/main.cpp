#include <iostream>
#include <vector>
using namespace std;

int n, m;
// 방향 배열 동 1, 서 2, 북 3, 남 4
int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<vector<int>> mat;
vector<int> dice, cmd;

void calc_dice_values(int x, int y, int cnt)
{
	int px = x, py = y, nx, ny;
	// 명령어 개수만큼 반복문을 진행
	for (int i = 0; i < cnt; i++)
	{
		// 다음 주사위 위치 계산 및 예외 처리
		nx = px + dir[cmd[i]][0], ny = py + dir[cmd[i]][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		// 명령어에 따라 변경되는 주사위의 값 수정
		int tmp = dice[0];
		switch (cmd[i])
		{
			case 1:
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
				break;
			case 2:
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
				break;
			case 3:
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
				break;
			case 4:
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
				break;
		}

		// 만일 현재 보드 값이 0일 경우, 주사위 바닥부분의 값을 입력
		if (mat[nx][ny] == 0)
			mat[nx][ny] = dice[5];
		// 만일 현재 보드 값이 0이 아니면 주사위 바닥부분에 값을 복사 및 보드 값 0으로 정의
		else
		{
			dice[5] = mat[nx][ny];
			mat[nx][ny] = 0;
		}

		// 현재 위치 갱신 및 현재 주사위 윗 부분 값 출력
		px = nx, py = ny;
		cout << dice[0] << '\n';
	}
}

int main()
{
	int x, y, cnt;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	// 보드 가로, 세로 크기 및 주사위 초기 좌표, 명령어 개수 입력
	cin >> n >> m >> x >> y >> cnt;
	// 보드, 주사위, 명령어 배열 정의
	mat = vector<vector<int>>(n, vector<int>(m, 0));
	cmd = vector<int>(cnt, 0);
	dice = vector<int>(6, 0);
	
	// 보드 숫자들 정의
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	// 명령어들 정의
	for (int i = 0; i < cnt; i++)
		cin >> cmd[i];

	calc_dice_values(x, y, cnt);
	return 0;
}