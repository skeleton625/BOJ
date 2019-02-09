#include <iostream>
#include <string>
using namespace std;

int n;
int mat[50];
int result[6];

void create_case(int s, int c) {

	if (c == 6) {
		string outp = "";
		for (int i = 0; i < 6; i++)
			outp += to_string(result[i]) + ' ';
		cout << outp << '\n';
		return;
	}

	for (int i = s; i < n; i++) {
		result[c] = mat[i];
		create_case(i + 1, c + 1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n) {
		for (int i = 0; i < n; i++)
			cin >> mat[i];

		create_case(0, 0);
		cout << '\n';
		cin >> n;
	}
	return 0;
}