#include <iostream>
#include <algorithm>
using namespace std;

int regi[10000];
int n, m;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int left = 0, right = 0, mid;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> regi[i];
		if (right < regi[i]) right = regi[i];
	}
	cin >> m;

	int sum, max = 0;

	while (left <= right) {
		sum = 0;
		mid = (left + right) >> 1;

		for (int i = 0; i < n; i++) {
			if (mid > regi[i]) sum += regi[i];
			else sum += mid;
		}

		if (sum > m) {
			right = mid - 1;
		} else {
			left = mid + 1;
			if (max < mid) max = mid;
		}
	}
	cout << max;
	return 0;
}