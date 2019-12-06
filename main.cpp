#include <iostream>
#include <queue>
#define min(a, b)(a < b ? a : b)
using namespace std;

int n, result;
bool visit[1000001];

int bfs() {
	queue<pair<int, int>> que;
	/* 시작값 입력 */
	que.push({ n, 0 });

	int pn, pd;
	/* BFS 알고리즘 실행 */
	while (!que.empty()) {
		pn = que.front().first;		/* 현재 숫자 위치 정의  */
		pd = que.front().second;	/* 현재 숫자에 따른 연산 횟수 정의 */
		que.pop();

		/* 현재 숫자를 방문했다는 것을 표시함 */
		visit[pn] = true;

		if (pn == 1)	/* 최초로 도착하는 노드가 횟수가 가장 적은 노드이므로 반환 */
			return pd;
		/* i-1 숫자를 방문하지 않았을 경우 (1을 뺀다 연산) 큐에 연산 횟수를 증가시켜 입력 */
		if (!visit[pn - 1])
			que.push({ pn - 1, pd + 1 });
		/* 
			i/2 숫자를 방문하지 않고 2로 나눠지는 경우 
			(2로 나눠진다 연산) 큐에 연산 횟수를 증가시켜 입력 
		*/
		if (!visit[pn / 2] && pn % 2 == 0)
			que.push({ pn / 2, pd + 1 });
		/* 
			i/3 숫자를 방문하지 않고 3으로 나눠지는 경우 
			(3으로 나눠진다 연산) 큐에 연산 횟수를 증가시켜 입력
		*/
		if (!visit[pn / 3] && pn % 3 == 0)
			que.push({ pn / 3, pd + 1 });
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 연산 횟수를 확인할 숫자 입력 */
	cin >> n;
	cout << bfs();
	return 0;
}