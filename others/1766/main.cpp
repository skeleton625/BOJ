#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

/* 해당 번호보다 먼저 풀어야할 문제 개수 저장 변수 */
int line[32001];
/* 해당 번호보다 머저 풀어야할 문제 번호를 저장할 배열 */
vector<int> conn[32001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, f, s;

	cin >> n >> m;
	while (m--) {
		/* f -> s 번 보다 먼저 풀어야할 문제 번호 */
		cin >> f >> s;
		/* s번 문제보다 먼저 풀어야할 번호 개수 증가 */
		line[s]++;
		/* 
			먼저 풀어야할 f 번과 s 번이 연결되어 있음을 표시.
			s번 이외에 다른 번호들도 f번이 먼저 풀어야할 문제일 수 있기 때문에 배열로 저장.
		*/
		conn[f].push_back(s);
	}

	/* 
		오름차순의 우선순위 큐를 정의.
		가능한 가장 빠른 번호를 출력할 수 있도록 하기 위함.
	*/
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 1; i <= n; i++) {
		/* 
			연결된 선이 없다는 것은 가정 먼저 풀어야할 문제들임.
			여기서도 순서가 중요하기 때문에 오름차순으로 우선순위 큐에 입력.
		*/
		if (line[i] == 0)
			que.push(i);
	}

	/* 결과 순서를 정의할 문자열 변수 정의 */
	string result = "";
	/* 풀어야할 문제 순서를 정의하기 위한 반복문 실행 */
	while(n--) {
		/* 우선순위 큐의 꼭대기 값 (간선 연결이 없는 문제들 중 가장 작은 문제 번호) 을 현재 값으로 정의 */
		int cur = que.top();
		result += to_string(cur)+ ' ';
		que.pop();
		
		/* 현재 값(문제번호) 와 연결된 문제 번호들의 간선을 제거하기 위한 반복문 실행. */
		for (int i = 0; i < conn[cur].size(); i++) {
			/* 현재 값과 연결된 문제 번호를 정의 */
			int next = conn[cur][i];
			/* 연결되어 있는 문제 번호가 현재 값 이외에 연결된 문제 번호가 없을 경우, 우선순위 큐에 입력. */
			if (--line[next] == 0)
				que.push(next);
		}
	}

	cout << result;
	return 0;
}
