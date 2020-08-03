#include <iostream>
#include <queue>
using namespace std;

struct ball {
	int d, rx, ry, bx, by;
};
int a, b;
int mat[10][10];
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
bool visit[10][10][10][10];
char in[11];

/* 
	���� ���� ��ġ(x,y)���� Ư�� ����(i)���� ������ �̵���Ű�� �Լ�
	�̵� ����� x, �Ǵ� y�� �Էµ� �� �ֱ� ������ �ּҷ� ���� �Է�����. 
*/
void marble_move(int& x, int& y, int i) {
	while (1) {
		/* i �������� ��� �̵�������. */
		x += dir[i][0], y += dir[i][1];
		/* ��� �̵��ϴ� ���� ���� ��� ����. */
		if (mat[x][y] == 1) {
			x -= dir[i][0], y -= dir[i][1];
			break;
		} 
		/* ��� �̵��ϴ� �������� ������ ��� ����. */
		else if (mat[x][y] == 2) {
			break;
		}
	}
}

int main() {
	int prx, pry, pbx, pby, dx, dy, re = -1;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	/* matrix �Է� */
	for (int i = 0; i < a; i++) {
		cin >> in;
		for (int j = 0; j < b; j++) {
			switch (in[j]) {
			case '#':
				mat[i][j] = 1;
				break;
			case '.':
				mat[i][j] = 0;
				break;
			case 'O':
				mat[i][j] = 2;
				dx = i, dy = j;
				break;
			case 'R':
				prx = i, pry = j;
				break;
			case 'B':
				pbx = i, pby = j;
				break;
			}
		}
	}

	queue<ball> que;
	/* 
		���� R, B ������ ��ġ�� ����ü ball�� ������ �Է���
		ball�� �ڷ������� ���� queue�� �Է�
	*/
	que.push({ 0,prx,pry,pbx,pby });
	/* R, B ������ ���� ��ġ �湮 üũ */
	visit[prx][pry][pbx][pby] = true;
	/* ��� ���� ������ ����� ���� �ľ��ϱ� ������ �ݺ����� ���� ���� */
	while (!que.empty()) {
		/* queue�� ����� ù ��° ball ������ Ȯ�� */
		ball cur = que.front(); que.pop();

		/* ����(ȸ�� Ƚ��)�� 10�� ���� ��� �ݺ��� ���� -> ���� */
		if (cur.d > 10) {
			break;
		} 
		/* 
			���� ��ġ�� ������(O)�� ��� ���� ���̸� ��� ������ �Է�,
			�ݺ����� ���� -> ����
		*/
		else if (cur.rx == dx && cur.ry == dy) {
			re = cur.d;
			break;
		}

		/* ���� �̵��� �� �ִ� ��� ����� ���� Ž�� */
		for (int i = 0; i < 4; i++) {
			/* ���� ball ������ ����� R, B ������ ��ġ�� �� ������ �Է� */
			int rx = cur.rx; int ry = cur.ry;
			int bx = cur.bx; int by = cur.by;
			/* 
				�� �������� Ư�� ����(i)�� ������ �̵���Ŵ.
				���⼭ R, B ������ ��ġ�� ���� �Ű澲�� ����.
			*/
			marble_move(rx, ry, i); marble_move(bx, by, i);

			/*
				�̵� ����, B ������ �������� ������ ��� �ش� ���� ���ܽ�����.
			*/
			if (bx == dx && by == dy) continue;
			/* 
				R, B ������ ��ĥ ��� ball ������ ���� �̵� �� R, B ������ 
				��ġ�� �ľ��� ��ġ�� ��������.
			*/
			else if (rx == bx && ry == by) {
				switch (i) {
				/* 
					0 -> x�� ��, 1 -> y�� ����, 2 -> x�� �Ʒ�, 3 -> y�� ������
					(�迭���� ����ϴ� x - ù ��° �迭, y - �ι�° �迭 ��)
				*/
				case 0:
					cur.rx < cur.bx ? bx++ : rx++;
					break;
				case 1:
					cur.ry < cur.by ? by++ : ry++;
					break;
				case 2:
					cur.rx < cur.bx ? rx-- : bx--;
					break;
				case 3:
					cur.ry < cur.by ? ry-- : by--;
				}
			}
			/* 
				�̵��� ��ġ�� �湮���� ���� ���, �̵��� ��ġ���� ���� �� �ִ�
				�ٸ� ��츦 Ȯ���ϱ� ���� queue�� �Է�.
			*/
			if (!visit[rx][ry][bx][by]) {
				que.push({ cur.d + 1,rx,ry,bx,by });
				visit[rx][ry][bx][by] = true;
			}
		}
	}
	/* 
		������� ���.
		������ ��� -> �ش� ����(ȸ�� Ƚ��)�� �����.
		������ ��� -> -1�� �����.
		(1. B ������ �ᱹ �������� ������,
		 2. ����(ȸ�� Ƚ��)�� 10�� �ʰ���)
	*/
	cout << re;
	return 0;
}

/* �˰��� ���� https://js1jj2sk3.tistory.com/105 */
/* �˰��� �ּ� -> ���� */