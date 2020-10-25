#include "iostream"
using namespace std;

int main() {
	int n, m;
	unsigned long long re = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m;
			re += m;
		}
	}
	cout << re;
	return 0;
}