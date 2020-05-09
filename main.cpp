#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> que;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int num;
	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) {
			if (que.empty()) cout << 0 << '\n';
			else {
				cout << que.top() << '\n';
				que.pop();
			}
		}else que.push(num);
	}

	return 0;
}