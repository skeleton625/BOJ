#include <cstdio>
#include <cstring>

int t, m, c;
char i1[10001], p[101];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		m = 0; c = 0;
		scanf_s("%s %s", i1, 10001, p, 101);
		for (int i = 0; i1[i]; i++) {
			if (i1[i] == p[c]) c++;
			else if(p[0] == i1[i]){ m += c; c = 1; }
			else { m += c + 1; c = 0; }
			if (c == strlen(p)) { c = 0; m++; }
		}
		m += c;
		printf("%d\n", m);
	}
	return 0;
}