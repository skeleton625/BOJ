#include <iostream>
#define min(a, b)(a < b ? a : b)
using namespace std;

int n, mat[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 연산 횟수를 확인할 숫자 입력 */
	cin >> n;
	/* 1부터 순서대로 연산 횟수를 계산 */
	for (int i = 2; i <= n; i++) {
		/* 1을 뺀다 연산 */
		mat[i] = mat[i - 1] + 1;
		/* 2로 나눠질 경우 2로 나눈다 연산 */
		if (i % 2 == 0) mat[i] = min(mat[i], mat[i / 2] + 1);
		/* 3으로 나눠질 경우 3으로 나눈다 연산 */
		if (i % 3 == 0) mat[i] = min(mat[i], mat[i / 3] + 1);
	}
	
	cout << mat[n];
	return 0;
}