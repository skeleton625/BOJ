#include <cstdio>

int main() {
	char[1024][1024];
}

/*
#include "iostream"
#include "string"
#include "cmath"
using namespace std;
int n;
string star[1024] = {
	"*",
	"**",
	"* *",
	"****"
};
void create_stars(int count) {
	if (n <= 2 || count == n) {
		for (int i = pow(2,n)-1; i >= 0; i--) {
			cout << star[i] << '\n';
		}
	} else {
		int s = pow(2, count);
		int e = pow(2, count + 1);
		for (int i = s; i < e; i++) {
			star[i].append(star[i-s]);
			for (int j = 0; j < e-i-1; j++) {
				star[i].append(" ");
			}
			star[i].append(star[i - s]);
		}
		create_stars(count + 1);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	create_stars(2);
	return 0;
}
*/