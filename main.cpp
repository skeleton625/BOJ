#include <cstdio>

int t, m, s, e, ma;
int main() {
	scanf_s("%d\n%d", &t, &m);
	ma = m;
	while (t--) {
		scanf_s("%d %d", &s, &e);
		m += s - e;
		if (m < 0) {
			ma = 0;
			break;
		}
		if (ma < m) ma = m;
	}
	printf("%d", ma);
	return 0;
}