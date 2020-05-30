#include <iostream>
#include <string>
using namespace std;

int n;
string num;

bool create_num(int len) {

	if (len-1 == n) {
		num.erase(len - 1);
		return true;
	}

	for (int i = 1; i <= len / 2; i++) {
		string a = num.substr(len - i, i);
		string b = num.substr(len - i * 2, i);
		if (a == b) {
			num.erase(len - 1);
			return false;
		}
	}

	for (int i = 1; i <= 3; i++) {
		num += i + '0';
		if (create_num(len + 1))
			return true;
	}
	num.erase(len - 1);
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	create_num(0);
	cout << num;
	return 0;
}