#include <iostream>
#include <string>
using namespace std;

string i1;
int main() {
	ios::sync_with_stdio(false);
	cin >> i1;
	for (int i = 0; i < i1.size(); i+= 10) cout << i1.substr(i, 10) << endl;
	return 0;
}