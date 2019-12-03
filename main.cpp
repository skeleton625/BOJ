#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int res[500][500], mat[500][500];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n1, n2;
	/* 삼각형의 크기와 삼각형 꼭대기 값을 입력 */
	cin >> n >> mat[0][0];
	/* 삼각형의 꼭대기 최대값을 초기화해줌 */
	res[0][0] = mat[0][0];
	for (int i = 1; i < n; i++) {
		/* 삼각형의 각 줄의 데이터 입력 */
		for (int j = 0; j <= i; j++)
			cin >> mat[i][j];

		/* 전 줄의 최대값들을 기준으로 현재 줄의 최대값을 계산 */
		for (int j = 0; j < i; j++) {
			n1 = res[i - 1][j] + mat[i][j];
			n2 = res[i - 1][j] + mat[i][j + 1];
			if (res[i][j] < n1) res[i][j] = n1;
			if (res[i][j + 1] < n2) res[i][j + 1] = n2;
		}
	}

	/* 마지막 줄에서 최대값을 파악, 최대값을 출력함 */
	sort(res[n - 1], res[n - 1] + n);
	cout << res[n - 1][n - 1];

	return 0;
}