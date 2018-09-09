#include <cstdio>
#include <cstring>
#include <cstdlib>

int t, m, c;
char i1[701], n[6];
int main() {
	scanf_s("%d%*c", &t);
	while (t--) {
		gets_s(i1, 701);
		for (int i = 0; i1[i]; i++) {
			if (i1[i] != ' ') n[c++] = i1[i];
			else {
				m += atoi(n);
				memset(n, 0, 6);
				c = 0;
			}
		}
		m += atoi(n);
		memset(n, 0, 6);
		c = 0;
		printf("%d\n", m);
		m = 0;
	}
	return 0;
}