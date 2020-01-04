#include <iostream>
#include <vector>
using namespace std;
#define MAX(a, b) ( a < b ? b : a );

int n, m;
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<vector<int>> mat;
vector<vector<bool>> visited;

int DFS(int x, int y, int c)
{
	int nx, ny, sum = 0;
	if (c == 3)
		return mat[x][y];

	for (int i = 0; i < 4; i++)
	{
		// 다음 블록 위치를 정의
		nx = x + dir[i][0], ny = y + dir[i][1];
		// 해당 위치가 종이를 벗어날 경우 넘어감
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		// 해당 위치가 종이를 벗어나지 않고 방문한 적이 없을 경우, 그 위치를 방문
		// 방문한 뒤의 값들과 현재 위치의 값을 더해 최대값을 정의
		if (!visited[nx][ny])
		{
			// 현재 방문한 공간에 대해 방문 초기화
			visited[nx][ny] = true;
			sum = MAX(sum, mat[x][y] + DFS(nx, ny, c + 1));
			visited[nx][ny] = false;
		}
	}

	return sum;
}

int calc_max_values(int x, int y)
{
	// 다음 위치 및 모든 값을 합할 정수 정의
	int nx, ny, _max = mat[x][y];
	// 주의 값을 접근 가능한지 파악할 배열 정의
	int flag[4] = { 0, };
	// 현재 위치의 주위에 있는 공간을 접근해 값을 정의하고 합함
	for (int i = 0; i < 4; i++)
	{
		nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		flag[i] = mat[nx][ny];
		_max += mat[nx][ny];
	}

	// 주위의 값들을 하나씩 빼가며 최대값을 찾음
	// 단, 정한 주위의 값 하나를 제외한 나머지 주위의 값 중에 
	// 하나라도 접근 불가능 한 값이 있을 경우, 그 경우에 한해서는 처리하지 않도록 함
	int res = 0;
	if (flag[0] && flag[1] && flag[2])
		res = MAX(res, _max - flag[3]);
	if (flag[0] && flag[2] && flag[3])
		res = MAX(res, _max - flag[1]);
	if (flag[0] && flag[1] && flag[3])
		res = MAX(res, _max - flag[2]);
	if (flag[1] && flag[2] && flag[3])
		res = MAX(res, _max - flag[0]);
	return res;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	mat = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));

	// 종이에 정의할 숫자들 입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	// 각 위치에 대해 폴리오미노 형태에 맞는 최대값을 비교함
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 현재 방문한 공간에 대해 방문 초기화
			visited[i][j] = true;
			res = MAX(res, DFS(i, j, 0));
			res = MAX(res, calc_max_values(i, j));
			visited[i][j] = false;
		}
	}

	cout << res;
	return 0;
}