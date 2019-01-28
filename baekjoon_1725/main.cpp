#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef unsigned long long ll;
int n;
stack<int> s;

int main() {
	cin >> n;
	int height, width;
	ll pre_max = 0;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			height = h[s.top()]; s.pop();
			if (!s.empty()) width = i - s.top() - 1;
			else width = i;
			if (pre_max < (ll)width*(ll)height)
				pre_max = (ll)width*(ll)height;
		}
		s.push(i);
	}

	while (!s.empty()) {
		height = h[s.top()]; s.pop();
		if (!s.empty()) width = n - s.top() - 1;
		else width = n;
		if (pre_max < (ll)width*(ll)height)
			pre_max = (ll)width*(ll)height;
	}

	cout << pre_max;
	return 0;
}