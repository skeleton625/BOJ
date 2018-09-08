#include <cstdio>

int t, s, c, m;
double g, n;
int main(){
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &s);
		for (int i = 0; i < s; i++) {
			scanf_s("%d %lf", &c, &g);
			m += c; n += c*g;
		}
		printf("%d %.1lf\n", m, n / m);
		m = 0; n = 0;
	}
	return 0;
}