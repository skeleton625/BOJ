#include <iostream>
#include <stack>
using namespace std;
#define NMAX 200001
#define swap(a, b) { int t = a; a = b; b = t; }

/* 정점의 현재 부모 노드, 정점의 전체 부모 노드 배열 선언 */
int parent[NMAX], graph[NMAX];
/* 각 정점의 트리 깊이, 질의에 대한 데이터 저장 배열 선언 */
int prank[NMAX], query[NMAX*2][2];

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;
	if (prank[a] > prank[b]) swap(a, b);
	parent[a] = b;
	if (prank[a] == prank[b]) ++prank[b];
}

int main() {
	int n, q, a;
	stack<bool> res; /* 최종 결과를 저장하는 stack */
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 정점의 개수와 질의 개수 입력 */
	cin >> n >> q;
	/* 
		루트는 항상 1이므로 1에 대한 부모는 생각하지 않음
		연산을 줄이기 위해 2부터 시작
	*/
	graph[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		parent[i] = i;	/* 현재 정점의 부모 정보 초기화 */
		graph[i] = a;	/* 정점의 부모 정보 입력 */
	}

	/* 질의에 대한 정보를 배열에 입력 */
	for (int i = 1; i <= n + q - 1; i++) {
		cin >> a;
		/* 
			첫 번째 입력 값이 1일 경우 입력 값 2 개
			-> 두 정점을 연결하는 간선이 존재하는가
		*/
		if (a) cin >> query[i][0] >> query[i][1];
		/*
			첫 번째 입력 값 이 0일 경우 입력 값 1 개
			-> 정점의 부모 노드와의 연결을 삭제
		*/
		else cin >> query[i][0];
	}

	/* 트리 간선 삭제 과정을 반대로 적용해 트리를 만들어가는 과정으로 진행 */
	for (int i = n + q - 1; i; i--) {
		/* 
			현재 질의에서 첫 번째 입력이 1인 경우
			-> 두 정점을 연결하는 간선이 존재하는지 확인하는 질의
		*/
		if (query[i][1]) {
			/* 두 정점이 같은 트리 내에 존재할 경우 간선이 존재하는 것임 */
			if (find(query[i][0]) == find(query[i][1])) res.push(true);
			/* 같은 트리 내에 존재하지 않을 경우 간선이 존재하지 않음 */
			else res.push(false);
		}
		/* 
			현재 질의에서 첫 번째 입력이 0인 경우
			-> 현재 정점과 부모 정점간의 간선을 삭제
			-> 지금 반복문에선 질의 과정을 반대로 실행하고 있으므로 다시 합해줌
		*/
		else
			merge(query[i][0], graph[query[i][0]]);
	}

	/* 입력된 질의에 대해 반대로 답을 입력했으므로 stack을 통해 입력된 반대로 출력 */
	while (!res.empty()) {
		cout << (res.top() ? "YES" : "NO") << '\n';
		res.pop();
	}

	return 0;
}

