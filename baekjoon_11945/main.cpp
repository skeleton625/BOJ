#include <cstdio>
#include <algorithm>

int a, b;
char i1[11];
int main() {
	scanf_s("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		scanf_s("%s", i1, 11);
		std::reverse(i1, i1 + b);
		printf("%s", i1);
	}
	return 0;
}