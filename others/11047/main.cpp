#include "cstdio"

int *coin;
int n, k, c;

int main() {
	scanf_s("%d %d", &n, &k);
	coin = new int[n];
	while (n--) {
		scanf_s("%d", &coin[c++]);
		if (coin[c - 1] > k) break;
	}
	n = 0;

	while (k) {
		if (coin[c - 1] > k) c--;
		else {
			n += k / coin[c - 1];
			k %= coin[c - 1];
		}
	}
	printf("%d", n);
	return 0;
}