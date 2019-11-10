#include <iostream>
#include <vector>
#define LMAX 10001
using namespace std;

typedef pair<int, int> ver;

int n, pos = 1;
ver mat[10001];
/* ������� ���̿� ���� �ּҰ�, �ִ밪, ����� ��� �� */
vector<int> arrmin, arrmax, real;

/* ���� ��ȸ dfs �˰��� �Լ� */
void dfs(int dep, int num) {
	
	/* ���� ��ġ���� Ʈ���� ���� ��带 dfs �˰������� ��ȸ�� */
	if (mat[num].first > 0)
		dfs(dep + 1, mat[num].first);

	/* ���� �湮�� ��尡 ���� ���̿��� ���� ���� ��ġ�� ��� ���� */
	if (arrmin[dep] > pos)
		arrmin[dep] = pos;
	/* ���� �湮�� ��尡 ���� ���̿��� ���� ū ��ġ�� ��� ���� */
	if (arrmax[num] < pos)
		arrmax[dep] = pos;

	/* ��ġ ���� -> ���ʿ��� ���������� �̵� */
	pos++;
	
	/* ���� ��ġ���� Ʈ���� ������ ��带 dfs �˰������� ��ȸ�� */
	if (mat[num].second > 0)
		dfs(dep + 1, mat[num].second);
}

int main() {
	int p, c1, c2;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ��� ���� Ʈ���� ���� �Է� */
	cin >> n;
	/* ��� ���� ���� �迭 �ʱ�ȭ */
	arrmin = vector<int>(n + 1, 20000);
	arrmax = vector<int>(n + 1, 0);
	/* Ʈ���� ��Ʈ ��带 �ľ��ϱ� ���� �迭 */
	real = vector<int>(n + 1, 0);
	/* Ʈ���� ���� ���� �Է�*/
	for (int i = 0; i < n; i++) {
		cin >> p >> c1 >> c2;
		mat[p].first = c1;
		mat[p].second = c2;
		
		/* ��带 �Է��� Ƚ�� ���� -> �� �� �ԷµǾ��� ��� �� ���� ��Ʈ ��� */
		real[p]++;
		if (c1 != -1) real[c1]++;
		if (c2 != -1) real[c2]++;
	}

	int root;
	/* ��Ʈ ��带 �ľ� */
	for (int i = 1; i <= n; i++) {
		if (real[i] == 1) {
			root = i;
			break;
		}
	}

	/* dfs �˰����� ���� */
	dfs(1, root);

	/* ���� ���̿� �����ϴ� ��尣�� �Ÿ��� ����, �ִ� ���� �ľ��� */
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