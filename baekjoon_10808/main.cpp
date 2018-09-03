#include <cstdio>

int a[26];
char i1[101];
int main() {
	scanf_s("%s", i1, 101);
	for (int i = 0; i1[i]; i++) a[i1[i] - 'a']++;
	for (int i = 0; i < 26; i++) printf("%d ", a[i]);
	return 0;
}