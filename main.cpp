#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

unsigned long long res, tmp;
int n;
vector<int> mat;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	mat = vector<int>(n, 0);
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	sort(mat.begin(), mat.end());
	for (int i = 0; i < n; i++) {
		tmp = mat[i] * (n - i);
		if (res < tmp) res = tmp;
	}

	cout << res;
	return 0;
}