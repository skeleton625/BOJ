#include <cstdio>

int t, m, n;
int main() {
	scanf_s("%d", &t);
	while (t--) {
		do {
			scanf_s("%d", &n);
			m += n;
		} while (getchar() == ' ');
		printf("%d\n", m);
		m = 0;
	}
	return 0;
}