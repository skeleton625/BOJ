#include "iostream"
using namespace std;

int num[3];
int re[2];
char calc[2];

int calculate(int x, int y, char c) {
	switch (c) {
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
	}
}

int main() {
	cin.tie(0);
	cin >> num[0] >> calc[0] >> num[1] >> calc[1] >> num[2];
	re[0] = calculate(calculate(num[0], num[1], calc[0]), num[2], calc[1]);
	re[1] = calculate(num[0], calculate(num[1], num[2], calc[1]), calc[0]);
	if (re[0] > re[1]) cout << re[1] << ' ' << re[0];
	else cout << re[0] << ' ' << re[1];
	return 0;
}