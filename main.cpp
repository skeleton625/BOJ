#include <iostream>
#include <vector>
#define INF 5000000
using namespace std;

int n, m;
vector<pair<int, int>> mat[501];
vector<int> dist;

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* �׷����� ���� ����(�� ��, ���� ��, ���� ����) �Է� */
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b, c });
	}

	/* �ִܰŸ� �ʱ�ȭ */
	dist = vector<int>(n + 1, INF);
	dist[1] = 0;

	int nn, nd;
	/* �������� �˰��� ����, ��� ������ �� �� �� ��ȸ�� -> ����Ŭ�� �����ϱ� ���� ��� */
	for (int i = 1; i <= n; i++) {
		/* ���� �ִܰŸ��� ���ŵ� ������ ���� ������ �ֱ����� ��� ���� ��ȸ */
		for (int j = 1; j <= n; j++) {
			/* �� �� ����Ŭ�� ����� ��찡 �ִ��� �ľ��ϱ� ���� �ش� ���� �������� Ȯ�� */
			for (int k = 0; k < mat[j].size(); k++) {
				nn = mat[j][k].first, nd = dist[j] + mat[j][k].second;
				/* 
					���� ���� �ִܰŸ��� ���� �ִܰŸ����� ª�� ��� ��������
					���� ���ŵ��� ���� ���� ��� ���� -> �߸��� �ִܰŸ��� ���ŵ� �� �ֱ� ����
				*/
				if (dist[j] != INF && dist[nn] > nd) {
					dist[nn] = nd;
					/*���� ��� ���� ��ȸ�ϰ� ���ŵǴ� ��찡 ����� ����Ŭ�� �ִٴ� ����̹Ƿ� -1 ��� */
					if (i == n) {
						cout << -1 << '\n';
						return 0;
					}
				}
			}
		}
	}

	/* 
		�������� ������ ��� ���� �ִܰŸ��� ���
		�ִ� �Ÿ��� ���� ��� -1�� �����
	*/
	for (int i = 2; i <= n; i++)
		cout << (dist[i] != INF ? dist[i] : -1) << '\n';

	return 0;
}