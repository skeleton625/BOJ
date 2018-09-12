#include <iostream>
using namespace std;

int a, b, m = 1, n = 1;
int main() {
	cin >> a >> b;
	for (int i = 0; i < b; i++) m *= a--;
	for (int i = 2; i <= b; i++) n *= i;
	cout << (m / n);
	return 0;
}