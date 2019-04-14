#include <iostream>
#define NMAX 201
#define swap(a, b) { int t = a; a = b; b = t; }
using namespace std;

int n, m;
int parent[NMAX];	/* 각 노드에 대한 루트 노드 배열  */
int prank[NMAX];	/* 각 노드에 대한 자식 깊이 배열 */

int find(int a) {
	/* 현재 노드의 루트 노드가 자기 자신일 경우 최고 꼭대기 노드임 */
	if (a == parent[a]) return a;
	/* 
		아닐 경우 부모 노드로 이동해 루트 노드를 찾음
		또한, 자신의 부모 노드를 해당 트리의 루트 노드로 변경해줌
			-> 탐색 속도를 더 빠르게 해주기 위함.
	*/
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	/* 노드 a, b의 루트 노드를 찾아줌 */
	int n1 = find(a), n2 = find(b);
	
	/* 두 노드의 루트 노드가 같을 경우 같은 트리에 속했다는 말이므로 재귀 종료 */
	if (n1 == n2) return;
	/* 두 루트 노드 중, 깊이가 더 큰 쪽으로 합병을 시켜줌 */
	if (prank[n1] > prank[n2]) swap(n1, n2);
	parent[n1] = n2;

	/* 만일 두 노드의 깊이가 같을 경우, 합병을 시켜준 노드의 깊이를 증가시켜 줌 */
	if (prank[n1] == prank[n2]) ++prank[n2];
}

int main() {
	int c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* 각 노드들에 대해 루트 노드를 초기화 */
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	/* 노드 그래프에 대한 정보 입력 */
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin >> c;
			/* i가 j보다 작은 경우는 이전 노드에서 간선 정보를 입력한 경우 */
			if (j > i && c == 1) merge(i, j);
		}
	}

	/* 노드의 순서를 입력 */
	cin >> c;
	/* 노드들의 부모가 같은지  파악하기 위해 루트 노드를 정의 */
	int root = find(c);
	for (int i = 1; i < m; i++) {
		cin >> c;
		/* 루트 노드가 다를 경우 "NO"를 출력 */
		if (root != find(c)) {
			cout << "NO";
			return 0;
		}
	}

	/* 모든 노드의 루트 노드가 같을 경우 "YES"를 출력 */
	cout << "YES";
	return 0;
}