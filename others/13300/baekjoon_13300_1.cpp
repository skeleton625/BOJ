#include <cstdio>

int num[2][6];
int t, rm, ans, s, n;
int main() {
	scanf_s("%d %d", &t, &rm);
	while (t--) {
		scanf_s("%d %d", &s, &n);
		++num[s][n - 1];
	}
	for (int i = 0; i < 6; i++) {
		ans += (num[0][i]+rm-1) / rm;
		ans += (num[1][i]+rm-1) / rm;
	}
	printf("%d", ans);
	return 0;
}