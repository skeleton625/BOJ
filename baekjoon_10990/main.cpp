#include <cstdio>

int t;
int main() {
	scanf_s("%d", &t);
	for (int i = 0; i < t; ++i && printf("\n"))
		for (int j = 1; j <= t + i; j++)
			printf("%c", (j == t - i) || (j == t + i) ? '*' : ' ');
	return 0;
}
