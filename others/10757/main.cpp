#include <cstdio>
#include <cstring>

int p, m, a, b;
char i1[10002], i2[10002], r[10002];
int main() {
	scanf_s("%s %s", i1, 10002, i2, 10002);
	a = strlen(i1); b = strlen(i2);
	m = a > b ? a : b;
	while (m--) {
		if (a > 0 && b > 0) {
			r[m] = (i1[--a] + i2[--b] - 96 + p) % 10 + 48;
			p = (i1[a] + i2[b] - 96) / 10;
		}
		else if (a == 0 && b > 0) {
			r[m] = (i2[--b] - 48 + p) % 10 + 48;
			p = (i2[b] - 48 + p) / 10;
		}
		else if (b == 0 && a > 0) {
			r[m] = (i1[--a] - 48 + p) % 10 + 48;
			p = (i1[a] - 48 + p) / 10;
		}
	}
	if (p == 1) printf("1");
	printf("%s", r);
	return 0;
}