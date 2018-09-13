#include <cstdio>
#include <cstring>

int t, c, l, m;
char sc[21], r[21];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &c);
		while (c--) {
			scanf_s("%s %d", sc, 21, &l);
			if (m < l) {
				strcpy_s(r, sc);
				m = l;
			}
		}
		printf("%s\n", r);
	}
	return 0;
}