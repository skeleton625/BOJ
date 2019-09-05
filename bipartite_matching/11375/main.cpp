#include <iostream>
#include <vector>
#define nMAX 1001	// �ִ� ��� ��
#define mMAX 1001	// �ִ� �� ��
using namespace std;

int n, m;					// ����, �� ���� ����
bool poss[nMAX][mMAX];		// ������ �� �� �մ� �� ���� �迭
vector<int> nMatch, mMatch;	// ����-��, ��-���� ����
vector<bool> visited;		// ���� �������� ���� ����ߴ��� ����

bool dfs(int human)
{
	/* ���� �̹� ��е� ����� ��� �ǳ� �� */
	if (visited[human])
		return false;

	visited[human] = true;

	/* ���� �켱 Ž�� ���� */
	for (int work = 1; work <= m; work++)
	{
		/* �ش� ����� �� ���� �� �� �ִ��� ���� �ľ� */
		if (poss[human][work])
		{
			if (mMatch[work] == -1 || dfs(mMatch[work]))
			{
				nMatch[human] = work;
				mMatch[work] = human;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatching()
{
	/* ����, �� ���� �ʱ�ȭ (-1 -> �Ҵ� �ȵ� ����) */
	nMatch = vector<int>(n + 1, -1);
	mMatch = vector<int>(m + 1, -1);

	/* ��е� ���� �ִ� �� */
	int cnt = 0;

	/* ��� ����� ���� �� ��� */
	for (int human = 1; human <= n; human++)
	{
		/* �ش� ������� �Ͽ� ����ߴ��� �ʱ�ȭ */
		visited = vector<bool>(n + 1, 0);

		/* ���� �켱 Ž�� ���� */
		if (dfs(human))
			++cnt;
	}

	return cnt;
}

int main()
{
	int cnt, work;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ��, �� �� �Է� */
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		/* �ش� ������ �� �� �ִ� �� ���� �Է� */
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			/* �� �� �ִ� �� ��ȣ �Է� ��, ���� ǥ�� */
			cin >> work;
			poss[i][work] = true;
		}
	}

	cout << bipartiteMatching();
	return 0;
}