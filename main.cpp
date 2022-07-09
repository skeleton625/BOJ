#include <iostream>
using namespace std;
int i;
unsigned long long n;
char r[100];
int main() {
	cin >> n;
	while (n > 0) {
		r[i++] = (n % 2) + 48;
		n /= 2;
	}
	while (i--) cout << r[i];
	return 0;
}
/*
int i;
unsigned long long n;
char r[100];
int main() {
	scanf_s("%I64d", &n);
	while (n > 0) {
		r[i++] = (n & 1)+48;
		n >>= 1;
	}
	while(i--) printf("%c", r[i]);
	return 0;
}
*/