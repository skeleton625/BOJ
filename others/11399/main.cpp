#include <iostream>
#include <algorithm>
using namespace std;

int cash[1000], n,re;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cash[i];
	sort(cash, cash + n);
	for (int i = 1; i < n; i++) {
		re += cash[i - 1];
		cash[i] += cash[i - 1];
	}
	cout << re+cash[n-1];
	return 0;
}