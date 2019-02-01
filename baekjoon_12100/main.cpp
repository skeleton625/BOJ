#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct board {
	/* ���� �� ����, ȸ�� ��(����), �ִ� ��*/
	int mat[20][20];
	int d;
	int m;
};

/* �� �Է� �迭, ���� ũ�� ����*/
int in[20][20];
int n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	board first;	/* ó�� �� ��ȣ�� �Է��� board ���� */
	int max = 0;

	/* �� ũ�� �Է�*/
	cin >> n;
	/* �� ���� �Է� */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> first.mat[i][j];
	}
	first.d = 0;
	first.m = 0;

	/* BFS�� ������ queue ���� ����, �Էµ� �� ������ �Է� */
	queue<board> que;
	que.push(first);

	/* BFS ���� */
	while (!que.empty()) {
		board cur = que.front(); que.pop();

		/* ȸ�� Ƚ��(����)�� 5�� �� ���, ���̻� ȸ���ϸ� �ȵǹǷ� ���� */
		if (cur.d == 5) {
			if (max < cur.m) max = cur.m;
			continue;
		}

		/* 4���� �������� ȸ�� */
		for (int i = 0; i < 4; i++) {
			board tmp;
			int pre_max = 0;
			/* 2���� �迭 Ž�� �� 2048 ���� ȸ�� ���� */
			for (int j = 0; j < n; j++) {
				/* 
					0�� ������ ���� ���� ������ vector ���� ����.
					�̵� ��ο� 0�� ���� ��� �����ϰ� �����ϹǷ� 0�� ����
				*/
				vector<int> fir_mat;
				/* 
					������ vector ������ �ش� ���� ���� ���� �Է�
					�Է� ������ �� ��, �� ��� ���� ������ ���� ��, ���� vector�� �Է�
					i�� 2���� ���� ��� -> �� ��
					irk 2���� ũ�ų� ���� ��� -> �� ��
				*/
				for (int k = 0; k < n; k++) {
					if ((i < 2 ? cur.mat[j][k] : cur.mat[k][j]) != 0)
						fir_mat.push_back((i < 2 ? cur.mat[j][k] : cur.mat[k][j]));
				}

				/* 
					0 -> ��, 1 -> ��, 2 -> ��, 3 -> �� �����̹Ƿ�
					��, �� ������ �����ϱ� ���� �迭�� ������
				*/
				if(i == 1 || i == 3)
					reverse(fir_mat.begin(), fir_mat.end());

				/* �̵��� ���� ����� �ӽ÷� ������ vector ���� ���� */
				vector<int> sec_mat;
				/*
					�̵� ��ġ�� ���� ũ���� ���� ������ ��� �ش� ���� 2��� �������� �Է�.
					�׷��� ���� ��� �׳� �Է�.
				*/
				for (int k = 0; k < fir_mat.size(); k++) {
					if (k + 1 < fir_mat.size() && fir_mat[k] == fir_mat[k+1]) {
						sec_mat.push_back(fir_mat[k] << 1);
						k++;
					}
					else
						sec_mat.push_back(fir_mat[k]);
				}
				/* �Էµ� ���� ������ ������ ������ 0���� ä�� */
				for (int k = sec_mat.size(); k < n; k++)
					sec_mat.push_back(0);

				/* ��, �� ������ ���, �迭�� �Է��ϱ� ���� ������� ������ �� */
				if (i == 1 || i == 3)
					reverse(sec_mat.begin(), sec_mat.end());

				/* 
					�̵��� �Ϸ�� ���� ������ �ӽ� �� ���� tmp�� �Է�.
					�ش� ���� �ִ밪�� ���� �ִ밪�� �ľ�.
				*/
				for (int k = 0; k < sec_mat.size(); k++) {
					(i < 2 ? tmp.mat[j][k] : tmp.mat[k][j]) = sec_mat[k];
					if (pre_max < sec_mat[k]) pre_max = sec_mat[k];
				}
			}
			/* ���� ȸ�� Ƚ�� ����, ���� �ִ밪 ���ŵ��� �� �� queue �ڷ����� �߰��� */
			tmp.d = cur.d + 1;
			tmp.m = cur.m < pre_max ? pre_max : cur.m;
			que.push(tmp);
		}
	}
	/* queue ������ ��� ������ ���� ��� �ִ밪 ��� (��� ��츦 ���ƺ� ��)*/
	cout << max;

	return 0;
}