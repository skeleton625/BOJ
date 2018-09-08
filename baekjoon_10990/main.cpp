#include <iostream>
using namespace std;

int t;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = t - i - 1; j > 0; j--) cout << " ";
		if (i != 0) cout << "*";
		else cout << "*"<<endl;
		for (int j = 0; j < 2*i-1; j++) cout << " ";
		if (i != 0) cout << "*"<<endl;
	}
	return 0;
}