#include <cstdio>
#include <cstring>

int t, i, c = 0;
char na[101], r[101];
int main() {
	scanf_s("%d%*c", &t);
	while (t--) {
		gets_s(na);
		memset(r, 0, 101);
		for (i = 0; na[i] != ' '; i++);
		for (; na[i]; i++) {
			if(na[i] != ' ') r[c++] = na[i];
		}
		printf("god%s\n", r);
		c = 0;
	}
	return 0;
}