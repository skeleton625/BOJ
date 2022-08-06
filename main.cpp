#include <cstdio>

char i1[101];
int a1, a2, s, n;
int main() {
	while (gets_s(i1, 101)){
		for (int i = 0; i < i1[i]; i++) {
			if (i1[i] >= 'A'&&i1[i] <= 'Z') a1++;
			else if (i1[i] >= 'a'&&i1[i] <= 'z') a2++;
			else if (i1[i] >= '0'&& i1[i] <= '9') n++;
			else s++;
		}
		printf("%d %d %d %d\n", a2, a1, n, s);
		a1 = 0; a2 = 0; n = 0; s = 0;
	}
	return 0;
}