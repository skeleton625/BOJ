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
	현재 구슬 위치(x,y)에서 특정 방향(i)으로 끝까지 이동시키는 함수
	이동 결과가 x, 또는 y에 입력될 수 있기 때문에 주소로 직접 입력해줌. 
*/
void marble_move(int& x, int& y, int i) {
	while (1) {
		/* i 방향으로 계속 이동시켜줌. */
		x += dir[i][0], y += dir[i][1];
		/* 계속 이동하다 벽을 만날 경우 종료. */
		if (mat[x][y] == 1) {
			x -= dir[i][0], y -= dir[i][1];
			break;
		} 
		/* 계속 이동하다 목적지에 도달할 경우 종료. */
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
	/* matrix 입력 */
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
		현재 R, B 구슬의 위치를 구조체 ball의 변수에 입력해
		ball을 자료형으로 갖는 queue에 입력
	*/
	que.push({ 0,prx,pry,pbx,pby });
	/* R, B 구슬의 현재 위치 방문 체크 */
	visit[prx][pry][pbx][pby] = true;
	/* 모든 접근 가능한 경우의 수를 파악하기 전까지 반복문을 종료 안함 */
	while (!que.empty()) {
		/* queue에 저장된 첫 번째 ball 변수를 확인 */
		ball cur = que.front(); que.pop();

		/* 깊이(회전 횟수)가 10을 넘을 경우 반복문 종료 -> 실패 */
		if (cur.d > 10) {
			break;
		} 
		/* 
			현재 위치가 목적지(O)일 경우 현재 깊이를 결과 변수에 입력,
			반복문을 종료 -> 성공
		*/
		else if (cur.rx == dx && cur.ry == dy) {
			re = cur.d;
			break;
		}

		/* 현재 이동할 수 있는 모든 경우의 수를 탐색 */
		for (int i = 0; i < 4; i++) {
			/* 현재 ball 변수에 저장된 R, B 구슬의 위치를 각 변수에 입력 */
			int rx = cur.rx; int ry = cur.ry;
			int bx = cur.bx; int by = cur.by;
			/* 
				각 변수들을 특정 방향(i)로 끝까지 이동시킴.
				여기서 R, B 구슬이 겹치는 경우는 신경쓰지 않음.
			*/
			marble_move(rx, ry, i); marble_move(bx, by, i);

			/*
				이동 도중, B 구슬이 목적지에 도착할 경우 해당 경우는 제외시켜줌.
			*/
			if (bx == dx && by == dy) continue;
			/* 
				R, B 구슬이 겹칠 경우 ball 변수를 통해 이동 전 R, B 구슬의 
				위치를 파악해 위치를 조정해줌.
			*/
			else if (rx == bx && ry == by) {
				switch (i) {
				/* 
					0 -> x축 위, 1 -> y축 왼쪽, 2 -> x축 아래, 3 -> y축 오른쪽
					(배열에서 얘기하는 x - 첫 번째 배열, y - 두번째 배열 축)
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
				이동한 위치가 방문하지 않은 경우, 이동한 위치에서 생길 수 있는
				다른 경우를 확인하기 위해 queue에 입력.
			*/
			if (!visit[rx][ry][bx][by]) {
				que.push({ cur.d + 1,rx,ry,bx,by });
				visit[rx][ry][bx][by] = true;
			}
		}
	}
	/* 
		결과값을 출력.
		성공한 경우 -> 해당 깊이(회전 횟수)를 출력함.
		실패한 경우 -> -1을 출력함.
		(1. B 구슬이 결국 목적지에 도착함,
		 2. 깊이(회전 횟수)가 10을 초과함)
	*/
	cout << re;
	return 0;
}

/* 알고리즘 도움 https://js1jj2sk3.tistory.com/105 */
/* 알고리즘 주석 -> 필자 */