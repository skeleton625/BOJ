#include <iostream>
#include <vector>
#define INF 5000000
using namespace std;

int n, m;
vector<pair<int, int>> mat[501];
vector<int> dist;

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 그래프에 대한 정보(점 수, 간선 수, 간선 정보) 입력 */
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
	}

	/* 최단거리 초기화 */
	dist = vector<int>(n + 1, INF);
	dist[1] = 0;

	int nn, nd;
	/* 벨만포드 알고리즘 시작, 모든 점들을 한 번 씩 순회함 -> 사이클을 제한하기 위한 방법 */
	for (int i = 1; i <= n; i++) {
		/* 점의 최단거리가 갱신될 때마다 새로 갱신해 주기위해 모든 점을 순회 */
		for (int j = 1; j <= n; j++) {
			/* 점 중 사이클이 생기는 경우가 있는지 파악하기 위해 해당 점의 간선들을 확인 */
			for (int k = 0; k < mat[j].size(); k++) {
				nn = mat[j][k].first, nd = dist[j] + mat[j][k].second;
				/* 
					새로 계산된 최단거리가 현재 최단거리보다 짧은 경우 갱신해줌
					아직 갱신되지 않은 점일 경우 무시 -> 잘못된 최단거리가 갱신될 수 있기 때문
				*/
				if (dist[j] != INF && dist[nn] > nd) {
					dist[nn] = nd;
					/*만일 모든 점을 순회하고도 갱신되는 경우가 생기면 사이클이 있다는 얘기이므로 -1 출력 */
					if (i == n) {
						cout << -1 << '\n';
						return 0;
					}
				}
			}
		}
	}

	/* 
		시작점을 제외한 모든 점의 최단거리를 출력
		최단 거리가 없을 경우 -1을 출력함
	*/
	for (int i = 2; i <= n; i++)
		cout << (dist[i] != INF ? dist[i] : -1) << '\n';

	return 0;
}