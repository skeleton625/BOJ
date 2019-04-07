#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 100001

typedef long long ll;

/* �༺ ��ǥ�� �༺ ��ȣ�� ������ �༺ ���� ���� */
struct ver {
	int x, y, z, idx;
};

/* �༺���� ���� ���� ���� ���� */
struct dist {
	int p1, p2;
	ll len;
	bool operator <(const dist &p) { return len < p.len; }
};

int n;				/* �༺ ���� ���� */
int parent[NMAX];	/* �༺ ������ �θ� ��ȣ �迭 */
ll res_dist;		/* �༺���� ������ �ּ� ���� ���� */
ver info[NMAX];	/* �༺�� ���� �迭 */
vector<dist> d;		/* �༺���� ���� ���� �迭 */

bool compx(ver &a, ver &b) { return a.x < b.x; }
bool compy(ver &a, ver &b) { return a.y < b.y; }
bool compz(ver &a, ver &b) { return a.z < b.z; }

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(dist &n) {
	int n1 = find(n.p1), n2 = find(n.p2);
	if (n1 == n2) return;
	parent[n1] = n2;
	res_dist += n.len;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* �༺ ������ �༺ ���� �迭�� �Է� */
	for (int i = 0; i < n; i++) {
		/*�༺ ��ǥ(x, y, z) �Է� */
		cin >> info[i].x >> info[i].y >> info[i].z;
		/* �༺ ��ȣ �Է�*/
		info[i].idx = i;
		/* �༺ ���� �ʱ�ȭ */
		parent[i] = i;
	}

	/* x���� �������� ���� */
	sort(info, info + n, compx);
	/* x���� ���� �� �༺�� ������ �ּ� ���̵��� �Է� */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].x - info[i - 1].x) });

	/* y���� �������� ���� */
	sort(info, info + n, compy);
	/* y���� ���� �� �༺�� ������ �ּ� ���̵��� �Է� */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].y - info[i - 1].y) });
	
	/* z���� �������� ���� */
	sort(info, info + n, compz);
	/* z���� ���� �� �༺�� ������ �ּ� ���̵��� �Է� */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].z - info[i - 1].z) });

	/* ������ ��ü ������ ���ؼ� ���� ���̸� �������� �������� ���� */
	sort(d.begin(), d.end());
	/* ������ �̷�� �� �༺�� ������ �պ����� */
	for (dist now : d) merge(now);

	cout << res_dist;
	return 0;
}
