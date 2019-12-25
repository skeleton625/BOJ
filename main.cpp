#include <iostream>
#include <vector>
#include <queue>
#define INF -(1LL << 60)
using namespace std;

typedef long long ll;

int n, m, s, e;
/* �׷����� ������ ������ ��� ���� */
vector <pair<int, int>> mat[100];
/* ����Ŭ�� ���� ��� int ������ �Ѿ �� �����Ƿ� long long���� ���� */
vector<ll> dist, cost;

/* ����Ŭ�� ������ ���� ����Ǿ� �ִ��� Ȯ���ϱ� ���� BFS �Լ� */
bool bfs(queue<int> que) {
	int cur, nex;
	/* BFS �湮 �ʱ�ȭ */
	vector<bool> visit(n+1, false);

	/* BFS �˰��� ���� */
	while (!que.empty()) {
		cur = que.front(); que.pop();

		if (visit[cur]) continue;
		visit[cur] = true;

		if (cur == e) break;

		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i].first;
			if (!visit[nex]) que.push(nex);
		}
	}
	return visit[e];
}

/* �������� �Լ� */
void belman_ford() {
	/* �� ���ÿ� ���� �ּ� ��� �ʱ�ȭ */
	dist = vector<ll>(n+1, INF);
	/* ���� �������� �� �� �ִ� ������ �ʱ�ȭ */
	dist[s] = cost[s];
	/* BFS �˰����� ���� ť ���� */
	queue<int> cycle;

	/* ���� ���� int ������ �Ѿ �� �����Ƿ� long long���� ���� */
	ll nd;
	int cnt = 0, nn;
	bool update = true; /* �ּ� ����� �����ϴ��� Ȯ���ϱ� ���� ���� */
	/* �������� �˰��� ���� */
	while (update&&cnt < n) {
		update = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				/* ���� ������ �ּ� ����� ���ŵ��� ������ ��� ���� */
				if (dist[i] != INF) {
					/* ���� ������ ��ġ�� ���� ���÷� �̵��� �� �� �� �ִ� �ݾ� ��� */
					nn = mat[i][j].first, nd = dist[i] + cost[nn] - mat[i][j].second;
					/* �� �� �ִ� �ݾ��� ���� �ݾ׺��� Ŭ ��� ���� */
					if (dist[nn] < nd) {
						dist[nn] = nd;
						update = true;
						/* ���� ����Ŭ ���� �����ϴ� ������ ��� ť�� �Է� */
						if (cnt == n - 1) cycle.push(i);
					}
				}
			}
		}
		cnt++;
	}

	if (dist[e] == INF)
		cout << "gg";
	else if (bfs(cycle))
		cout << "Gee";
	else
		cout << dist[e];

}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �׷����� ���� ���� ����, ��� �Է�*/
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
	}

	/* ���ø� �湮�� ������ ���� �� �ִ� �ݾ� �Է� */
	cost = vector<ll>(n+1, 0);
	for (int i = 0; i < n; i++)
		cin >> cost[i];

	belman_ford();
	return 0;
}