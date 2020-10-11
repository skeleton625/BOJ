#include <iostream>
#include <cstring>
using namespace std;

int n, c;
/* 행, 왼쪽 대각선, 오른쪽 대각선*/
/*
	queen은 좌,우 대각선과 행, 열로 이동할 수 있다
	여기서 queen_col은 해당 층(행)에서 queen이 위치한 번호,
	queen_right_up은 해당 층(행)에서 queen이 오른쪽 대각선으로 움직일 수 있는 칸,
		-> 참고로 해당 대각선 칸은 해당 층수 + queen이 위치한 열 번호 이다.
	queen_left_up은 해당 층(행)에서 queen이 왼쪽 대각선으로 움직일 수 있는 칸 이다.
		-> 참고로 해당 대각선 칸은 전체 층수 - 1 + (해당 층수 - queen이 위치한 열 번호) 이다.
*/
/* 체스판(2차원배열)에서 좌, 우 대각선의 개수는 각각 2*n-1개 */
bool *queen_col, *queen_right_up, *queen_left_up;

void count_queen_pos(int floor) {
	if (floor == n) {
		c++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (queen_col[i] || queen_right_up[floor + i] || queen_left_up[n - 1 + floor - i])
			continue;
		queen_col[i] = queen_right_up[floor + i] = queen_left_up[n - 1 + floor - i] = 1;
		count_queen_pos(floor+1);
		queen_col[i] = queen_right_up[floor + i] = queen_left_up[n - 1 + floor - i] = 0;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	queen_col = new bool[n];
	queen_right_up = new bool[2 * n - 1];
	queen_left_up = new bool[2 * n - 1];

	memset(queen_col, 0, sizeof(bool)*n);
	memset(queen_right_up, 0, sizeof(bool)*(2*n-1));
	memset(queen_left_up, 0, sizeof(bool)*(2*n-1));

	count_queen_pos(0);
	cout << c;

	return 0;
}