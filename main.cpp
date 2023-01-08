#include <iostream>
#include <algorithm>
using namespace std;

int n[3], t;
int main() {
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n[0] >> n[1] >> n[2];
		sort(n, n + 3);
		cout << "Case #" << i;
		if (n[2] < n[0] + n[1]) {
			if (n[0] == n[2]) cout << ": equilateral" << endl;
			else if (n[0] == n[1] || n[1] == n[2]) cout << ": isosceles" << endl;
			else cout << ": scalene" << endl;
		}
		else cout << ": invalid!" << endl;
	}
	return 0;
}