#include <iostream>
#define NMAX 1000001 /* 노드의 최대 개수 */
using namespace std;

int n, m;
/* 각 노드에 대한 집합의 부모 노드를 저장할 배열 선언 */
int mat[NMAX], prank[NMAX];

int find(int a) {
	/* 현재 노드의 부모 노드가 자기 자신일 경우, 즉 루트 노드 */
	if (a == mat[a]) return a;
	/* 아직 루트 노드가 아니므로 부모 노드로 이동 */
	return mat[a] = find(mat[a]);
}

void merge(int a, int b) {
	/* 매개변수 a, b 노드의 루트 노드를 찾음 */
	int n1 = find(a), n2 = find(b);

	/* 루트 노드가 같을 경우, 같은 집합에 속해 있으므로 합병 종료 */
	if (n1 == n2) return;
	
	/* 두 집합 중, 집합의 높이가 더 큰 쪽을 파악함 */
	if (prank[n1] > prank[n2]) swap(n1, n2);
	/* 높이가 더 큰 집합에 작은 집합을 합쳐줌 */
	mat[n1] = n2;
	/* 두 집합의 크기가 같을 경우 합쳐지는 쪽의 높이를 1 증가시켜 줌 */
	if (prank[n1] == prank[n2]) ++prank[n1];
}

int main() {
	int u, a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 집합의 최대 개수, 집합 연산과 찾기 연산 개수 입력 */
	cin >> n >> m;
	/* 각 노드의 부모 노드를 자기 자신으로 초기화 */
	for (int i = 1; i <= n; i++) mat[i] = i;

	/* 연산 시작 */
	for (int i = 0; i < m; i++) {
		cin >> u >> a >> b;
		/* 처음 값이 0일 경우 합병 시도 */
		if (u == 0) {
			merge(a, b);
		} 
		/* 처음 값이 1일 경우 입력된 두 노드 번호가 같은 집합에 있는지 확인 */
		else {
			/* 같을 경우 "YES"를 출력 */
			if (find(a) == find(b)) cout << "YES\n";
			/* 그렇지 않을 경우 "NO"를 출력 */
			else cout << "NO\n";
		}
	}
	return 0;
}