#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;

typedef long long ll;

int n, m;
vector<vector<ll>> mat;

int main() {
	int a, b;
	ll c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	/* �׷��� �� �ʱ�ȭ */
	mat = vector<vector<ll>>(n+1, vector<ll>(n+1, INF));
	/* �ڱ� �ڽ����� �̵��ϴ� ���� �� �����̴� ���̹Ƿ� 0���� �ʱ�ȭ */
	for (int i = 1; i < n + 1; i++)
		mat[i][i] = 0;

	/* �׷��� ���� �Է� */
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a][b] = min(mat[a][b], c);
	}

	/* �÷��̵� �ͼ� �˰��� ���� */
	for (int i = 1; i <= n; i++)	/* ������ �ݺ��� */
		for (int j = 1; j <= n; j++)	/* ������ �ݺ��� */
			for (int k = 1; k <= n; k++)	/* ������� ������ ������ �� �ݺ��� */
				/* ������� ������ ������ ���� ���� ��ΰ� �� ª������ ���� �ִ��� Ȯ���� ���� */
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	/* ��� ��� */
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (mat[i][j] != INF ? mat[i][j] : 0) << ' ';
		cout << '\n';
	}

	return 0;
}