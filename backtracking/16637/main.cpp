#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define INF 987654321
#define NMAX 20
#define MAX(a, b) ( a < b ? b : a )

int n, rmax = -INF;
char inp[NMAX];
int bound[NMAX];

/* ���� a, b�� ���� ������ op�� �����ϴ� �Լ� */
int calculate(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		default:
			return 0;
	}
}

int opResult()
{
	int p = 0;
	string str;
	queue<string> que;
	/* �ϼ��� �Ŀ��� ��ȣ�� ���� ���� ���� ��� */
	while (p < n)
	{
		/* �ش� ��ġ�� ���� ��ȣ�� ���� ��� */
		if (bound[p] == 2)
		{
			/* ���� ��ȣ ���� ���� ������ queue�� �Է� */
			que.push(to_string(calculate(inp[p]-'0', inp[p+2]-'0', inp[p+1])));
			/* ���� ��ȣ �������� �̵� */
			p += 3;
		}
		/* �׷��� ���� ��� */
		else
		{
			str = inp[p];
			/* ���� ��ġ�� ����, �����ڸ� �Է� */
			que.push(str);
			/* ���� ���ڷ� �̵� */
			++p;
		}
	}

	/* ��ȣ ����� �Ϸ��� �Ŀ��� ù ��° ���ڷ� ������� �ʱ�ȭ */
	int res = stoi(que.front()); que.pop();
	/* queue���� �ϼ��� ���� ���ʴ�� ������ ���� */
	while (!que.empty())
	{
		char oper = que.front()[0]; que.pop();
		int b = stoi(que.front()); que.pop();
		res = calculate(res, b, oper);
	}
	return res;
}

void backtracking(int pos)
{
	/* ���� �ϼ��� ���� ��갪�� �ִ밪�� �� */
	rmax = MAX(rmax, opResult());
	/* ���� ��ġ���� �߰��� �� �ִ� ��� ��ȣ�� �߰� */
	for (int i = pos; i < n; i+=2)
	{
		/* ��ȣ�� ���� ���, ��ȣ�� �߰� */
		if (i + 2 < n && bound[i] == 0 && bound[i + 2] == 0)
		{
			/* ���� ��ȣ�� 2, �ݴ� ��ȣ�� 1�� ���� */
			bound[i] = 2;
			bound[i + 2] = 1;
			/* ����Լ� ���� */
			backtracking(i+2);
			/* backtracking�� ����ϱ� ���� 0���� �ٽ� �ʱ�ȭ */
			bound[i] = bound[i + 2] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> inp;

	backtracking(0);
	cout << rmax;

	return 0;
}