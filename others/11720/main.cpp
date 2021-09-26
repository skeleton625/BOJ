#include <cstdio>

int m, d;
char i1[101];
int main() {
	scanf_s("%d\n%s", &d, i1, 101);
	for (int i = 0; i1[i]; i++) m += i1[i] - '0';
	printf("%d", m);
	return 0;
}