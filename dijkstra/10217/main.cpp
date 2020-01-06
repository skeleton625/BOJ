#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 100000
using namespace std;

typedef pair<pair<int, int>, int> pai;

struct ver {
	int e, co, di;
};
/* ���� ��, �� �������, Ƽ�� ���� ��*/
int n, m, k;
/* �� �װ��� ��뿡 ���� �ִܰŸ� �迭 */
vector<vector<int>> dist;

int dijkstra(vector<ver> *mat) {
	/* ������ ��� ������ ������������ �ִܰŸ� ���� ���� */
	int result = INF;
	/* ����ü pai�� ���� �켱���� ť �ڷ��� ���� */
	priority_queue<pai, vector<pai>, greater<pai>> que;
	/* ������� ��뿡 ���� �ִܰŸ� �ʱ�ȭ -> ����� 1 ( ���, �Ÿ��� 0 ) */
	dist[1][0] = 0;
	/* ������� �ִܰŸ�, �����, ��� -> �ִ� �Ÿ��� �ľ��ϱ� ���� �ִܰŸ��� ���� */
	que.push({ {0, 1}, 0 });

	/* ���ͽ�Ʈ�� �˰��� ���� */
	int pn, pc, pd;
	while (!que.empty()) {
		/* ���� ������� ��ǥ, �ִܰŸ�, ��� ���� */
		pn = que.top().first.second;
		pd = que.top().first.first;
		pc = que.top().second;
		que.pop();

		/* ������� ��뿡 ���� �ִܰŸ��� ���ŵ� ��� ���� ������ �Ѿ */
		if (dist[pn][pc] < pd) continue;

		int nn, nc, nd;
		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].e; /* ������ �װ� ��ǥ */
			nc = pc + mat[pn][i].co; /* ������� ���� �������� ��� */
			/* ���� ��������� ���������� ����� ������ ����� �Ѵ��� Ȯ�� */
			if (nc <= m) {
				nd = pd + mat[pn][i].di; /* ������� ���� ������ �ִܰŸ� */
				/* ���� ������� ��뿡 ���� �ִܰŸ��� ���ŵ� ������ ���� ��� �������ְ� �켱���� ť�� �Է� */
				if (dist[nn][nc] > nd) {
					dist[nn][nc] = nd;
					/* ���� ��ġ�� �������� ���, ������������ �ִܰŸ� ����(���纸�� ���ŵ� �Ÿ��� �� ª�� ���)*/
					if (nn == n && result > nd) result = nd;
					que.push({ {nd, nn}, nc });
				}
			}
		}
	}
	return result;
}

int main() {
	/* �����, ������, ���, �ð�, �׽�Ʈ ���̽� ��*/
	int u, v, c, d, t;

	cin >> t;
	while (t--) {
		vector<ver> mat[101];
		cin >> n >> m >> k;
		/* ������� �������� ���� ��� ������ �Է� */
		for (int i = 0; i < k; i++) {
			cin >> u >> v >> c >> d;
			mat[u].push_back({ v, c, d });
		}

		/* ��뿡 ���� �ִ� ��� �ʱ�ȭ */
		dist = vector<vector<int>>(n + 1, vector<int>(10001, INF));
		/* ��뿡 ���� ������������ �ִ� �Ÿ� ��� */
		int result = dijkstra(mat);

		/* 
			������ ���� ������ ������� �� �� ���� ��� �ִ� �Ÿ��� ���
			�׷��� ���� ��� "Poor KCM" ���
		*/
		if (result == INF) cout << "Poor KCM" << '\n';
		else cout << result << '\n';
	}
	return 0;
}