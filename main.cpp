#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define DMAX 500000
using namespace std;

typedef pair<int, int> ver;

int n, m, s, e;
vector<int> line;
vector<vector<bool>> visit;

/* ���ͽ�Ʈ�� �Լ� */
void dijkstra(vector<ver>* mat) {
	/* �������� ���� �ִܰŸ� �迭 �ʱ�ȭ */
	line = vector<int>(n, DMAX);
	/* ���ͽ�Ʈ�� �����ϱ� ���� ���� �ʱ�ȭ */
	priority_queue<ver, vector<ver>, greater<ver>> que;
	line[s] = 0;
	que.push({ 0, s });

	int pn, pd;
	while (!que.empty()) {
		pn = que.top().second, pd = que.top().first;
		que.pop();

		/* ť�� �Է��� ���� �ִܰŸ��� ����Ǿ��� ��� ���� ���̽��� ���� */
		if (line[pn] < pd)
			continue;

		int nn, nd;
		/* ����Ǿ� �ִ� �����ε鿡 ���� ������ Ȯ�� */
		for (int i = 0; i < mat[pn].size(); i++) {

			/* ���� ����� �������� ��ȣ�� �ִ� �Ÿ��� ��� */
			nn = mat[pn][i].second;
			nd = pd + mat[pn][i].first;

			/* ���� �ִ� ��κ��� ���� �ִ� ��ΰ� �� ª�� ��� ���� */
			/* �ִ� ��� ���� �� ���ŵ� �����̸� �ǳ� ��(ó���� �������) */
			if (line[nn] > nd && !visit[pn][nn]) {
				line[nn] = nd;
				/* ���ŵ� �ִ� ��ο� ���ؼ� ����� �ٸ� �������� �ִ� ��θ� �������� */
				que.push({ nd, nn });
			}
		}
	}
}

/* ���� �ִܰŸ� ��θ� �����ϴ� �Լ�(BFS) */
void remove_line(vector<ver>* mat) {
	queue<int> que;
	que.push(e);

	int pre;
	/* BFS �˰��� ���� */
	while (!que.empty()) {
		pre = que.front(); que.pop();

		/* ���� ���� ��ġ�� �������� ��� ���� */
		if (pre == s) continue;

		int nex;
		/* ���������� ������� �̵��ϸ� �ִܰŸ� ��ο� �ִ� ���θ� ã�� */
		for (int i = 0; i < mat[pre].size(); i++) {
			nex = mat[pre][i].second;
			if (line[pre] == line[nex] + mat[pre][i].first) {
				/* ���ͽ�Ʈ�󿡼� �ִ� ��θ� ã�� ���� �ݴ�� �����ϹǷ� ����� �Է� */
				visit[nex][pre] = true;
				que.push(nex);
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �����ο� ���� ���� �Է� */
	cin >> n >> m;
	while (n != 0 && m != 0) {
		/* ��������� ������������ �� �迭 ���� */
		vector<ver> go[500];
		/* ���������� ����������� �� �迭 ���� */
		vector<ver> back[500];
		/* ������� ������ ��ġ �Է� */
		cin >> s >> e;
		/* ���ο� ���� ���� �Է� */
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			/* ������ ���ؿ� ���� �� �迭 ���� */
			go[a].push_back({ c, b });
			back[b].push_back({ c, a });
		}

		/* �ִܰŸ� �湮 �迭 �ʱ�ȭ */
		visit = vector<vector<bool>>(n, vector<bool>(n, false));

		/* ���� �ִܰŸ��� ã�� �ִ� �Ÿ� ��ο� �ִ� ���ε��� ������ */
		dijkstra(go);
		remove_line(back);
		/* �ִܰŸ� ��ο� �ִ� ���θ� �����ϰ� �ٽ� ���ͽ�Ʈ�� ���� */
		dijkstra(go);

		/* ���� �ִ� ��θ� ���(��ΰ� ������ -1 ���) */
		if (line[e] == DMAX) cout << -1 << '\n';
		else cout << line[e] << '\n';

		/* ���� �׽�Ʈ ���̽��� ���� */
		cin >> n >> m;
	}
	return 0;
}
