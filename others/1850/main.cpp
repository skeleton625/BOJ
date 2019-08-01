#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
	ll tmp = a;
	while (a) {
		tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

void generate_num(ll a) {
	string num = "";
	while (a--)
		num += '1';

	cout << num << '\n';
}

int main() {
	ll a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b;
	generate_num(gcd(a, b));
	return 0;
}