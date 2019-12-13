#include <iostream>
#include <vector>
#define INF 100
#define min(a, b) (a < b ? a : b)
using namespace std;

int main() {
	int n, m, a, b;
	/* 그래프 정보를 저장할 배열 선언 */
	vector<vector<int>> mat;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	/* 그래프 배열 초기화 */
	mat = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		mat[i][i] = 0;

	/* 그래프 배열 정보 입력 */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
	}

	/* 플로이드 와샬 알고리즘 실행 */
	for (int k = 1; k <= n; k++) { /* 출발지, 도착지 사이에 점이 있는지 모든 점을 입력 */
		for (int i = 1; i <= n; i++) { /* 모든 점을 출발지로 입력 */
			for (int j = 1; j <= n; j++) /* 모든 점을 도착지로 입력 */
				/* 점 간의 최단거리 연결 -> 각 행에서 갱신된 번호들은 연결되어 있는 번호들 */
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		}
	}

	/* 각 점이 연결되어 있는 개수를 세어줌 */
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != INF) {
				/* mat[i][j]가 초기 값이 아니므로 i와 j는 연결되어 있는 상태 */
				result[i]++;
				result[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << (n - result[i] + 1) << '\n';

	return 0;
}