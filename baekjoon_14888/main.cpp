#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cal_max=-1000000000, cal_min=1000000000;
int num[11], calc[4], tmp[4];
vector<int> expr;

int calculate() {
	int n = num[0], ln = 0;
	for (int i = 0; i < expr.size(); i++) {
		switch (expr[i]) {
		case 0:
			n = n + num[ln + 1];
			break;
		case 1:
			n = n - num[ln + 1];
			break;
		case 2:
			n = n * num[ln + 1];
			break;
		case 3:
			n = n / num[ln + 1];
			break;
		}
		ln++;
	}
	return n;
}

void calc_expr(int len) {

	if (len == n-1) {
		int re = calculate();
		cal_max = max(cal_max, re);
		cal_min = min(cal_min, re);
	}

	for (int i = 0; i < 4; i++) {
		if (calc[i] > tmp[i]) {
			tmp[i]++;
			expr.push_back(i);
			calc_expr(len + 1);
			expr.pop_back();
			tmp[i]--;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> calc[i];

	calc_expr(0);
	cout << cal_max << '\n' << cal_min;
	return 0;
}