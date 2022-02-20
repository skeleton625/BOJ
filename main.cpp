#include <iostream>
using namespace std;

int n;
unsigned long long r = 1;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) r *= i;
	cout << r;
	return 0;
}