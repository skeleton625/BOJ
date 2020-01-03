#include <iostream>
#include <vector>
using namespace std;

int n, m;
// ���� �迭 �� 1, �� 2, �� 3, �� 4
int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<vector<int>> mat;
vector<int> dice, cmd;

void calc_dice_values(int x, int y, int cnt)
{
	int px = x, py = y, nx, ny;
	// ��ɾ� ������ŭ �ݺ����� ����
	for (int i = 0; i < cnt; i++)
	{
		// ���� �ֻ��� ��ġ ��� �� ���� ó��
		nx = px + dir[cmd[i]][0], ny = py + dir[cmd[i]][1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		// ��ɾ ���� ����Ǵ� �ֻ����� �� ����
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

		// ���� ���� ���� ���� 0�� ���, �ֻ��� �ٴںκ��� ���� �Է�
		if (mat[nx][ny] == 0)
			mat[nx][ny] = dice[5];
		// ���� ���� ���� ���� 0�� �ƴϸ� �ֻ��� �ٴںκп� ���� ���� �� ���� �� 0���� ����
		else
		{
			dice[5] = mat[nx][ny];
			mat[nx][ny] = 0;
		}

		// ���� ��ġ ���� �� ���� �ֻ��� �� �κ� �� ���
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

	// ���� ����, ���� ũ�� �� �ֻ��� �ʱ� ��ǥ, ��ɾ� ���� �Է�
	cin >> n >> m >> x >> y >> cnt;
	// ����, �ֻ���, ��ɾ� �迭 ����
	mat = vector<vector<int>>(n, vector<int>(m, 0));
	cmd = vector<int>(cnt, 0);
	dice = vector<int>(6, 0);
	
	// ���� ���ڵ� ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	// ��ɾ�� ����
	for (int i = 0; i < cnt; i++)
		cin >> cmd[i];

	calc_dice_values(x, y, cnt);
	return 0;
}