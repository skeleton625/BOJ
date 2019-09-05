#include <iostream>
#include <vector>
#define nMAX 201 // �� �ִ� ����
#define mMAX 201 // ��� �ִ� ����
using namespace std;

int n, m;					// ��, ��� ���� ����
int adj[nMAX][mMAX];		// ��, ��� ���� ���� ���� �迭
vector<bool> visited;		// ���� �켱 Ž�� ���� �� �湮 ����
vector<int> nMatch, mMatch; // �ҿ� ����� ���, ���� ����� �� ��ȣ �Է� ����

bool dfs(int cow)
{
	/* ���� �湮�� �� ��ȣ�� ���, ������ ��ȯ -> ��͸� ���� ���� �ݺ��� ���� ���� */
	if (visited[cow])
		return false;

	/* �ش� �Ҵ� �湮������ ǥ�� */
	visited[cow] = true;

	/* ��� ��翡 ���� �Ұ� �� �� �ִ��� �ľ� */
	for (int cage = 1; cage <= m; cage++)
	{
		/* ���� ��翡 �Ұ� ���� ���� ��� */
		if (adj[cow][cage])
		{
			/* ���� ��翡 �Ұ� ���ų� �� �ִ� �Ҹ� �ٸ� ���� �ű� �� �ִ� ��� */
			if (mMatch[cage] == -1 || dfs(mMatch[cage]))
			{
				/* ��, ��翡 ���� ���� ���� ���� */
				nMatch[cow] = cage;
				mMatch[cage] = cow;
				/* �Ұ� �� �� �����Ƿ� ���� ��ȯ */
				return true;
			}
		}
	}

	/* ��� ��翡 ���� �Ұ� �� �� �����Ƿ� ������ ��ȯ */
	return false;
}

int biParticleMatching()
{
	/* ��-��� ��ȣ �Է� �迭 �ʱ�ȭ */
	nMatch = vector<int>(n + 1, -1);
	mMatch = vector<int>(m + 1, -1);

	/* �Ұ� ���ϴ� ��翡 �� ���� ���� */
	int cnt = 0;

	/* ��� �ҵ鿡 ���� ���� �켱 Ž���� ���� */
	for (int s = 1; s <= n; s++)
	{
		/* �湮 ���� �ʱ�ȭ */
		visited = vector<bool>(n + 1, false);

		/* ���� �켱 Ž���� ���� ������ ������ ������� Ȯ�� */
		if (dfs(s))
			cnt++;
	}

	return cnt;
}

int main()
{
	int cnt, cage;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ��, ��� ���� �Է� */
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		/* ���� �� ��ȣ�� ���ϴ� ��� ��ȣ �Է� */
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			/* ��� ��ȣ�� �Է�, ���� �ҿ� �Էµ� ���ڿ� ���� ���� ���� */
			cin >> cage;
			adj[i][cage] = true;
		}
	}

	cout << biParticleMatching();
	return 0;
}