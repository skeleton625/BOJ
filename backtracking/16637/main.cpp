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

/* 숫자 a, b에 대해 연산자 op를 연산하는 함수 */
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
	/* 완성된 식에서 괄호로 묶인 식을 먼저 계산 */
	while (p < n)
	{
		/* 해당 위치에 열린 괄호가 있을 경우 */
		if (bound[p] == 2)
		{
			/* 열린 괄호 내의 식을 연산해 queue에 입력 */
			que.push(to_string(calculate(inp[p]-'0', inp[p+2]-'0', inp[p+1])));
			/* 닫힌 괄호 다음으로 이동 */
			p += 3;
		}
		/* 그렇지 않을 경우 */
		else
		{
			str = inp[p];
			/* 현재 위치의 숫자, 연산자를 입력 */
			que.push(str);
			/* 다음 문자로 이동 */
			++p;
		}
	}

	/* 괄호 계산을 완료한 식에서 첫 번째 숫자로 결과값을 초기화 */
	int res = stoi(que.front()); que.pop();
	/* queue에서 완성된 식을 차례대로 연산을 시작 */
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
	/* 현재 완성된 식의 계산값과 최대값을 비교 */
	rmax = MAX(rmax, opResult());
	/* 현재 위치에서 추가할 수 있는 모든 괄호를 추가 */
	for (int i = pos; i < n; i+=2)
	{
		/* 괄호가 없을 경우, 괄호를 추가 */
		if (i + 2 < n && bound[i] == 0 && bound[i + 2] == 0)
		{
			/* 여는 괄호를 2, 닫는 괄호를 1로 정의 */
			bound[i] = 2;
			bound[i + 2] = 1;
			/* 재귀함수 실행 */
			backtracking(i+2);
			/* backtracking을 취소하기 위해 0으로 다시 초기화 */
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