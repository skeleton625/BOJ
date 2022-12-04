#include <cstdio>

int al1[26], al2[26], c, t = 1;
char i1[1001], i2[1001];
int main() {
	while (gets_s(i1,1001)&&gets_s(i2,1001)){
		if (i1[0] < 'a') break;
		for (int i = 0; i1[i]; i++) al1[i1[i] - 'a']++;
		for (int i = 0; i2[i]; i++) al2[i2[i] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (al1[i] == al2[i])c++;
			al1[i] = al2[i] = 0;
		}
		printf("Case %d: %s\n", t++, c == 26 ? "same" : "different");
		c = 0;
	}
	return 0;
}