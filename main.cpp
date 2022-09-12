#include <cstdio>
#include <cstring>

int t, s, m;
char i1[200];
int main() {
	scanf_s("%d%*c", &t);
	while (t--) {
		gets_s(i1, 200);
		s = strlen(i1);
		for (int i = 0; i < s / 2; i++) {
			if (i1[i] >= 'A'&&i1[i] <= 'Z') i1[i] += 32;
			if (i1[s - i - 1] >= 'A'&&i1[s - i - 1] <= 'Z') i1[s - i - 1] += 32;
			if (i1[i] == i1[s - i - 1]) m++;
			else break;
		}
		if (m == s / 2) printf("Yes\n");
		else printf("No\n");
		m = 0;
	}
	return 0;
}