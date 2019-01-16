#include <cstdio>

int n, q;
int *queen;

bool promising(int floor) {
	for (int i = 0; i < floor; i++) {
		if (queen[i] - queen[floor] == 0 ||
			queen[i] - queen[floor] == floor - i ||
			queen[i] - queen[floor] == i - floor)
			return false;
	}
	return true;
}

bool find_queen(int floor) {
	if (!promising(floor-1)) {
		return false;
	} else if (floor == n) {
		return true;
	} else {
		for (int i = 0; i < n; i++) {
			if (q >= n) q = 0;
			queen[floor] = q;
			q++;
			if (find_queen(floor + 1)) {
				return true;
			}
		}
		return false;
	}
}

void print_queen() {
	for (int i = 0; i < n; i++)
		printf("%d\n", queen[i]+1);
}

int main() {
	scanf_s("%d", &n);
	queen = new int[n];

	find_queen(0);
	print_queen();

	return 0;
}