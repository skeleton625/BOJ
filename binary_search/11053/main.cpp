#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define NMAX 1001

int n;
int mat[NMAX];
int lis[NMAX];

int main() {
	int cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
		lis[i] = NMAX;
	}

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(lis, lis + cnt, mat[i]) - lis;
		if (lis[it] == NMAX) ++cnt;
		lis[it] = mat[i];
	}

	cout << cnt;
	return 0;
}
