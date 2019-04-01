#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define NMAX 10001
#define swap(a, b) { int t = a; a = b; b = t; }

/* 두 정점에 대한 간선 자료형 선언 */
struct edge{
	int v1, v2, cost;
	bool operator < (const edge &ed) {
		return cost < ed.cost;
	}
};
int v, e;	/* 정점 개수, 간선 개수 변수 선언 */
int parent[NMAX], prank[NMAX]; /* 정점의 부모 노드 배열, 부모 트리 깊이 배열 선언 */
vector<edge> vers; /* 간선들에 대한 정보 배열 선언 */

/* 트리의 루트를 찾는 함수 */
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

/* 주어진 두 정점이 속한 트리를 합해주는 함수 */
void merge(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;
	if (prank[a] > prank[b]) swap(a, b);
	parent[a] = b;
	if (prank[a] == prank[b]) ++prank[b];
}

/* 최소 신장 트리의 가중치 반환 함수 */
int kruskal() {
	long long res = 0;
	/* 각 정점 간선의 가중치를 정렬 */
	sort(vers.begin(), vers.end());
	/* 각 정점의 부모 노드 초기화 -> 자기 자신으로 */
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	/* 가장 작은 가중치부터 시작해 정점을 트리로 연결해줌 */
	for (edge now : vers) {
		/* 현재 정점이 다른 집합(트리)일 경우 연결 */
		if (find(now.v1) != find(now.v2)) {
			res += now.cost;	/* 최소 가중치를 구하기 위한 계산 */
			merge(now.v1, now.v2);
		}
	}
	return res;
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 각 정점의 개수, 간선의 개수 입력 */
	cin >> v >> e;
	/* 트리의 간선 정보 입력 */
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vers.push_back({ a, b, c });
	}

	/* 입력된 그래프의 최소 신장 트리 가중치 출력 */
	cout << kruskal();
	return 0;
}