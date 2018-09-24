#include <cstdio>

int i1, y = 2014, m = 4, d = 1;
int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	scanf_s("%d", &i1);
	while (i1 > mon[m - 1]) {
		i1 -= mon[m - 1];
		m++;
		if (m == 13) { 
			m= 1; y++;
			mon[1] = (y%4 == 0 && y%100 != 0) ? 29 : y%400 == 0 ? 29 : 28;
		}
	}
	d += i1;
	if (d > mon[m - 1]) { d -= mon[m - 1]; m++; }
	if (m == 13) { m = 1; y++; }
	printf("%d-%02d-%02d", y, m, d);
	return 0;
}
