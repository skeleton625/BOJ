#include <iostream>
#include <algorithm>
using namespace std;

int tree[1000000];
int m, n;

int main() {
	int left = 0, right, mid, max = 0;
	unsigned long long sum;

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> tree[i];
	
	sort(tree, tree + m);
	
	right = tree[m - 1];
	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;
		for (int i = m - 1; i >= 0; i--) {
			if (tree[i] < mid) break;
			sum += (tree[i] - mid);
		}
		if (sum < n) {
			right = mid - 1;
		} else {
			left = mid + 1;
			if (max < mid) max = mid;
		}
	}
	cout << max;
	return 0;
}