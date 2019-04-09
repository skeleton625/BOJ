#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define NMAX 1000001

int n;				/* 집합 원소 개수 변수 선언 */
int mat[NMAX];	/* 집합 배열 선언 */
int lst[NMAX];

int main() {
	int cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 집합 정보 입력 */
	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
		lst[i] = NMAX;
	}

	/* LIS 알고리즘 실행 */
	for (int i = 0; i < n; ++i) {
		/* 이분 탐색을 통해 현재 집합 원소보다 작거나 같은 값의 위치를 찾음 */
		auto it = lower_bound(lst, lst + cnt, mat[i]) - lst;
		/* 현재 원소가 만드는 집합 원소들 중 가장 클 경우, 크기 증가 */
		if (lst[it] == NMAX) cnt++;
		lst[it] = mat[i];
	}

	/* 집합 내 원소들의 개수를 파악함 */
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (lst[i] == NMAX) break;
		++cnt;
	}

	cout << cnt;
	return 0;
}