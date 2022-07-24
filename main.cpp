#include <iostream>
using namespace std;

char i1[101];
int m;
int main() {
	cin >> i1;
	for (int i = 0; i1[i]; i++) {
		if (i1[i] == ',') m++;
	}
	cout << m+1 << endl;
	return 0;
}