#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k, c;
	cin >> n >> k;

	int left = 1, right = k, mid, res;
	while (left <= right) {
		c = 0;
		mid = (left + right) >> 1;
		
		for (int i = 1; i <= n; i++) c += min(mid/i, n);

		if (c < k) left = mid + 1;
		else if(c > k){
			res = mid;
			right = mid - 1;
		}
	}
	cout << res;
	return 0;
}