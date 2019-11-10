#include <iostream>
#include <vector>
#define LMAX 10001
using namespace std;

typedef pair<int, int> ver;

int n, pos = 1;
ver mat[10001];
/* 순서대로 깊이에 따른 최소값, 최대값, 연결된 노드 수 */
vector<int> arrmin, arrmax, real;

/* 전위 순회 dfs 알고리즘 함수 */
void dfs(int dep, int num) {
	
	/* 현재 위치에서 트리의 왼쪽 노드를 dfs 알고리즘으로 순회함 */
	if (mat[num].first > 0)
		dfs(dep + 1, mat[num].first);

	/* 현재 방문한 노드가 현재 깊이에서 가장 작은 위치일 경우 갱신 */
	if (arrmin[dep] > pos)
		arrmin[dep] = pos;
	/* 현재 방문한 노드가 현재 깊이에서 가장 큰 위치일 경우 갱신 */
	if (arrmax[num] < pos)
		arrmax[dep] = pos;

	/* 위치 증가 -> 왼쪽에서 오른쪽으로 이동 */
	pos++;
	
	/* 현재 위치에서 트리의 오른쪽 노드를 dfs 알고리즘으로 순회함 */
	if (mat[num].second > 0)
		dfs(dep + 1, mat[num].second);
}

int main() {
	int p, c1, c2;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 노드 수와 트리의 정보 입력 */
	cin >> n;
	/* 노드 수에 대한 배열 초기화 */
	arrmin = vector<int>(n + 1, 20000);
	arrmax = vector<int>(n + 1, 0);
	/* 트리의 루트 노드를 파악하기 위한 배열 */
	real = vector<int>(n + 1, 0);
	/* 트리에 대한 정보 입력*/
	for (int i = 0; i < n; i++) {
		cin >> p >> c1 >> c2;
		mat[p].first = c1;
		mat[p].second = c2;
		
		/* 노드를 입력한 횟수 측정 -> 한 번 입력되었을 경우 그 노드느 루트 노드 */
		real[p]++;
		if (c1 != -1) real[c1]++;
		if (c2 != -1) real[c2]++;
	}

	int root;
	/* 루트 노드를 파악 */
	for (int i = 1; i <= n; i++) {
		if (real[i] == 1) {
			root = i;
			break;
		}
	}

	/* dfs 알고리즘을 실행 */
	dfs(1, root);

	/* 같은 깊이에 존재하는 노드간의 거리를 측정, 최대 값을 파악함 */
	int pre_len, max_len = 0, max_dep = 0;
	for (int i = 1; i <= n; i++) {
		pre_len = arrmax[i] - arrmin[i]+1;
		if (max_len < pre_len) {
			max_len = pre_len;
			max_dep = i;
		}
	}

	cout << max_dep << ' ' << max_len;
	return 0;
}