#include <iostream>
#include <algorithm>
using namespace std;

int n[100000];
int dc, nc, num;

bool search_num(int fnum) {
	int left = 0, right = dc-1, mid;
	while (left <= right) {
		mid = (left+right) / 2;
		if (n[mid] < fnum) {
			left = mid + 1;
		} else if (n[mid] > fnum) {
			right = mid - 1;
		} else {
			return true;
			break;
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> dc;
	for (int i = 0; i < dc; i++) cin >> n[i];
	sort(n, n + dc);
	cin >> nc;
	for (int i = 0; i < nc; i++) {
		cin >> num;
		cout << search_num(num) << '\n';
	}
	return 0;
}