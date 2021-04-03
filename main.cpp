#include <cstdio>
#include <cstring>

int t;
char i1[101], r[101];
char tm[26] = { 'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q' };
int main() {
	scanf_s("%d%*c", &t);
	for (int i = 0; i < t; i++) {
		gets_s(i1, 101);
		for (int j = 0; j < strlen(i1); j++) {
			if(i1[j] != ' ') r[j] = tm[(i1[j] - 'a')];
			else r[j] = i1[i];
		}
		printf("Case #%d: %s\n", i+1, r);
		memset(r, 0, 101);
	}
	return 0;
}