#include <cstdio>

int t, i1;
int n[8];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d%d%d%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5], &n[6], &n[7]);
		n[0] += n[4]; n[1] += n[5]; n[2] += n[6]; n[3] += n[7];
		n[0] <= 0 ? 1 : n[0]; n[1] <= 0 ? 1 : n[1]; n[2] <= 0 ? 0 : n[2];
		printf("%d\n", n[0] + 5 * n[1] + 2 * n[2] + 2 * n[3]);
	}
	return 0;
}