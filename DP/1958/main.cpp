#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define SMAX 101

int cnt[SMAX][SMAX][SMAX];
string a, b, c;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;
	/* LCS 알고리즘을 3차원으로 구현 */
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			for (int k = 1; k < c.size(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) cnt[i][j][k] = cnt[i - 1][j - 1][k - 1] + 1;
				else cnt[i][j][k] = max({ cnt[i - 1][j][k], cnt[i][j - 1][k], cnt[i][j][k - 1] });
			}
		}
	}

	cout << cnt[a.size() - 1][b.size() - 1][c.size() - 1];
	return 0;
}