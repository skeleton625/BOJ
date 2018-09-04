#include <iostream>
#include <cstring>
using namespace std;

char a[15], b[8], c[15], d[8];
int s1, s2;
int main() {
	cin >> a >> b >> c >> d;
	s1 = strlen(a); s2 = strlen(c);
	for (int i = s1; i < s1+strlen(b); i++) a[i] = b[i - s1];
	for (int i = s2; i < s2+strlen(d); i++) c[i] = d[i - s2];
	cout << atoll(a) + atoll(c);
	return 0;
}
