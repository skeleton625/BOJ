#include <cstdio>

char i1[101];
int main() {
	gets_s(i1, 101);
	for (int i = 0; i1[i]; i++) {
		if (i1[i] >= 'A'&&i1[i] <= 'Z') i1[i] = (i1[i] - 'A' + 13) % 26 + 'A';
		else if (i1[i] >= 'a'&&i1[i] <= 'z') i1[i] = (i1[i] - 'a' + 13) % 26 + 'a';
	}
	printf("%s", i1);
	return 0;
}