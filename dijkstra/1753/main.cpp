#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 20001	/* ������ �ִ� ���� ���� */
#define DMAX 200000	/* ���� ���ἱ�� �ִ� ����ġ ���� */

typedef pair<int, int> ver;

int v, e, k;
vector<int> len;
vector<ver> mat[NMAX];

void dijkstra() {
	priority_queue<ver> que;

	/* ���� ���� ���ؼ� ����ġ �ʱ�ȭ */
	len[k] = 0;
	/* ���� �� ��ȣ, ����ġ, ���� �� ��ȣ, ����ġ ���� ���� */
	int curn, curd, nexn, nexd;
	/* �켱���� ť�� ���� ���� �Է� */
	que.push({ 0, k });
	while (!que.empty()) {
		curn = que.top().second;
		curd = -que.top().first;
		que.pop();

		/* ���� ��ġ�l ���� ����ġ�� ���� ����ġ���� Ŭ ��� �Ѿ */
		if (len[curn] < curd) continue;

		/* ���� ������ ����� �����鿡 ���ؼ� ����ġ ��� */
		for (int i = 0; i < mat[curn].size(); i++) {
			nexn = mat[curn][i].second;
			nexd = curd + mat[curn][i].first;
			/*
				���� ���� ���� ���� ������ ����ġ�� �Էµ� ����ġ���� ���� ��� ��������
				������ ���� ����� �ٸ� ������ ����ġ�� �������ֱ� ���� �켱���� ť�� �Է�
			*/
			if (len[nexn] > nexd) {
				len[nexn] = nexd;
				que.push({ -nexd, nexn });
			}
		}
	}
}

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ������ ����, ���� ����, ������ ��ȣ �Է� */
	cin >> v >> e >> k;
	len = vector<int>(v + 1, DMAX);
	/* ������ ���� ���� �Է� */
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ c, b });
	}

	/* ���ͽ�Ʈ�� �˰��� ���� */
	dijkstra();
	/* ��� ����ġ ��� */
	for (int i = 1; i <= v; i++) {
		if (len[i] == DMAX) cout << "INF\n";
		else cout << len[i] << '\n';
	}

	return 0;
}