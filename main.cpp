#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

int main() {
	int lines[10000];
	int k, n;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> lines[i];
	sort(lines, lines + k);

	ll left = 1, right = lines[k - 1], c;
	ll mid, max = 0;

	while (left <= right) {
		c = 0;
		mid = (left+right) / 2;
		for (int i = 0; i < k; i++)
			c += lines[i] / mid;
		if (c < n) {
			right = mid - 1;
		} else {
			left = mid + 1;
			if (max < mid) max = mid;
		}
	}
	cout << max;
	return 0;
}