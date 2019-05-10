#include <iostream>
using namespace std;
#define NMAX 31

int ncr[NMAX][NMAX];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 왼쪽 점이 1개 일 경우, 왼쪽, 오른쪽 점 개수가 동일한 경우 다리 개수 초기화 */
	for (int i = 1; i < NMAX; i++) {
		ncr[1][i] = i;
		ncr[i][i] = 1;
	}

	/* 모든 왼쪽, 오른쪽 점 개수에 대한 다리의 개수를 계산 */
	for (int i = 1; i < NMAX; i++) {
		for (int j = i + 1; j < NMAX; j++) {
			for (int k = j; k >= i; k--)
				ncr[i][j] += ncr[i-1][k-1];
		}
	}

	int t, a, b;
	/* 테스트 케이스 수 입력 */
	cin >> t;
	while (t--) {
		/* 왼쪽, 오른쪽 점 개수 입력 */
		cin >> a >> b;
		/* 그에 대한 전체 다리 경우의 수 출력 */
		cout << ncr[a][b] << '\n';
	}

	return 0;
}