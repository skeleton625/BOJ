#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) (a < b ? b : a)
#define NMAX 1001		/* ������ �ִ� ���� ���� */
#define TMAX 100000		/* �ð� �ִ� �� ���� */
using namespace std;

typedef long long ll;

int n, k, e;
vector<int> cost, matc;		/* �� ������ ���, ������ ����� ���� ���� �迭 ���� */
vector<ll> costmax;			/* �� �������� ����� �ִ� �� �迭 ���� */
vector<vector<int>> mat;	/* ���� �׷��� ���� */

void bfs() {
	queue<int> que;

	/* ���� ������ �ľ��� ť�� �Է� */
	for (int i = 1; i <= n; i++) {
		if (matc[i] == 0) {
			que.push(i);
			costmax[i] = cost[i];
		}
	}

	/* BFS �˰��� ���� */
	int cur, nex;
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* 
			���� ������ ����� ���� �������� �ľ�
			�������� ���� �ִ� ��� ����
			���� ������ ����� ���� �̿ܿ� �ٸ� ������ �̹� �湮�� ���, �� ������ ť�� �Է�
		*/
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i];
			matc[nex]--;
			costmax[nex] = max(costmax[nex], costmax[cur] + (ll)cost[nex]);
			if (matc[nex] == 0) {
				/* ���� ���� �湮�� ������ ���� ������ ��� �˰��� ���� */
				if (nex == e) return;
				que.push(nex);
			}
		}
	}
}

int main() {
	int x, y, t;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �׽�Ʈ ���̽� ���� */
	cin >> t;
	while (t--) {
		/* ���� �׽�Ʈ�� ���� ����, ���� ���� �Է� */
		cin >> n >> k;
		/* �Էµ� ���� ���� �׷���, ���, �� ������ ���� �迭 ���� */
		mat = vector<vector<int>>(n + 1, vector<int>(0, 0));
		costmax = vector<ll>(n + 1, 0);
		cost = vector<int>(n + 1, 0);
		matc = vector<int>(n + 1, 0);
		/* �� ������ ��� �Է� */
		for (int i = 1; i <= n; i++) cin >> cost[i];
		/* �׷��� ���� �Է�  */
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			mat[x].push_back(y);
			matc[y]++;
		}
		/* ���� ���ľ� �� ���� ��ȣ �Է� */
		cin >> e;

		/* BFS ���� ���� �Լ� ���� */
		bfs();
		/* ���� �������� �ּ� ���(�ð�) ��� */
		cout << costmax[e] << '\n';
	}

	return 0;
}