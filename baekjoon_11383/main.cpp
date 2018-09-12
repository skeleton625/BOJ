#include <cstdio>
#include <cstring>

int m, n, c;
char a1[101], a2[201], i1[11], i2[21];
bool ey;
int main() {
	scanf_s("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf_s("%s", i1, 11);
		strcat_s(a1, i1);
	}
	for (int i = 0; i < m; i++) {
		scanf_s("%s", i2, 21);
		strcat_s(a2, i2);
	}
	for (int i = 0; a1[i]; i++) {
		if (a1[i] != a2[c++] || a1[i] != a2[c++]) {
			printf("Not Eyfa");
			return 0;
		}
	}
	printf("Eyfa");
	return 0;
}