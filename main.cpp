#include <cstdio>

int num[25], ans[26], i1, c, i;
int main() {
	for (i = 0; i < 25; i++) scanf_s("%d", &num[i]);
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &i1);
		ans[i1] = 1;
	}
	for (i = 11; i <= 25; i++) {
		scanf_s("%d", &i1);
		ans[i1] = 1;
		for (int j = 0; j < 5; j++) {
			if (ans[num[5 * j]] && ans[num[5 * j + 1]] && ans[num[5 * j + 2]] 
				&& ans[num[5 * j + 3]] && ans[num[5 * j + 4]]) c++;
			if (ans[num[j]] && ans[num[5 + j]] && ans[num[10 + j]] 
				&& ans[num[15 + j]] && ans[num[20 + j]]) c++;
		}
		if (ans[num[0]] && ans[num[6]] && ans[num[12]] && ans[num[18]] && ans[num[24]]) c++;
		if (ans[num[4]] && ans[num[8]] && ans[num[12]] && ans[num[16]] && ans[num[20]]) c++;
		if (c >= 3) break;
		c = 0;
	}
	printf("%d", i);
	return 0;
}