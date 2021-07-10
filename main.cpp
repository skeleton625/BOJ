#include <cstdio>
#include <cstring>
#include <cstdlib>

int b, c, l;
char i1[5], r[10000];
int main() {
	scanf_s("%s %d", i1, 5, &b);
	l = strlen(i1);
	if (l*atoi(i1) > b) for (int i = 0; i < b; i++, c %= l) r[i] = i1[c++];
	else {
		for (int i = 0; i < atoi(i1)*l; i++, c %= l) r[i] = i1[c++];
	}
	printf("%s", r);
	return 0;
}