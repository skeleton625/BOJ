#include <cstdio>
#include <string>

int gcd(int x, int y) {
	int t;
	while (y) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int main() {
	int t, m, n, x, y;
	int max, ty;
	std::string result;
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d %d %d %d", &m, &n, &x, &y);
		max = (m*n) / gcd(m, n);
		while (1) {
			ty = x % n == 0 ? n : x % n;
			if (ty == y) { break; }
			else if (x > max) {
				x = -1;
				break;
			}
			x += m;
		}
		result.append(std::to_string(x) + '\n');
	}
	puts(result.c_str());
	return 0;
}
