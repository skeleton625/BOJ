#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> mat;
int fn, sn, num;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> fn;
	for (int i = 0; i < fn; i++) {
		cin >> num;
		mat.push_back(num);
	}
	sort(mat.begin(), mat.end());

	cin >> sn;
	while (sn--) {
		cin >> num;
		auto s = lower_bound(mat.begin(), mat.end(), num);
		auto e = upper_bound(mat.begin(), mat.end(), num);
		cout << e - s << ' ';
	}

	return 0;
}