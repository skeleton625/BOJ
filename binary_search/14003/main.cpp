#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
#define MAX 1000001

int n;
int mat[MAX], lis[MAX];
pair<int, int> ans[MAX];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
		lis[i] = MAX;
	}

	int cnt = 0, nex;
	for (int i = 0; i < n; ++i) {
		nex = lower_bound(lis, lis + cnt, mat[i]) - lis;
		if (lis[nex] == MAX) ++cnt;
		ans[i].first = nex;
		ans[i].second = mat[i];
		lis[nex] = mat[i];
	}

	cout << cnt-- << '\n';

	stack<int> s;
	for (int i = n-1; i >= 0; --i) {
		if (ans[i].first == cnt) {
			s.push(ans[i].second);
			--cnt;
		}
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}