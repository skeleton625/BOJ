#include <cstdio>
#include <cstring>

int a[26];
char i1[101];
int main() {
	scanf_s("%s", i1, 101);
	memset(a, -1,sizeof(int)*26);
	for (int i = 0; i1[i]; i++) { if (a[i1[i] - 'a'] == -1) a[i1[i] - 'a'] = i; }
	for (int i = 0; i < 26; i++) printf("%d ", a[i]);
	return 0;
}