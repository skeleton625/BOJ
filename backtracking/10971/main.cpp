#include <iostream>
#include <vector>
#define MIN(a, b) ( a < b ? a : b )
#define NMAX 100000001
using namespace std;

int n, start, ans = NMAX;
int mat[10][10];
bool visited[10];

void dfs(int p, int cnt, int cost) {
	// ������ ���ñ��� �湮�� ���
	if (cnt == n) {
		// ������ �湮 ���ÿ��� ���� ���÷� �̵��ϴ� ��ΰ� �����ϴ��� Ȯ��
		if (mat[p][start])
			// ���� ��� ����� ����� ������ �ּ� ����� ����
			ans = MIN(ans, cost + mat[p][start]);
		return;
	}
	// DFS ��Ʈ��ŷ �˰��� ����
	for (int i = 0; i < n; i++) {
		// �湮���� ���� ���ø鼭 ��ΰ� ������ ���
		if (!visited[i] && mat[p][i]) {
			// �湮�� ���÷� ǥ��
			visited[i] = true;
			// ���� ���÷� �̵�
			dfs(i, cnt + 1, cost + mat[p][i]);
			// ��Ʈ��ŷ�� �������� �̵��� ���� �湮 �ʱ�ȭ
			visited[i] = false;
		}
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	// ������ ���� �Է�
	cin >> n;
	// i���ÿ��� j���÷� �̵��ϴ� �̵� ����� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}

	// ��� ���ø� ������� ���� ���÷� ������ DFS �˰����� ����
	for (int i = 0; i < n; i++) {
		start = i;
		visited[start] = true;
		dfs(start, 1, 0);
		visited[start] = false;
	}

	// ��� ���ÿ� ���� ��ȸ ��� ��, �ּ� ����� ���
	cout << ans;

	return 0;
}