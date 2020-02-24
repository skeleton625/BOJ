#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> vertex;

int n, e, s, f;
vector<vertex> mat[1001];
vector<int> min_len;

void dijkstra(int start) {
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;
	min_len[start] = 0;
	que.push({ 0, start });

	int pre_num, pre_len;
	while (!que.empty()) {
		pre_num = que.top().second;
		pre_len = que.top().first;
		que.pop();

		if (min_len[pre_num] < pre_len)
			continue;

		int next_num, next_len;
		for (int i = 0; i < mat[pre_num].size(); i++) {
			next_num = mat[pre_num][i].first;
			next_len = min_len[pre_num] + mat[pre_num][i].second;

			if (min_len[next_num] > next_len) {
				min_len[next_num] = next_len;
				que.push({next_len, next_num});
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> e;
	min_len = vector<int>(n + 1, 100000000);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
	}
	cin >> s >> f;

	dijkstra(s);
	cout << min_len[f];

	return 0;
}