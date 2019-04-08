#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NMAX 100001

typedef long long ll;

/* 행성 좌표와 행성 번호를 포함한 행성 변수 정의 */
struct ver {
	int x, y, z, idx;
};

/* 행성간의 간선 정보 변수 정의 */
struct dist {
	int p1, p2;
	ll len;
	bool operator <(const dist &p) { return len < p.len; }
};

int n;				/* 행성 개수 변수 */
int parent[NMAX];	/* 행성 집합의 부모 번호 배열 */
ll res_dist;		/* 행성들을 연결한 최소 길이 변수 */
ver info[NMAX];	/* 행성의 정보 배열 */
vector<dist> d;		/* 행성들의 간선 정보 배열 */

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
	/* 행성 정보를 행성 정보 배열에 입력 */
	for (int i = 0; i < n; i++) {
		/*행성 좌표(x, y, z) 입력 */
		cin >> info[i].x >> info[i].y >> info[i].z;
		/* 행성 번호 입력*/
		info[i].idx = i;
		/* 행성 집합 초기화 */
		parent[i] = i;
	}

	/* x값을 기준으로 정렬 */
	sort(info, info + n, compx);
	/* x값에 대해 두 행성간 가능한 최소 길이들을 입력 */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].x - info[i - 1].x) });

	/* y값을 기준으로 정렬 */
	sort(info, info + n, compy);
	/* y값에 대해 두 행성간 가능한 최소 길이들을 입력 */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].y - info[i - 1].y) });
	
	/* z값을 기준으로 정렬 */
	sort(info, info + n, compz);
	/* z값에 대해 두 행성간 가능한 최소 길이들을 입력 */
	for (int i = 1; i < n; i++)
		d.push_back({ info[i].idx, info[i - 1].idx, abs(info[i].z - info[i - 1].z) });

	/* 구해준 전체 간선에 대해서 간선 길이를 기준으로 내림차순 정렬 */
	sort(d.begin(), d.end());
	/* 간선을 이루는 두 행성의 집합을 합병해줌 */
	for (dist now : d) merge(now);

	cout << res_dist;
	return 0;
}
