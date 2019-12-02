#include <iostream>
#define max(a, b) (a < b ? b : a)
using namespace std;

int mat[10001];
int res[10001];

int main() {
	int n;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 데이터 입력 */
	for (int i = 1; i <= n; i++)
		cin >> mat[i];

	/* 각 위치의 최대값 초기화 */
	res[1] = mat[1];
	res[2] = mat[1] + mat[2];

	/* 최대값 계산 */
	for (int i = 3; i <= n; i++) {
		/* 이전 와인을 마시지 않은 경우와 이전 와인과 현재 와인을 마신 경우의 최대값 */
		res[i] = max(res[i - 2] + mat[i], res[i - 3] + mat[i - 1] + mat[i]);
		/* 현재 최대값보다 이전의 최대값이 더 클 수 있으므로 비교(두번씩이나 와인을 안 먹을수도 있기 때문) */
		res[i] = max(res[i], res[i - 1]);
	}

	cout << res[n];
	return 0;
}