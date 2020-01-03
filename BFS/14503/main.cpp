#include <queue>
#include <iostream>
using namespace std;
#define NMAX 50

int n, m;
// ���� 2���� �迭 0 - ��, 1 - ��, 2 - ��, 3 - ��
// �迭�� ��(��) ��(��) ��(��) ��(��)
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool mat[NMAX][NMAX], visited[NMAX][NMAX];

// �κ� û�ұ��� ���� ��ġ �� ���� ����ü
struct ver
{
	int x, y, d;
};

int calc_clean_count(int x, int y, int d)
{
	// �κ� û�� ��ġ ����
	int cnt = 0;
	queue<ver> que;
	// �ʱ� �κ� û�ұ� ��ġ �Է�
	que.push({ x, y, d });

	bool flag;
	int px, py, pd, nx, ny, nd;
	while (!que.empty())
	{
		// �κ� û�ұ��� ���� ��ġ �Է�
		px = que.front().x;
		py = que.front().y;
		pd = que.front().d;
		que.pop();

		// ���� ��ġ�� û������ ���� ������ ���, ǥ�� �� ���� ī��Ʈ ����
		if (!visited[px][py])
		{
			visited[px][py] = true;
			++cnt;
		}

		// ���� ��ġ�� �������� ȸ�� Ž�� ����
		nd = pd;
		flag = true;
		for (int i = 0; i < 4; i++)
		{
			// ���� ���⿡�� �������� ȸ�� ( �� -> �� -> �� -> �� ��)
			nd = nd - 1 >= 0 ? nd - 1 : 3;
			nx = px + dir[nd][0], ny = py + dir[nd][1];
			// ���� ��ġ�� ���� ��� �н�
			if (mat[nx][ny])
				continue;
			// ���� ��ġ�� û������ ���� ������ ���, û���� ���� ǥ�� �� ��ġ �̵�
			else if (!visited[nx][ny])
			{
				flag = false;
				que.push({ nx, ny, nd });
				// ���� ��ġ �ܿ� ���� ȸ�� ��ġ��� �̵����� �ʵ��� �ߴ�
				break;
			}
		}

		// ���� ��� ������ ��ġ�� û�� �Ǿ��ų� ���� ���
		// �ٶ󺸴� ������ ������ ü �ٶ󺸴� ������ �ڷ� �̵�
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

	// ���� ũ��, �κ� û�ұ��� ��ġ, ���� �Է�
	cin >> n >> m;
	cin >> r >> c >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	// �Էµ� �� ���� û�� ��ġ ���� ���
	cout << calc_clean_count(r, c, b);
	return 0;
}