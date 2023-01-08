#include <cstdio>
#include <algorithm>

int n, tmp[100] = { 1 }, t = 1, m;
int main() {
	while (scanf_s("%d", &n) && (n != -1)) {
		m = n;
		for (int i = 2; i < n; i++){
			if (n%i == 0) {
				if (tmp[t-1] == i) break;
				tmp[t++] = i;
				tmp[t++] = n / i;
				m -= (i + n / i);
			}
		}
		if (m == 1) {
			printf("%d = 1", n);
			std::sort(tmp, tmp + t);
			for (int i = 1; i < t; i++) printf(" + %d", tmp[i]);
		}
		else printf("%d is NOT perfect.", n);
		printf("\n");
		t = 1;
	}
	return 0;
}