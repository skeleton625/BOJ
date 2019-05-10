#include <algorithm>
#include <iostream>
using namespace std;
#define NMAX 1000

int mat[NMAX], cache[NMAX];

int main() {
	int n;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	sort(mat, mat + n);

	cache[0] = mat[0];
	int res = mat[0];
	for (int i = 1; i < n; i++) {
		cache[i] = mat[i] + cache[i - 1];
		res += cache[i];
	}

	cout << res;
	return 0;
}