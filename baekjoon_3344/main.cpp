#include <cstdio>
#include <cstring>

bool *queen_center, *queen_right, *queen_left;
int n;

bool find_queen(int floor) {
	if (floor == n) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		if (!(queen_center[i] || queen_right[floor + i] || queen_left[n - 1 + floor - i])) {
			queen_center[i] = queen_right[floor + i] = queen_left[n - 1 + floor - i] = true;
			if (find_queen(floor + 1)) {
				printf("%d\n", i + 1);
				return true;
			}
			else {
				queen_center[i] = queen_right[floor + i] = queen_left[n - 1 + floor - i] = false;
			}
		}
		
	}
	return false;
}

int main() {
	scanf_s("%d", &n);
	queen_center = new bool[n];
	queen_right = new bool[n];
	queen_left = new bool[n];

	memset(queen_center, 0, sizeof(bool)*n);
	memset(queen_right, 0, sizeof(bool)*(2 * n - 1));
	memset(queen_left, 0, sizeof(bool)*(2 * n - 1));

	find_queen(0);

	return 0;
}