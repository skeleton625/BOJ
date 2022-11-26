#include <cstdio>

int n;
int main() {
	scanf_s("%d", &n);
	printf(n % 10 > 0 ? "-1" : "%d %d %d", n / 300, n / 60 % 5, n / 10 % 6);
	return 0;
}