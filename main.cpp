#include <iostream>
using namespace std;

int t;
bool s = false;
int main() {
	cin >> t;
	for (int i = 0; i < 2*t; i++) {
		for (int j = 0; j < t; j++) {
			cout << (j % 2 == s ? '*' : ' ');
		}
		cout << endl;
		s = !s;
	}
	return 0;
}