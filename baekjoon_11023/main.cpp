#include <cstdio>
#include <cstring>
#include <cstdlib>

int m, c;
char n[701], t[6];
int main() {
	gets_s(n, 701);
	for (int i = 0; i < strlen(n); i++) {
		if (n[i] != ' ') t[c++] = n[i];
		else {
			c = 0;
			m += atoi(t);
			memset(t, 0, 6);
		}
	}
	m += atoi(t);
	printf("%d", m);
	return 0;
}