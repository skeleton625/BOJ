#include <cstdio>
#include <cstring>

int s;
char i1[101];
int main() {
	scanf_s("%s", i1,101);
	s = strlen(i1);
	for (int i = 0; i < s/2; i++) {
		if (i1[i] != i1[s - i - 1]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}