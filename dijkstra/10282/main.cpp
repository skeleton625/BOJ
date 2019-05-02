#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define NMAX 10001		/* �ִ� ��ǻ�� �� */
#define DMAX 10000001	/* �ִ� ��ǻ�� �ð� ����ġ */

typedef pair<int, int> ver;

int n, d, c;

/* ��ǻ�� ��Ʈ��ũ ���� �迭 ���� */
vector<vector<ver>> mat;
/* ��ǻ�� �ð� ����ġ ��� ���� */
vector<int> vals;

void calculate_time() {
	priority_queue<ver> que;
	/* ������ ��ǻ�� ��, ���� �����Ǵµ� �ɸ��� �ð� */
	int cnt = 0, all_time = 0;
	/* ���� ��ǻ�� ��ȣ, ����ġ / ���� ��ǻ�� ��ȣ, ����ġ */
	int cur, curd, nex, nexd;

	vals[c] = 0;
	/* ���̷��� ���� ��ǻ�� ��ȣ, �ð� ����ġ �Է� */
	que.push({ 0, c });
	/* ���ͽ�Ʈ�� �˰��� ���� */
	while (!que.empty()) {
		cur = que.top().second;
		/* �ּ� ����ġ�� ���� �̱� ���� ������ ���� */
		curd = -que.top().first;
		que.pop();

		/* ���� ���� ��ǻ���� ���ŵ� ����ġ�� ���� ����ġ���� ���� ��� �Ѿ */
		if (vals[cur] < curd) continue;

		/* ���� ��ǻ�Ϳ� ����� ��ǻ�͵��� ����ġ�� ��� */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i].second;
			nexd = curd + mat[cur][i].first;

			/* ���� ��ǻ���� ����ġ�� ���� ���� ����ġ�� ���� ����ġ���� ���� ��� ���� */
			if (vals[nex] > nexd) {
				vals[nex] = nexd;
				/* �ּ� ����ġ�� ���� �̱� ���� ������ ���� */
				que.push({ -nexd, nex });
			}
		}
	}

	/* ������ ��ǻ�� ���� �� �ɸ� �ð� �ľ� */
	for (int i = 1; i <= n; i++) {
		/* ����ġ�� �ִ밪���� ���ŵǾ��� ��� */
		if (vals[i] != DMAX) {
			/* ������ ��ǻ���̹Ƿ� ���� �߰� */
			++cnt;
			/* 
				���� ������ ��ǻ�� ��, ���������� ������ ��ǻ���� �ð��� ���� ��� ������ 
				����ġ�� ���� ū ��ǻ���� �ð��� �Է�
			*/
			if (all_time < vals[i]) all_time = vals[i];
		}
	}

	cout << cnt << ' ' << all_time << '\n';
}

int main() {
	int t, a, b, v;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �׽�Ʈ ���̽� �� �Է� */
	cin >> t;
	while (t--) {
		/* ��ǻ�� ��, ��ǻ�� ��Ʈ��ũ �� ��, ù ��° ���̷��� ��ǻ�� ��ȣ �Է� */
		cin >> n >> d >> c;
		/* �� ��ǻ���� �ð� ����ġ, ��Ʈ��ũ ���� �ʱ�ȭ */
		vals = vector<int>(n + 1, DMAX);
		mat = vector<vector<ver>>(n + 1, vector<ver>(0, { 0, 0 }));
		/* ��ǻ�� ��Ʈ��ũ ���� �Է� */
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> v;
			mat[b].push_back({ v, a });
		}

		calculate_time();
	}

	return 0;
}