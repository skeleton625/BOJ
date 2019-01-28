#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef pair<int, int> pai;
typedef unsigned long long ll;

pai dots[100000];
map<pai, int> comp_dots;
int n;

/* ���� �� ������ �ּ� �Ÿ��� ���ϴ� �Լ� */
ll getDist(pai d1, pai d2) {
	int x = d2.first - d1.first;
	int y = d2.second - d1.second;
	return (ll)(y * y + x * x);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dots[i].first >> dots[i].second;
	/* ������ x���� ���ؼ� ���� */
	sort(dots, dots + n);

	/* x�� �������� �������� ��� dots 0, dots 1�� ���� ����� ������ ���� */
	comp_dots[{dots[0].second, dots[0].first}] = 1;
	comp_dots[{dots[1].second, dots[1].first}] = 1;

	/* ���� ������ �� �� ������ ���̸� �ּ� ���̷� ���� */
	ll res_min = getDist(dots[0], dots[1]);

	/* ���� �� ��ġ�� ���� ����� �� ��ġ�� �ľ��ϱ� ���� ��ġ ���� */
	int last = 0;
	
	/* dots 0, dots 1�� �̹� ������ �����̴� �� ���� ��° dots ���� Ž�� ���� */
	for (int i = 2; i < n; i++) {
		while (last < i) {
			ll x = dots[last].first - dots[i].first;
			/* x������ �ּ� ���̺��� ���� ���� ���� ���� ��ġ�� �۰ų� ���� ��� ���� -> �ش� ��ġ�� �ּҷ� ���� */
			if (x*x <= res_min) {
				break;
			}
			/* �׷��� ���� ��� �ش� ���� �ʿ䰡 �����Ƿ� �� ��󿡼� ���ܽ�Ŵ */
			else {
				comp_dots.erase({ dots[last].second, dots[last].first });
				/* ���� ���� ���� ��ġ�� �̵���Ŵ */
				last++;
			}
		}

		/* y�� �󿡼� ���� ���̷� �ּ� ������ �ľ��ϱ� ���� ���� �ּ� ������ ���� ���̸� ���� */
		int dist = sqrt(res_min);

		/* map�� ����Ǿ� �ִ� ���� �߿��� �ּ� ���� ���� ���� �ִ� ������ �ľ��ϱ� ���� lower, upper bound�� ���� */
		/* ���⼭ x���� ��� ���� ���밪���� 10000�� ���� �ʱ� ������ x�� ������ ���� */
		auto lo = comp_dots.lower_bound({ dots[i].second - dist, -10000 });
		auto up = comp_dots.upper_bound({ dots[i].second + dist, 10000 });

		/* �ּ� ���� ���� ���� �����ϴ� ����� ���� ������ �Ÿ��� ���, �ּ� ���� �������� */
		for (auto it = lo; it != up; it++)
			res_min = min(res_min, getDist({ it->first.second, it->first.first }, dots[i]));

		/* ���� ���� �ּ� ���̿� �ִ� ���̹Ƿ� map�� �߰����� */
		comp_dots[{dots[i].second, dots[i].first}] = 1;
	}

	cout << res_min;
	return 0;
}
