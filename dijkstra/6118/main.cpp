#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 20001

int n, m;
vector<int> len;
vector<int> mat[NMAX];

void dijkstra() {
	priority_queue<pair<int, int>> que;
	len[1] = 0;
	que.push({ 0, 1 });

	/* ���� �갣 ��ȣ, ���� �갣 ����ġ, ���� �갣 ����ġ ���� ���� */
	int cur, curd, nexd;
	/* ���� �ָ� �ִ� ���� ���� ��ȣ�� �갣, �ִ� �갣 ����ġ, ���� �ָ� �ִ� �갣 ���� ���� ���� */
	int minnum = 0, maxlen = 0, cnt= 0;
	/* ���ͽ�Ʈ�� �˰��� ���� */
	while (!que.empty()) {
		/* ���� �갣 ��ȣ�� ����ġ �Է� */
		cur = que.top().second;
		curd = -que.top().first;
		que.pop();

		/*
			���� �갣�� ���ŵ� ����ġ���� ���� ����ġ�� �� Ŭ ��� �Ѿ 
			-> �ִܰŸ��� ���ؾ� �ϱ� ������ ����ġ�� �þ�� ���� ����
		*/
		if (len[cur] < curd) continue;

		/* ���� �갣�� ����� �ٸ� �갣�鿡 ���ؼ� ����ġ ��� */
		for (auto next : mat[cur]) {
			nexd = curd + 1;
			if (len[next] > nexd) {
				/* ��ü �갣�� �ִ� ����ġ �ľ� */
				if (maxlen < nexd) maxlen = nexd;
				len[next] = nexd;
				que.push({ -nexd, next });
			}
		}
	}

	/* ���� �ָ��ִ� �갣�� �� ���� ���� ��ȣ�� �갣�� ã�� */
	for (int i = 1; i <= n; i++) {
		if (len[i] == maxlen) {
			minnum = i;
			break;
		}
	}

	/* ���� ���� ��ȣ�� �갣���� �갣���� ������ �ľ� */
	for (int i = minnum; i <= n; i++) {
		if (len[i] == maxlen) cnt++;
	}
	/* ���� �갣 �ּ� ��ȣ, ���� �갣 ����ġ, ���� �갣 ���� ��� */
	cout << minnum << ' ' << maxlen << ' ' << cnt;
}

int main() {
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �갣�� ����, �갣���� ���� ���� �Է� */
	cin >> n >> m;
	/* �갣�� �ּ� ����ġ �ʱ�ȭ */
	len = vector<int>(n + 1, NMAX);
	/* �갣���� ���� ���� �Է� */
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	dijkstra();
	return 0;
}