#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) (a < b ? b : a)
#define NMAX 10001		/* ������ �ִ� ���� ���� */
#define INF 100			/* ��� �ִ� �� ���� */
using namespace std;

int n, res;
int matc[NMAX];
int cost[NMAX], costmax[NMAX];
vector<int> mat[NMAX];

void bfs() {
	queue<int> que;
	
	/* 
		���� ������ ���� ����(�������� ���� ������ ���� ���)�� ��� ť�� �߰� 
		����, �׷����� ���� �����ۿ� �������� ���� ���� �ֱ� ������ ���� �ִ� �ð��� ������
	*/
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) {
			que.push(i);
			costmax[i] = cost[i];
			res = max(res, cost[i]);
		}
	}

	int cur, nex;
	/* BFS �˰����� ������ �׷����� ��ȸ */
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* ���� ������ ����Ǿ� �ִ� ������ �ľ� */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			/* ���� �������� ���� ���� �� ���� */
			matc[nex]--;
			/* �������� ���� �ִ� ���(�ð�) ���� */
			costmax[nex] = max(costmax[nex], cost[nex] + costmax[cur]);
			/* 
				���̻� ����� ������ ���� ���(���� �������� ���� ��� ������ �̿��� ���)
				���� ������ ť�� �Է�
			*/
			if (matc[nex] == 0) {
				que.push(nex);
				/* �ִ�� �ɸ��� �ð��� �ľ��ϱ� ���� ������� �ִ� ��� �� */
				res = max(res, costmax[nex]);
			}
		}
	}
}

int main() {
	int a;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �۾� ���� �Է� */
	cin >> n;
	/* �� �۾�(����)�� ���� ���� �Է� */
	for (int i = 1; i <= n; i++) {
		cin >> cost[i] >> matc[i];
		for (int j = 0; j < matc[i]; j++) {
			cin >> a;
			/* i�� �۾��� �����ϱ� ���� a���� ���� �ؾ� �ϹǷ� a���� �������� */
			mat[a].push_back(i);
		}
	}

	bfs();
	cout << res;
	return 0;
}