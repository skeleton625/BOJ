#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int s, e, n, *al;
map<int, int> dat;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	al = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		al[i] = e;
		if(e-dat[e] >= e-s){
			dat[e] = s;
		}
	}
	sort(al, al + n);
	int c = 1;
	e = 0;
	for (int i = 1; i < n; i++) {
		if (al[e] <= dat[al[i]]) {
			c++;
			e = i;
		}
	}
	cout << c;
	return 0;
}