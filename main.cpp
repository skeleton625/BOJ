#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct zero_pos {
	int x, y, sqa;
};

int mat[9][9];
bool ex_num[3][10][10];
vector<zero_pos> emp;

bool find_num(int c) {
	/* 비어있는 공간을 모두 채웠을 경우 참을 반환 */
	if (c == emp.size()) return true;
	/* 그렇지 않은 경우 */
	else {
		/* 현재 비어있는 공간의 위치에 들어갈 수 있는 숫자를 찾아줌 */
		for (int i = 1; i < 10; i++) {
			/* 1 ~ 9 까지의 숫자를 대입해 가능한지를 파악 */
			if (!ex_num[0][emp[c].x][i] && !ex_num[1][emp[c].y][i] && !ex_num[2][emp[c].sqa][i]) {
				/* 
					가능한 숫자를 찾을 경우 해당 칸을 찾은 숫자로 채워줌.
					숫자를 찾았기 때문에 x, y, 블록 위치에 찾은 숫자가 존재한다는 것을 표시.
				*/
				ex_num[0][emp[c].x][i] = ex_num[1][emp[c].y][i] = ex_num[2][emp[c].sqa][i] = true;
				mat[emp[c].x][emp[c].y] = i;
				/* 다음 빈칸으로 이동, 다음 빈칸 또한 숫자를 찾을 경우 true를 반환 */
				if (find_num(c + 1)) return true;
				/* 
					그렇지 못할 경우 찾은 숫자는 옳은 숫자가 아니므로 숫자를 제거.
					찾은 숫자에 대한 x, y, 블록 위치의 표시 제거.
				*/
				ex_num[0][emp[c].x][i] = ex_num[1][emp[c].y][i] = ex_num[2][emp[c].sqa][i] = false;
				mat[emp[c].x][emp[c].y] = 0;
			}
		}
		/* 1 ~ 9 까지 모두 불가능할 경우 거짓을 반환 */
		return false;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 현재 스도쿠 판의 정보 입력 */
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			if (mat[i][j]) {
				/* 현재 스도쿠 칸에 숫자가 있을 경우 x축, y축, 해당 블록에 입력된 번호가 존재함을 저장 */
				ex_num[0][i][mat[i][j]] = 1;
				ex_num[1][j][mat[i][j]] = 1;
				ex_num[2][(i / 3) * 3 + (j / 3)][mat[i][j]] = 1;
			} else
				/* 현재 스도쿠 칸이 비어있을 경우 나중에 채워주기 위해 위치(x,y,블록)를 저장 */
				emp.push_back({ i, j, (i / 3) * 3 + (j / 3) });
		}
	}

	/* 
		스도쿠에 비어있는 칸을 채우는 함수 실행.
		모든 칸을 채우지 못하는 입력은 주어지지 않으므로 다른 처리는 안함.
	*/
	find_num(0);

	/* 완성된 스도크 판의 정보를 출력 */
	for (int i = 0; i < 9; i++) {
		string result = "";
		/* 한 줄의 값을 문자열 변수에 입력해 한 번에 출력 */
		for (int j = 0; j < 9; j++)
			result += to_string(mat[i][j]) + ' ';
		cout << result << '\n';
	}
	return 0;
}