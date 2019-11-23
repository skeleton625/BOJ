#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 1000000000
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, int> ver;
int n, num, v[2], t = 0;
vector<ver> mat[100001];
vector<ll> len;

/* 시작 점에 대해서 가장 긴 정점을 반환하는 함수 -> 다익스트라 알고리즘 사용 */
ver dijkstra(int start) {
	/* 각 점에 대한 최단거리 초기화 */
	len = vector<ll>(n + 1, INF);
	/* 다익스트라 알고리즘에 사용할 우선순위 큐 초기화 */
	priority_queue<ver, vector<ver>, greater<ver>> que;
	ver max_ver = { 0, start };
	que.push({ 0, start });
	len[start] = 0;

	/* 다익스트라 알고리즘 실행 */
	int pn, pd, nn, nd;
	while (!que.empty()) {
		pn = que.top().second;
		pd = que.top().first;
		que.pop();

		if (len[pn] < pd) continue;

		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].second;
			nd = len[pn] + mat[pn][i].first;
			if (len[nn] > nd) {
				len[nn] = nd;
				que.push({ nd, nn });
				/* 루트 노드로부터 가장 긴 점을 발견할 경우 최장거리 노드 갱신 */
				if (max_ver.first < nd) {
					max_ver.first = nd;
					max_ver.second = nn;
				}
			}
		}
	}
	return max_ver;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 트리의 간선 정보 입력 */
	for(int i = 0; i < n; i++){
		cin >> num; /* 정점 번호 입력*/
		/* 정점과 연결된 다른 정점과의 간선 정보를 입력 */
		while (v[0] != -1) { /* 입력에서 -1이 나올 때까지 입력함 */
			if (t < 2) {
				cin >> v[t];
				t++;
			} else{
				/* -1 입력이 나오지 않고 연결된 정점과 간선의 길이를 입력할 경우 그래프에 추가 */
				mat[num].push_back({ v[1], v[0] });
				t = 0;
			}
		}
		v[0] = 0;
		t = 0;
	}

	/* 트리의 루트 노드에 대해서 다익스트라 알고리즘 실행 */
	ver n1 = dijkstra(1);
	/* 루트 노드에서 가장 멀리 떨어진 정점에 대해서 다익스트라 알고리즘 실행 */
	ver n2 = dijkstra(n1.second);

	/* 루트 노드에서 가장 멀리 떨어진 정점에서 가장 멀리 떨어진 정점간의 거리를 출력 */
	cout << n2.first;

	return 0;
}