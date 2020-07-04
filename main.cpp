#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h[200000];
	int n, s;
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	sort(h, h + n);

	int left = 1, right = h[n - 1] - h[0], mid, max = 0;
	int d, start, wc;

	while (left <= right) {
		mid = (left + right) / 2;
		start = h[0], wc = 1;
		for (int i = 0; i < n; i++) {
			d = h[i] - start;
			if (d >= mid) {
				wc++;
				start = h[i];
			}
		}

		if (s > wc) {
			right = mid - 1;
		} else {
			left = mid + 1;
			if (max < mid) max = mid;
		}
	}

	cout << max;
	return 0;
}