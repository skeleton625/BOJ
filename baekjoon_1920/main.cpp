#include <iostream>
#include <map>
using namespace std;

map<int, bool> mp;
int nc, num;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> nc;
	for (int i = 0; i < nc; i++) {
		cin >> num;
		mp[num] = 1;
	}
	cin >> nc;
	for (int i = 0; i < nc; i++) {
		cin >> num;
		if (mp[num]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}