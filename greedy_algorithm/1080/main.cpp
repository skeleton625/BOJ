#include <iostream>
using namespace std;
#define INF 52

/* ���� ��� */
char inp[INF][INF];
/* ��� ��� */
char res[INF][INF];
/* ��� ����, ���� ���� */
int n, m;

/* �Է¹޴� �Լ� */
void insert(char (*mat)[INF])
{
	for (int i = 0; i < n; i++)
		cin >> mat[i];
}

/* ��Ŀ��� sx, sy���� 3*3 �κ� ����� XOR �����ϴ� �Լ� */
bool convert(int sx, int sy)
{
	/* ���� ��ġ sx, sy���� 3*3 �κ� ����� ��������� ���� ��� ������ ��ȯ */
	if (sx + 3 > n || sy + 3 > m)
		return false;

	/* 3*3 �κ���Ŀ� ���� XOR ���� ���� */
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++)
			inp[i][j] = inp[i][j] == '0' ? '1' : '0';
	}
	/* ���� ��ȯ */
	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	insert(inp);	// ���� ��� �Է�
	insert(res);	// ��� ��� �Է�

	/* �κ� ��� ��ȯ Ƚ�� ���� */
	int cnt = 0;
	/* �˰��� ���� */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			/* ���� ���ҿ��� ���� ��İ� ��� ����� �ٸ� ��� */
			if (inp[i][j] != res[i][j])
			{
				/* 
					���� ��ġ���� 3x3 �κ� ��� ��ȯ �Լ� ����
					��ȯ�� ������ ��� True, �׷��� ���� ��� False�� ��ȯ
				*/
				if (convert(i, j))
					cnt++;	// ��ȯ Ƚ�� ����
				else
				{
					/* ��ȯ�� �Ұ����� ��� -1�� ����ϰ� ���� */
					cout << -1;
					return 0;
				}
			}
		}
	}

	/* �����ϰ� ���� ��� ��ȯ �Լ� ���� Ƚ�� ��� */
	cout << cnt;
	return 0;
}