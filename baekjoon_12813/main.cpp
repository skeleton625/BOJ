#include <iostream>
#include <string>
using namespace std;

int t1, t2;
char r[5][100000];
string a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; a[i]; i++) {
		t1 = a[i] - '0'; t2 = b[i] - '0';
		r[0][i] = (t1 & t2) + 48; r[1][i] = (t1 | t2) + 48; 
		r[2][i] = (t1 ^ t2) + 48; r[3][i] = !t1 + 48; r[4][i] = !t2 + 48;
	}
	cout << r[0] << '\n' << r[1] << '\n' << r[2] << '\n' << r[3] << '\n' << r[4];
	return 0;
}