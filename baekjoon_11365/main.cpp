#include <cstdio>
#include <cstring>
#include <algorithm>

char i1[501];
int main() {
	while (gets_s(i1, 501) && (strcmp(i1, "END") != 0)) {
		std::reverse(i1, i1 + strlen(i1));
		printf("%s\n", i1);
	}
	return 0;
}