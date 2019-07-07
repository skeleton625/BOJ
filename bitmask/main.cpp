#include <iostream>
#include <vector>
#define MMAX 16
#define NMAX 1000000001
#define MIN(a, b) ( a < b ? a : b )
using namespace std;

int n;
vector<vector<int>> mat, cash;

// 모든 도시를 순회하는 비용의 최소 값을 계산하는 함수
int calcMinPath(int p, int path) {
	// 만약 모든 경로를 순회한 경우
	if (path == (1 << n) - 1)
		// 시작 도시로 이동하는 경로가 있을 경우 그 비용을, 그렇지 않을 경우 최대값을 반환
		return mat[p][0] ? mat[p][0] : NMAX;
	// 현재 도시와 경로에 따른 비용 칸을 가져옴
	int& ret = cash[p][path];
	// 만약 현재 비용 칸에 값이 존재할 경우 최소값이므로 반환
	if (ret != -1) return ret;
	// 그렇지 않을 경우 최대값으로 초기화
	ret = NMAX;
	for (int i = 0; i < n; i++) {
		// 만일 다음 도시가 지나온 도시거나 경로가 존재하지 않을 경우 무시
		if ((path & 1 << i) || mat[p][i] == 0) continue;
		// 처음 이동하는 도시일 경우,이후 경로가 완성된 비용과 현재 비용을 비교해 최소값을 입력
		ret = MIN(ret, calcMinPath(i, path | 1 << i)+mat[p][i]);
	}
	// 현재 도시 경로의 최소값을 반환
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	// 도시의 이동경로 배열 초기화
	mat = vector<vector<int>>(n, vector<int>(n, 0));
	// i 도시에서 j 도시로 이동하는 비용 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	// 각 도시로 이동하는 경로의 경우의 수 초기화
	cash = vector<vector<int>>(n, vector<int>(1 << n, -1));

	// 모든 도시를 순회하는 최소 비용을 출력
	cout << calcMinPath(0, 1);
	return 0;
}