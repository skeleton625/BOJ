#include <cstdio>

int num[2][7];
int t, rm, ans, s, n, tmp_c;
int main() {
	scanf_s("%d %d", &t, &rm);
	while (t--) {
		scanf_s("%d %d", &s, &n);
		num[s][n]++;
	}
	for (int i = 1; i < 7; i++) {
		ans += num[0][i] / rm + (num[0][i]%rm==0? 0:1);
		ans += num[1][i] / rm + (num[1][i]%rm==0? 0 : 1);
	}
	printf("%d", ans);
	return 0;
}