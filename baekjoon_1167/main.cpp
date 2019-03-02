#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 1000000000
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, int> ver;
int n, num, v[2], t = 0;
vector<ver> mat[100001];
vector<ll> len;

/* ���� ���� ���ؼ� ���� �� ������ ��ȯ�ϴ� �Լ� -> ���ͽ�Ʈ�� �˰��� ��� */
ver dijkstra(int start) {
	/* �� ���� ���� �ִܰŸ� �ʱ�ȭ */
	len = vector<ll>(n + 1, INF);
	/* ���ͽ�Ʈ�� �˰��� ����� �켱���� ť �ʱ�ȭ */
	priority_queue<ver, vector<ver>, greater<ver>> que;
	ver max_ver = { 0, start };
	que.push({ 0, start });
	len[start] = 0;

	/* ���ͽ�Ʈ�� �˰��� ���� */
	int pn, pd, nn, nd;
	while (!que.empty()) {
		pn = que.top().second;
		pd = que.top().first;
		que.pop();

		if (len[pn] < pd) continue;

		for (int i = 0; i < mat[pn].size(); i++) {
			nn = mat[pn][i].second;
			nd = len[pn] + mat[pn][i].first;
			if (len[nn] > nd) {
				len[nn] = nd;
				que.push({ nd, nn });
				/* ��Ʈ ���κ��� ���� �� ���� �߰��� ��� ����Ÿ� ��� ���� */
				if (max_ver.first < nd) {
					max_ver.first = nd;
					max_ver.second = nn;
				}
			}
		}
	}
	return max_ver;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* Ʈ���� ���� ���� �Է� */
	for(int i = 0; i < n; i++){
		cin >> num; /* ���� ��ȣ �Է�*/
		/* ������ ����� �ٸ� �������� ���� ������ �Է� */
		while (v[0] != -1) { /* �Է¿��� -1�� ���� ������ �Է��� */
			if (t < 2) {
				cin >> v[t];
				t++;
			} else{
				/* -1 �Է��� ������ �ʰ� ����� ������ ������ ���̸� �Է��� ��� �׷����� �߰� */
				mat[num].push_back({ v[1], v[0] });
				t = 0;
			}
		}
		v[0] = 0;
		t = 0;
	}

	/* Ʈ���� ��Ʈ ��忡 ���ؼ� ���ͽ�Ʈ�� �˰��� ���� */
	ver n1 = dijkstra(1);
	/* ��Ʈ ��忡�� ���� �ָ� ������ ������ ���ؼ� ���ͽ�Ʈ�� �˰��� ���� */
	ver n2 = dijkstra(n1.second);

	/* ��Ʈ ��忡�� ���� �ָ� ������ �������� ���� �ָ� ������ �������� �Ÿ��� ��� */
	cout << n2.first;

	return 0;
}