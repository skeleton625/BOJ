#include <cstdio>

int a, b;
int main() {
	while (scanf_s("%d %d", &a, &b)&&(a||b)) printf("%d %d / %d\n", a / b, a%b, b);
	return 0;
}