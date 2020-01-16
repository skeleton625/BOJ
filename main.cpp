#include <iostream>
#include <vector>
#define INF 5000000
using namespace std;

int n, m, w;
vector<int> dist;

int main() {
	int a, b, c, t;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		bool is_poss = false;
		vector<pair<int, int>> mat[501];
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			mat[a].push_back({ b,c });
			mat[b].push_back({ a,c });
		}

		for (int i = 0; i < w; i++) {
			cin >> a >> b >> c;
			mat[a].push_back({ b, -c });
		}

		dist = vector<int>(n + 1, INF);
		dist[1] = 0;

		int nn, nd;
		/* 벨만포드 알고리즘 실행 */
		for (int i = 1; i <= n; i++) {
			/* 각 점에 대해서 Relax 하는 과정 */
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < mat[j].size(); k++) {
					nn = mat[j][k].first, nd = dist[j] + mat[j][k].second;
					if (dist[j] != INF && dist[nn] > nd) {
						dist[nn] = nd;
						/* 사이클이 존재하는 경우 -> 마지막에 다시 갱신하려 함 */
						if (i == n) {
							is_poss = true;
							break;
						}
					}
				}
			}
		}

		if (is_poss) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}