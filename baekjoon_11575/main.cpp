#include <cstdio>
using namespace std;

int t, a, b;
char i1[1000001];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d %d%*c", &a, &b);
		gets_s(i1, 1000001);
		for (int i = 0; i1[i]; i++) printf("%c", (a*(i1[i] - 'A') + b) % 26 + 'A');
		printf("\n");
	}
	return 0;
}