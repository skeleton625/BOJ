#include <iostream>
using namespace std;

int p[3][2];

int main() {
	int s;
	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++)
		cin >> p[i][0] >> p[i][1];

	/* p1, p2�� p2, p3 ���� ������ ���� ��ü ������ �ľ� */
	s = (p[1][0] - p[0][0]) * (p[2][1] - p[0][1]) - (p[2][0] - p[0][0]) * (p[1][1] - p[0][1]);
	
	/* ������ ���� �� ������ ���� ���Ͱ� ����Ű�� ������ ��� �������� �ľ��� */
	
	if (s > 0) cout << 1;
	else if (s < 0) cout << -1;
	else cout << 0;

	return 0;
}