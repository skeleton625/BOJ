#include <cstdio>

int t;
int main() {
	scanf_s("%d", &t);
	for (int i = 0; i < t; ++i&&printf("\n")) {
		if (i%2 == 1) printf(" ");
		for (int j = 0; j < 2 * t - 1; j++)
			printf("%c", j % 2 == 0 ? '*' : ' ');
	}
	return 0;
}