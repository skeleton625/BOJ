#include <iostream>
using namespace std;
#define NMAX 100000
#define MAX(a, b) ( (a) < (b) ? (b) : (a) )

int main() {
	int t, n;
	/* 스티커 점수 배열, 해당칸 스티커 점수 최대값 배열 선언 */
	int mat[2][NMAX], ans[2][NMAX];
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 테스트 케이스 수 입력 */
	cin >> t;
	while (t--) {
		/* 한 행의 스티커 수 입력 */
		cin >> n;
		/* 스티커 점수 정보 입력 */
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];
		}

		/* 초기칸 스티커 점수 최대값 초기화 */
		ans[0][0] = mat[0][0], ans[1][0] = mat[1][0];
		ans[0][1] = ans[1][0] + mat[0][1], ans[1][1] = ans[0][0] + mat[1][1];

		/* 스티커 점수 최대값 계산 */
		for (int i = 2; i < n; i++) {
			/*2행의 스티커를 선택했을 때, 최대값 계산 */
			ans[0][i] = mat[0][i] + MAX(ans[1][i - 1], ans[1][i - 2]);	/* 이전 대각선 혹은 그 옆의 값 중, 가장 큰 값과 더해줌 */
			ans[1][i] = mat[1][i] + MAX(ans[0][i - 1], ans[0][i - 2]);
		}

		/* 마지막으로 결정된 두 행의 최대값 중 가장 큰 값을 출력 */
		cout << MAX(ans[0][n - 1], ans[1][n - 1]) << '\n';
	}

	return 0;
}