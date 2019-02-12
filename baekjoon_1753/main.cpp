#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MNUM 20001
#define IMAX 200000
using namespace std;

typedef pair<int, int> vertex;

int v, e, k;
vector<vertex> mat[MNUM];
vector<int> result;

void dijkstra() {
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;
	vertex pre;
	result[k] = 0;
	que.push({0, k});
	
	while (!que.empty()) {
		pre = que.top();  que.pop();

		/* 
			점의 거리가 갱신된 이후 다른 점들에 의해 다시 최소 거리가 갱신된 경우
			-> 해당 점은 무시(최근에 갱신된 최소 거리가 이전 것보다 작은 경우)
		*/
		if (result[pre.second] < pre.first)
			continue;
		
		for (int i = 0; i < mat[pre.second].size(); i++) {
			int next_num = mat[pre.second][i].second;
			int next_dist = mat[pre.second][i].first + result[pre.second];
			if (result[next_num] > next_dist) {
				result[next_num] = next_dist;
				que.push({next_dist, next_num});
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c;

	cin >> v >> e >> k;
	result = vector<int>(v + 1, IMAX);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ c, b });
	}

	dijkstra();
	for (int i = 1; i <= v; i++) {
		if (result[i] == 200000) cout << "INF" << '\n';
		else cout << result[i] << '\n';
	}

	return 0;
}