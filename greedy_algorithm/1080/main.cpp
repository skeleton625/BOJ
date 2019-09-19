#include <iostream>
using namespace std;
#define INF 52

/* 시작 행렬 */
char inp[INF][INF];
/* 결과 행렬 */
char res[INF][INF];
/* 행렬 가로, 세로 길이 */
int n, m;

/* 입력받는 함수 */
void insert(char (*mat)[INF])
{
	for (int i = 0; i < n; i++)
		cin >> mat[i];
}

/* 행렬에서 sx, sy부터 3*3 부분 행렬을 XOR 연산하는 함수 */
bool convert(int sx, int sy)
{
	/* 현재 위치 sx, sy에서 3*3 부분 행렬이 만들어지지 않을 경우 거짓을 반환 */
	if (sx + 3 > n || sy + 3 > m)
		return false;

	/* 3*3 부분행렬에 대해 XOR 연산 실행 */
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++)
			inp[i][j] = inp[i][j] == '0' ? '1' : '0';
	}
	/* 참을 반환 */
	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	insert(inp);	// 시작 행렬 입력
	insert(res);	// 결과 행렬 입력

	/* 부분 행렬 변환 횟수 변수 */
	int cnt = 0;
	/* 알고리즘 실행 */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			/* 현재 원소에서 시작 행렬과 결과 행렬이 다를 경우 */
			if (inp[i][j] != res[i][j])
			{
				/* 
					현재 위치부터 3x3 부분 행렬 변환 함수 실행
					변환이 가능할 경우 True, 그렇지 않을 경우 False를 반환
				*/
				if (convert(i, j))
					cnt++;	// 변환 횟수 증가
				else
				{
					/* 변환이 불가능할 경우 -1을 출력하고 종료 */
					cout << -1;
					return 0;
				}
			}
		}
	}

	/* 완전하게 같을 경우 변환 함수 실행 횟수 출력 */
	cout << cnt;
	return 0;
}