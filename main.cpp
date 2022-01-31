#include <cstdio>

int t;
bool s = true;
int main() {
	scanf_s("%d", &t);
	for (int i = 0; i < t; ++i&&printf("\n")) {
		for (int j = t - i - 1; j > 0; j--) printf(" ");
		for (int j = 1; j <= 2*i + 1; j++) {
			printf("%c", s ? '*' : ' ');
			s = !s;
		}
		s = true;
	}
	
	return 0;
}