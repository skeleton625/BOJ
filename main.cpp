#include <cstdio>
#include <cstring>


char i1[81];
int main() {
	while (gets_s(i1, 81)) {
		if (strcmp(i1, "EOI") == 0) break;
		for (int i = 0; i1[i]; i++) if (i1[i] >= 'A'&& i1[i] <= 'Z') { i1[i] += 32; }
		printf(strstr(i1, "nemo") ? "Found\n" : "Missing\n");
	}
	return 0;
}