#include <iostream>
#include <string>
using namespace std;

int t, i1, i2, a, b;
string d[6] = { "Yakk","Doh","Seh","Ghar","Bang","Sheesh" };
string de[7] = { "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh", "Sheesh Beesh" };
int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; i ++){
		cin >> i1 >> i2;
		cout << "Case " << i << ": ";
		if (i1 - i2 == 0) cout << de[i1-1] << '\n';
		else {
			if ((i1 == 6 && i2 == 5) || (i1 == 5 && i2 == 6)) cout << de[6] << '\n';
			else {
				a = i1 > i2 ? i2 : i1;
				b = i1 > i2 ? i1 : i2;
				cout << d[b - 1] << ' ' << d[a - 1] << '\n';
			}
		}
	}
	return 0;
}