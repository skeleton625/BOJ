#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> left_que;
priority_queue<int> right_que;

int main() {
	int num;
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i % 2 == 0) left_que.push(num);
		else right_que.push(-num);
		if (!right_que.empty() && left_que.top() > -right_que.top()) {
			int a = -right_que.top(); right_que.pop();
			int b = left_que.top(); left_que.pop();
			left_que.push(a);
			right_que.push(-b);
		}
		cout << left_que.top() << '\n';
	}
	return 0;
}