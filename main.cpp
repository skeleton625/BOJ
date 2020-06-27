#include <iostream>
#include <algorithm>
using namespace std;

int card[500000];
int n, nc, in;

void is_card(int num) {
	int left = 0, right = n-1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (num < card[mid])
			right = mid - 1;
		else if (num > card[mid])
			left = mid + 1;
		else {
			cout << 1 << ' ';
			return;
		}
	}
	cout << 0 << ' ';
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);

	cin >> nc;
	for (int i = 0; i < nc; i++) {
		cin >> in;
		is_card(in);
	}
	return 0;
}