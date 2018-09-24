#include <cstdio>

int t, i1;
int n[4];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; i++) scanf_s("%d", &n[i]);
		for (int i = 0; i < 4; i++) { 
			scanf_s("%d", &i1); 
			n[i] += i1; 
		}
		for (int i = 0; i < 2; i++) {
			if (n[i] < 1) n[i] = 1;
		}
		if (n[2] < 0) n[2] = 0;
		printf("%d\n", n[0] + 5 * n[1] + 2 * n[2] + 2 * n[3]);
	}
	return 0;
}