#include <iostream>
/* 노드 최대 개수 정의 */
#define NMAX 100001	
/* swap 함수 정의 */
#define swap(a, b) { int t = a; a = b; b = t; }
using namespace std;

int g, p;			/* 공항 게이트 개수, 비행기 개수 변수 선언 */
int parent[NMAX];	/* 게이트 번호에 따른 현재 도킹 가능한 번호 배열 선언 */

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int n1 = find(a), n2 = find(b);

	if (n1 == n2) return;
	/* 
		해당 알고리즘에서 집합 트리의 깊이가 1이상 늘어날 일이 없기 때문에 
		트리 깊이를 줄이는 알고리즘은 없앰
	*/
	parent[n1] = n2;
}

int main() {
	int a, f, cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> g >> p;
	/* 게이트 번호 집합 초기화 */
	for (int i = 1; i <= g; i++)
		parent[i] = i;

	/* 들어오는 비행기가 도킹하기 원하는 게이트 번호 입력 */
	for (int i = 0; i < p; i++) {
		cin >> a;
		/* 현재 비행기가 도킹할 수 있는 게이트 번호 찾음 */
		f = find(a);
		/* 비행기가 도킹할 수 잇는 게이트가 없을 경우 알고리즘 종료 */
		if (0 == f) break;
		else {
			/* 
				현재 비행기가 도킹할 수 있는 게이트 번호 집합과 바로 옆에 있는 게이트 번호 집합을 합해줌
			*/
			merge(f, f - 1);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}