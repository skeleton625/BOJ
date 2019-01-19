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
		int tmp = att[0].second;
		for (int i = 1; i < n; i++) {
			if (att[i].second < tmp)
				tmp = att[i].second;
			else s++;
		}

		cout << n - s << '\n';
		s = 0;
	}
	return 0;
}