#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> pai;
typedef unsigned long long ll;
int n;

/* �� ������ �ּ� ������ ������ ��ȯ�ϴ� �Լ� */
ll getDist(pai d1, pai d2) {
	int x = d2.first - d1.first;
	int y = d2.second - d1.second;
	return (ll)(x * x + y * y);
}

/* �� ���� ������ �ּ� ���̸� ���� ���� �ּ� ������ ������ ��ȯ�ϴ� �Լ� */
ll comp_dots(vector<pai>::iterator dots, int n) {
	/* ���� �ȿ� �� ���� ���� ���� ��� �ּ� ���̸� ����� ��ȯ */
	if (n == 2)
		return getDist(dots[0], dots[1]);
	/* ���� �ȿ� �� ���� ���� ���� ��� �ּ� ���̸� ����� ��ȯ */
	if (n == 3)
		return min({ getDist(dots[0], dots[1]), getDist(dots[1], dots[2]), getDist(dots[2],dots[0]) });

	/* x���� �߰� �������� ������ ���, �߰��� �������� ����, ���Ŀ� �ִ� ���� �߰� x ���� ���� */
	int line = (dots[n/2-1].first + dots[n/2].first) / 2;
	/* �߰� �������� ���� ��, ������ ���� ������ �ּ� ���̸� ���� ���� d�� ���� */
	ll d = min(comp_dots(dots, n/2), comp_dots(dots+n/2,n-n/2));

	/* x������ ���ĵ� �� �� ������ ������ �ִ� ������ y������ ���Ľ�ų vector ���� */
	vector<pai> mid;

	/* 
		�߰� ������ �������� ������ �Ÿ��� �ּ� ���� d���� ���� ��� vector ���� mid�� �Է� 
		�Է��� �� x, y ���� ���� vector ������ �ݴ�� �Է�( x, y -> y, x )
	*/
	for (int i = 0; i < n; i++) {
		int t = line - dots[i].first;
		if ((ll)(t*t) < d)
			mid.push_back({dots[i].second, dots[i].first});
	}
	/* vector ���� mid�� �Էµ� ������ y���� �������� ������ */
	sort(mid.begin(), mid.end());
	
	int mid_sz = mid.size();
	/* i -> �� 1, j -> �� 2 */
	/* 
		vector ���� mid�� �Էµ� ������ ���̸� ���� 
		�ش� ������ �Ÿ��� �ּ� ���̸� ����� �ʴ� ���� �������� ������
		��, �ش� ������ �߰� ������ �ּ� ���̸� �� ���� �� ���� ���� ���̰� �ִ��� Ȯ���ϱ� ����
	*/
	for (int i = 0; i < mid_sz - 1; i++)
		for (int j = i + 1; j < mid_sz && mid[j].first - mid[i].first < d; j++)
			d = min(d, getDist(mid[i], mid[j]));
	
	return d;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	/* ���� �Է¹޾� �� vector ���� */
	vector<pai> dots(n);
	for (int i = 0; i < n; i++)
		cin >> dots[i].first >> dots[i].second;

	/* �Է¹��� ������ x�� �������� ���� */
	sort(dots.begin(), dots.end());

	cout << comp_dots(dots.begin(), n);
	return 0;
}
