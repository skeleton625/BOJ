#include <iostream>
#include <string>
using namespace std;

int t, a, b;
string str;
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> a >> b >> str;
		for (int i = 0; i < str.size(); i++) str[i] = (a*(str[i] - 'A') + b) % 26 + 'A';
		cout << str << endl;
	}
	return 0;
}