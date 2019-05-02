#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define NMAX 10001		/* 최대 컴퓨터 수 */
#define DMAX 10000001	/* 최대 컴퓨터 시간 가중치 */

typedef pair<int, int> ver;

int n, d, c;

/* 컴퓨터 네트워크 정보 배열 선언 */
vector<vector<ver>> mat;
/* 컴퓨터 시간 가중치 뱅려 선언 */
vector<int> vals;

void calculate_time() {
	priority_queue<ver> que;
	/* 감염된 컴퓨터 수, 전부 감염되는데 걸리는 시간 */
	int cnt = 0, all_time = 0;
	/* 현재 컴퓨터 번호, 가중치 / 다음 컴퓨터 번호, 가중치 */
	int cur, curd, nex, nexd;

	vals[c] = 0;
	/* 바이러스 시작 컴퓨터 번호, 시간 가중치 입력 */
	que.push({ 0, c });
	/* 다익스트라 알고리즘 실행 */
	while (!que.empty()) {
		cur = que.top().second;
		/* 최소 가중치를 먼저 뽑기 위해 음수로 정의 */
		curd = -que.top().first;
		que.pop();

		/* 만일 현재 컴퓨터의 갱신된 가중치가 현재 가중치보다 작을 경우 넘어감 */
		if (vals[cur] < curd) continue;

		/* 현재 컴퓨터와 연결된 컴퓨터들의 가중치를 계산 */
		for (int i = 0; i < mat[cur].size(); i++) {
			nex = mat[cur][i].second;
			nexd = curd + mat[cur][i].first;

			/* 현재 컴퓨터의 가중치로 인해 계산된 가중치가 기존 가중치보다 작을 경우 갱신 */
			if (vals[nex] > nexd) {
				vals[nex] = nexd;
				/* 최소 가중치를 먼저 뽑기 위해 음수로 정의 */
				que.push({ -nexd, nex });
			}
		}
	}

	/* 감염된 컴퓨터 수와 총 걸린 시간 파악 */
	for (int i = 1; i <= n; i++) {
		/* 가중치가 최대값에서 갱신되었을 경우 */
		if (vals[i] != DMAX) {
			/* 감염된 컴퓨터이므로 개수 추가 */
			++cnt;
			/* 
				또한 감염된 컴퓨터 중, 마지막으로 감염된 컴퓨터의 시간이 가장 길기 때문에 
				가중치가 가장 큰 컴퓨터의 시간을 입력
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

	/* 테스트 케이스 수 입력 */
	cin >> t;
	while (t--) {
		/* 컴퓨터 수, 컴퓨터 네트워크 선 수, 첫 번째 바이러스 컴퓨터 번호 입력 */
		cin >> n >> d >> c;
		/* 각 컴퓨터의 시간 가중치, 네트워크 정보 초기화 */
		vals = vector<int>(n + 1, DMAX);
		mat = vector<vector<ver>>(n + 1, vector<ver>(0, { 0, 0 }));
		/* 컴퓨터 네트워크 정보 입력 */
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> v;
			mat[b].push_back({ v, a });
		}

		calculate_time();
	}

	return 0;
}