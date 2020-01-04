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
		// ���� ��� ��ġ�� ����
		nx = x + dir[i][0], ny = y + dir[i][1];
		// �ش� ��ġ�� ���̸� ��� ��� �Ѿ
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		// �ش� ��ġ�� ���̸� ����� �ʰ� �湮�� ���� ���� ���, �� ��ġ�� �湮
		// �湮�� ���� ����� ���� ��ġ�� ���� ���� �ִ밪�� ����
		if (!visited[nx][ny])
		{
			// ���� �湮�� ������ ���� �湮 �ʱ�ȭ
			visited[nx][ny] = true;
			sum = MAX(sum, mat[x][y] + DFS(nx, ny, c + 1));
			visited[nx][ny] = false;
		}
	}

	return sum;
}

int calc_max_values(int x, int y)
{
	// ���� ��ġ �� ��� ���� ���� ���� ����
	int nx, ny, _max = mat[x][y];
	// ���� ���� ���� �������� �ľ��� �迭 ����
	int flag[4] = { 0, };
	// ���� ��ġ�� ������ �ִ� ������ ������ ���� �����ϰ� ����
	for (int i = 0; i < 4; i++)
	{
		nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		flag[i] = mat[nx][ny];
		_max += mat[nx][ny];
	}

	// ������ ������ �ϳ��� ������ �ִ밪�� ã��
	// ��, ���� ������ �� �ϳ��� ������ ������ ������ �� �߿� 
	// �ϳ��� ���� �Ұ��� �� ���� ���� ���, �� ��쿡 ���ؼ��� ó������ �ʵ��� ��
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

	// ���̿� ������ ���ڵ� �Է�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	// �� ��ġ�� ���� �������̳� ���¿� �´� �ִ밪�� ����
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ���� �湮�� ������ ���� �湮 �ʱ�ȭ
			visited[i][j] = true;
			res = MAX(res, DFS(i, j, 0));
			res = MAX(res, calc_max_values(i, j));
			visited[i][j] = false;
		}
	}

	cout << res;
	return 0;
}