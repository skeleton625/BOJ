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
	/* ����ִ� ������ ��� ä���� ��� ���� ��ȯ */
	if (c == emp.size()) return true;
	/* �׷��� ���� ��� */
	else {
		/* ���� ����ִ� ������ ��ġ�� �� �� �ִ� ���ڸ� ã���� */
		for (int i = 1; i < 10; i++) {
			/* 1 ~ 9 ������ ���ڸ� ������ ���������� �ľ� */
			if (!ex_num[0][emp[c].x][i] && !ex_num[1][emp[c].y][i] && !ex_num[2][emp[c].sqa][i]) {
				/* 
					������ ���ڸ� ã�� ��� �ش� ĭ�� ã�� ���ڷ� ä����.
					���ڸ� ã�ұ� ������ x, y, ��� ��ġ�� ã�� ���ڰ� �����Ѵٴ� ���� ǥ��.
				*/
				ex_num[0][emp[c].x][i] = ex_num[1][emp[c].y][i] = ex_num[2][emp[c].sqa][i] = true;
				mat[emp[c].x][emp[c].y] = i;
				/* ���� ��ĭ���� �̵�, ���� ��ĭ ���� ���ڸ� ã�� ��� true�� ��ȯ */
				if (find_num(c + 1)) return true;
				/* 
					�׷��� ���� ��� ã�� ���ڴ� ���� ���ڰ� �ƴϹǷ� ���ڸ� ����.
					ã�� ���ڿ� ���� x, y, ��� ��ġ�� ǥ�� ����.
				*/
				ex_num[0][emp[c].x][i] = ex_num[1][emp[c].y][i] = ex_num[2][emp[c].sqa][i] = false;
				mat[emp[c].x][emp[c].y] = 0;
			}
		}
		/* 1 ~ 9 ���� ��� �Ұ����� ��� ������ ��ȯ */
		return false;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ������ ���� ���� �Է� */
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			if (mat[i][j]) {
				/* ���� ������ ĭ�� ���ڰ� ���� ��� x��, y��, �ش� ��Ͽ� �Էµ� ��ȣ�� �������� ���� */
				ex_num[0][i][mat[i][j]] = 1;
				ex_num[1][j][mat[i][j]] = 1;
				ex_num[2][(i / 3) * 3 + (j / 3)][mat[i][j]] = 1;
			} else
				/* ���� ������ ĭ�� ������� ��� ���߿� ä���ֱ� ���� ��ġ(x,y,���)�� ���� */
				emp.push_back({ i, j, (i / 3) * 3 + (j / 3) });
		}
	}

	/* 
		������ ����ִ� ĭ�� ä��� �Լ� ����.
		��� ĭ�� ä���� ���ϴ� �Է��� �־����� �����Ƿ� �ٸ� ó���� ����.
	*/
	find_num(0);

	/* �ϼ��� ����ũ ���� ������ ��� */
	for (int i = 0; i < 9; i++) {
		string result = "";
		/* �� ���� ���� ���ڿ� ������ �Է��� �� ���� ��� */
		for (int j = 0; j < 9; j++)
			result += to_string(mat[i][j]) + ' ';
		cout << result << '\n';
	}
	return 0;
}