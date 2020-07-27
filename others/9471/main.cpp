#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, m, tmp;
	int f1, f2, c;
	vector<int> km;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> tmp >> m;
		c = 0, f1 = 1, f2 = 1;
		while (1) {
			tmp = f2;
			f2 = (f1 + f2) % m;
			c++;
			if (f1 == 0 && f2 == 1) break;
			f1 = tmp;
		}
		km.push_back(c);
	}
	for (int i = 0; i < km.size(); i++)
		cout << i+1 << ' ' << km[i] << '\n';
	return 0;
}