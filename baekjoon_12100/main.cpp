#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct board {
	/* 현재 판 정보, 회전 수(깊이), 최대 값*/
	int mat[20][20];
	int d;
	int m;
};

/* 판 입력 배열, 판의 크기 변수*/
int in[20][20];
int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	board first;	/* 처음 판 번호를 입력할 board 변수 */
	int max = 0;

	/* 판 크기 입력*/
	cin >> n;
	/* 판 정보 입력 */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> first.mat[i][j];
	}
	first.d = 0;
	first.m = 0;

	/* BFS를 실행할 queue 변수 정의, 입력된 판 정보를 입력 */
	queue<board> que;
	que.push(first);

	/* BFS 시작 */
	while (!que.empty()) {
		board cur = que.front(); que.pop();

		/* 회전 횟수(깊이)가 5가 될 경우, 더이상 회전하면 안되므로 제거 */
		if (cur.d == 5) {
			if (max < cur.m) max = cur.m;
			continue;
		}

		/* 4개의 방향으로 회전 */
		for (int i = 0; i < 4; i++) {
			board tmp;
			int pre_max = 0;
			/* 2차원 배열 탐색 및 2048 게임 회전 시작 */
			for (int j = 0; j < n; j++) {
				/* 
					0을 제외한 숫자 값을 저장할 vector 변수 정의.
					이동 경로에 0이 있을 경우 무시하고 진행하므로 0은 제외
				*/
				vector<int> fir_mat;
				/* 
					정의한 vector 변수에 해당 줄의 숫자 값만 입력
					입력 조건을 상 하, 좌 우로 나눠 각각에 대한 행, 열로 vector에 입력
					i가 2보다 작은 경우 -> 좌 우
					irk 2보다 크거나 같은 경우 -> 상 하
				*/
				for (int k = 0; k < n; k++) {
					if ((i < 2 ? cur.mat[j][k] : cur.mat[k][j]) != 0)
						fir_mat.push_back((i < 2 ? cur.mat[j][k] : cur.mat[k][j]));
				}

				/* 
					0 -> 우, 1 -> 좌, 2 -> 하, 3 -> 상 방향이므로
					좌, 상 방향을 적용하기 위해 배열을 뒤집음
				*/
				if(i == 1 || i == 3)
					reverse(fir_mat.begin(), fir_mat.end());

				/* 이동한 최종 결과를 임시로 저장할 vector 변수 정의 */
				vector<int> sec_mat;
				/*
					이동 위치에 같은 크기의 값이 존재할 경우 해당 값을 2배로 증가시켜 입력.
					그렇지 않을 경우 그냥 입력.
				*/
				for (int k = 0; k < fir_mat.size(); k++) {
					if (k + 1 < fir_mat.size() && fir_mat[k] == fir_mat[k+1]) {
						sec_mat.push_back(fir_mat[k] << 1);
						k++;
					}
					else
						sec_mat.push_back(fir_mat[k]);
				}
				/* 입력된 값을 제외한 나머지 공간은 0으로 채움 */
				for (int k = sec_mat.size(); k < n; k++)
					sec_mat.push_back(0);

				/* 좌, 상 방향의 경우, 배열에 입력하기 전에 원래대로 뒤집어 줌 */
				if (i == 1 || i == 3)
					reverse(sec_mat.begin(), sec_mat.end());

				/* 
					이동이 완료된 줄의 정보를 임시 판 정보 tmp에 입력.
					해당 줄의 최대값과 현재 최대값을 파악.
				*/
				for (int k = 0; k < sec_mat.size(); k++) {
					(i < 2 ? tmp.mat[j][k] : tmp.mat[k][j]) = sec_mat[k];
					if (pre_max < sec_mat[k]) pre_max = sec_mat[k];
				}
			}
			/* 현재 회전 횟수 증가, 현재 최대값 갱신등을 한 뒤 queue 자료형에 추가함 */
			tmp.d = cur.d + 1;
			tmp.m = cur.m < pre_max ? pre_max : cur.m;
			que.push(tmp);
		}
	}
	/* queue 변수의 모든 값들이 빠질 경우 최대값 출력 (모든 경우를 돌아본 뒤)*/
	cout << max;

	return 0;
}