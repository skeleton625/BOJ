#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n, num, result;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> que;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		que.push(num);
	}

	int a, b, tmp;
	while (que.size() > 1) {
		a = que.top(); que.pop();
		b = que.top(); que.pop();
		tmp = a + b;
		result += tmp;
		que.push(tmp);
	}

	cout << result;
	return 0;
}