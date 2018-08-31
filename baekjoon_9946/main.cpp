#include <cstdio>
#include <string.h>

int al1[26], al2[26], c, t = 1;
char i1[1001], i2[1001];
int main() {
	while (scanf_s("%s", i1, 1001) && scanf_s("%s", i2, 1001)) {
		if (strcmp(i1, "END") == 0 && strcmp(i2, "END") == 0) break;
		for (int i = 0; i1[i]; i++) al1[i1[i] - 'a']++;
		for (int i = 0; i2[i]; i++) al2[i2[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (al1[i] == al2[i])c++;
			al1[i] = 0; al2[i] = 0;
		}
		printf("Case %d: ", t++);
		if (c == 26) printf("same\n");
		else printf("different\n");
		c = 0;
	}
	return 0;
}