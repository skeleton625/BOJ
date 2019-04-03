#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 101
#define swap(a, b) { int t = a; a = b; b = t; }

/* 별 정점 자료형 선언 */
struct ver {
	double x, y;
};

/* 두 별 정점에 대한 간선 자료형 선언 */
struct star {
	int s1, s2;
	double len;
	/* 내림차순 정렬을 위한 operator 정의 */
	bool operator < (const star &s) { return len < s.len; }
};

int n;
/* 
	union find를 실행하기 위한
	정점이 속한 집합의 루트 번호 배열
	정점이 속한 집합의 트리 깊이 배열
*/
int parent[NMAX], prank[NMAX];
ver info[NMAX];
vector<star> mat;

/* 별 정점 a가 속한 집합의 루트 번호를 반환하는 함수 */
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

/* 별 정점 a, b가 속한 두 집합을 합해주는 함수 */
void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;
	if (prank[a] > prank[b]) swap(a, b);
	parent[a] = b;
	if (prank[a] == prank[b]) ++prank[b];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 정점 개수 입력 */
	cin >> n;
	/* 각 정점의 위치 입력 */
	for (int i = 1; i <= n; i++) {
		cin >> info[i].x >> info[i].y;
		parent[i] = i;
	}

	double lx, ly, len;
	/* 모든 정점들에서 나올 수 있는 길이 계산 */
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			lx = info[i].x - info[j].x;
			ly = info[i].y - info[j].y;

			len = sqrt(lx*lx + ly * ly);
			mat.push_back({ i, j, len });
		}
	}

	/* 모든 간선들을 내림차순으로 정렬 */
	sort(mat.begin(), mat.end());

	double res = 0;
	/* 
		모든 간선들에 대해서 길이가 최소인 간선부터 정점들을 연결
		정점들을 연결할 때마다 길이를 더해줌
	*/
	for (star now : mat) {
		if (find(now.s1) != find(now.s2)) {
			merge(now.s1, now.s2);
			res += now.len;
		}
	}

	/* 완성된 별자리 간선의 길이 출력 */
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << res;
	return 0;
}