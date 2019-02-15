#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> vertex;

int n, m, x;
vector<vertex> go[1001];
vector<vertex> back[1001];
vector<int> go_line;
vector<int> back_line;

void dijkstra(int start, vector<int> &pre_line, vector<vertex> *mat) {
	priority_queue<vertex, vector<vertex>, greater<vertex>> que;

	pre_line[start] = 0;
	que.push({ 0 , start });

	int pre_num, pre_len;
	while (!que.empty()) {
		pre_num = que.top().second;
		pre_len = que.top().first;
		que.pop();

		if (pre_line[pre_num] < pre_len)
			continue;

		int next_num, next_len;
		for (int i = 0; i < mat[pre_num].size(); i++) {
			next_num = mat[pre_num][i].first;
			next_len = pre_len + mat[pre_num][i].second;

			if (pre_line[next_num] > next_len) {
				pre_line[next_num] = next_len;
				que.push({ next_len, next_num });
			}
		}
	}
}

int main() {
	int a, b, c, re_max = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		go[a].push_back({ b, c });
		back[b].push_back({ a, c });
	}

	go_line = vector<int>(n + 1, 100000);
	back_line = vector<int>(n + 1, 100000);
	dijkstra(x, go_line, go);
	dijkstra(x, back_line, back);

	for (int i = 1; i <= n; i++)
		re_max = max(re_max, go_line[i] + back_line[i]);

	cout << re_max;
	return 0;
}