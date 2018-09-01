#include <cstdio>
#include <cstring>

int n;
char i1[81], n1[4] = { 'n','e','m','o' }, n2[4] = { 'N', 'E', 'M', 'O' };
int main() {
	while (gets_s(i1, 81)) {
		if (strcmp(i1, "EOI") == 0) break;
		for (int i = 0; i1[i]; i++) {
			if (i1[i] == n1[n] || i1[i] == n2[n]) {
				n++;
			} else n = 0;
			if (n == 4) break;
		}
		if (n == 4) printf("Found\n");
		else printf("Missing\n");
		n = 0;
	}
	return 0;
}