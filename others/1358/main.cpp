#include <iostream>
using namespace std;

int player[100][2];
int pos[4][2];

int distance(int* mark, int* p) {
	int x = mark[0] - p[0], y = mark[1] - p[1];
	return x * x + y * y;
}

int main() {
	int w, h, x, y, p, r;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> w >> h >> x >> y >> p;
	for (int i = 0; i < p; i++) 
		cin >> player[i][0] >> player[i][1];
	r = h / 2;

	pos[0][0] = x, pos[0][1] = y + r;
	pos[1][0] = x, pos[1][1] = y;
	pos[2][0] = x + w, pos[2][1] = y + h;
	pos[3][0] = x + w, pos[3][1] = y + r;

	int cnt = 0;
	r *= r;
	for (int i = 0; i < p; i++) {
		if ((distance(pos[0], player[i]) <= r) || (distance(pos[3],player[i]) <= r)) {
			++cnt;
			continue;
		} else if ((pos[1][0] <= player[i][0] && pos[1][1] <= player[i][1])&&(
					pos[2][0] >= player[i][0] && pos[2][1] >= player[i][1])) {
			++cnt;
			continue;
		}
	}
	cout << cnt;
	return 0;
}