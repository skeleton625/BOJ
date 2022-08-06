#include <cstdio>

int n[101];
int i1, i2, t, m, tmp;
int main() {
	scanf_s("%d %d", &m, &t);
	for (int i = 1; i <= m; i++) n[i] = i;
	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &i1, &i2);
		tmp = n[i1]; n[i1] = n[i2]; n[i2] = tmp;
	}
	for (int i = 1; i <= m; i++) printf("%d ", n[i]);
	return 0;
}