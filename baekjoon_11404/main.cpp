#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;

typedef long long ll;

int n, m;
vector<vector<ll>> mat;

int main() {
	int a, b;
	ll c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* 그래프 값 초기화 */
	mat = vector<vector<ll>>(n+1, vector<ll>(n+1, INF));
	/* 자기 자신으로 이동하는 경우는 안 움직이는 것이므로 0으로 초기화 */
	for (int i = 1; i < n + 1; i++)
		mat[i][i] = 0;

	/* 그래프 정보 입력 */
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a][b] = min(mat[a][b], c);
	}

	/* 플로이드 와샬 알고리즘 실행 */
	for (int i = 1; i <= n; i++)	/* 시작점 반복문 */
		for (int j = 1; j <= n; j++)	/* 도착점 반복문 */
			for (int k = 1; k <= n; k++)	/* 출발점과 도착점 사이의 점 반복문 */
				/* 출발점과 도착점 사이의 점을 통해 경로가 더 짧아지는 것이 있는지 확인해 갱신 */
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	/* 결과 출력 */
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (mat[i][j] != INF ? mat[i][j] : 0) << ' ';
		cout << '\n';
	}

	return 0;
}