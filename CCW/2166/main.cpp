#include <iostream>
#include <cmath>
using namespace std;

double x[10001];
double y[10001];

int main() {
	int n;
	double re = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	x[n] = x[0];
	y[n] = y[0];

	for (int i = 0; i < n; i++)
		re += ((x[i] + x[i + 1]) * (y[i] - y[i + 1]) / 2);

	cout.setf(ios::fixed);
	cout.precision(1);
	cout << fabs(re);
	return 0;
}