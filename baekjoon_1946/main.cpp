#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> att[100000];
int t, n, s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> att[i].first >> att[i].second;
		sort(att, att + n);
		for (int i = n - 1; i >= 1; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (att[i].second > att[j].second) {
					s++;
					break;
				}
			}
		}

		cout << n - s << '\n';
		s = 0;
	}
	return 0;
}