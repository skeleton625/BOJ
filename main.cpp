#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define DMAX 800000
using namespace std;

typedef pair<int, int> vertex;

vector<vertex> mat[801];
vector<int> min_len;
int re1, re2;
bool is_imp_1, is_imp_2;

int n, e;
int ver_num[2][4] = { {1,}, {1,} };

int dijkstra(int start, int end) {
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;
	que.push({ start, 0 });
	min_len[start] = 0;
	int pre_num, pre_dist;

	while (!que.empty()) {
		pre_num = que.top().first;
		pre_dist = que.top().second;
		que.pop();

		if (min_len[pre_num] < pre_dist)
			continue;

		int next_num, next_dist;
		for (int i = 0; i < mat[pre_num].size(); i++) {
			next_num = mat[pre_num][i].first;
			next_dist = min_len[pre_num]+mat[pre_num][i].second;
			if (min_len[next_num] > next_dist) {
				min_len[next_num] = next_dist;
				que.push({next_num, next_dist});
			}
		}
	}
	return min_len[end];
}

int main() {
	int a, b, c;
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> e;
	ver_num[0][3] = n, ver_num[1][3] = n;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
		mat[b].push_back({ a, c });
	}

	int cas1, cas2;
	cin >> ver_num[0][1] >> ver_num[0][2];
	ver_num[1][1] = ver_num[0][2], ver_num[1][2] = ver_num[0][1];

	for (int i = 0; i < 3; i++) {
		min_len = vector<int>(n + 1, DMAX);
		cas1 = dijkstra(ver_num[0][i], ver_num[0][i + 1]);
		min_len = vector<int>(n + 1, DMAX);
		cas2 = dijkstra(ver_num[1][i], ver_num[1][i + 1]);
		if (cas1 == DMAX) is_imp_1 = true;
		re1 += cas1;
		if (cas2 == DMAX) is_imp_2 = true;
		re2 += cas2;
	}

	if (is_imp_1 && is_imp_2) cout << -1;
	else if (re1 > re2) cout << re2;
	else cout << re1;

	return 0;
}