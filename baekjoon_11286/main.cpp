#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, num;
priority_queue<pair<int, int>> que;

int main() {
	int n;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) {
			if (que.empty()) cout << 0 << '\n';
			else {
				cout << -que.top().second << '\n';
				que.pop();
			}
		}
		else que.push({-abs(num), -num});
	}
	return 0;
}