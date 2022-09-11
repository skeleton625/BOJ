#include <cstdio>

int h, w, m;
char i1[101];
int main() {
	scanf_s("%d %d%*c", &h, &w);
	for (int i = 0; i < h; i++) {
		gets_s(i1, 101);
		m = -1;
		for (int j = 0; i1[j]; j++) {
			if (i1[j] == 'c') m = 0;
			else if (m >= 0) m++;
			printf("%d ", m);
		}
		printf("\n");
	}
	return 0;
}