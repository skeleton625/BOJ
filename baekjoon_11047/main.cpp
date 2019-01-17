#include "iostream"
using namespace std;

int *coin;
int n, k, tmp, c;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	coin = new int[n];
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	while (k) {
		if (k < coin[n-1]) n--;
		else {
			k -= coin[n - 1];
			c++;
		}
	}
	cout << c;
	return 0;
}