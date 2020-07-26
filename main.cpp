#include <iostream>
#include <stack>
using namespace std;

typedef unsigned long long ll;
int h[100000], hsize;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int width, height;
	ll maxi;
	while (1) {
		cin >> hsize;
		if (hsize == 0) break;
		maxi = 0;
		for (int i = 0; i < hsize; i++) cin >> h[i];
		stack<int> s;
		for (int i = 0; i < hsize; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				height = h[s.top()];
				s.pop();
				if (!s.empty()) width = i - s.top() - 1;
				else width = i;
				if ((ll)width*(ll)height > maxi) maxi = (ll)width * (ll)height;
			}
			s.push(i);
		}

		while (!s.empty()) {
			height = h[s.top()];
			s.pop();
			if (!s.empty()) width = hsize - s.top() - 1;
			else width = hsize;
			if ((ll)width*(ll)height > maxi) 
				maxi = (ll)width * (ll)height;
		}
		cout << maxi << '\n';
	}
	return 0;
}