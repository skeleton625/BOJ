#include <cstdio>
#include <cstring>

int t;
char na[21];
int main() {
	scanf_s("%s", na, 21);
	t = strlen(na);
	for (int i = 0; i < t/2; i++) {
		if (na[i] != na[t - i - 1]) {
			printf("false");
			return 0;
		}
	}
	printf("true");
	return 0;
}