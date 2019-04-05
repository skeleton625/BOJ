#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 1001
#define swap(a, b) { int t = a; a = b; b = t; }

/* 신의 이차원 정점 변수 정의 */
struct ver {
	int x, y;
};
/* 두 신의 간선 정보 변수 정의 */
struct god {
	int g1, g2;
	double len;
	bool operator < (const god &g) { return len < g.len; }
};

/* 신 개수, 이미 연결된 정점 개수 변수 선언 */
int n, m;
/* 각 정점이 속한 집합의 루트 정점 번호 배열, 깊이 배열 선언 */
int parent[NMAX], prank[NMAX];
/* 각 신들의 좌표 배열 선언 */
ver dots[NMAX];
/* 모든 간선 정보 배열 선언 */
vector<god> dist;

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
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* 각 신들의 좌표 입력, 각 신들이 속한 집합 초기화 */
	for (int i = 1; i <= n; i++) {
		cin >> dots[i].x >> dots[i].y;
		parent[i] = i;
	}

	int a, b;
	/* 이미 연결된 신들의 정점 번호 입력. 집합을 합병해줌 */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	/* 각 정점들을 연결해서 생길 수 있는 모든 간선을 구함 */
	double lx, ly, len;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			lx = dots[i].x - dots[j].x;
			ly = dots[i].y - dots[j].y;

			len = sqrt(lx * lx + ly * ly);
			dist.push_back({ i, j, len });
		}
	}

	/* 구해준 모든 간선들을 내림차순으로 정렬 */
	sort(dist.begin(), dist.end());

	double res = 0;
	/* 
		구해준 모든 정점들은 최소부터 순서대로 합병해줌
		해당 정점이 이미 집합 내에 존재할 경우 합병 안함
	*/
	for (god now : dist) {
		if (find(now.g1) != find(now.g2)) {
			merge(now.g1, now.g2);
			/* 새로 합병될 경우 간선 길이 추가 */
			res += now.len;
		}
	}

	/* 새로 연결해준 간선의 길이 출력 */
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << res;
	return 0;
}