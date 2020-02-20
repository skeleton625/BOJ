#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d, n ,cons, coll;
char mat[15];
string result;

bool figure_cons(char c) {
	switch (c) {
	case 'a': 
	case 'e': 
	case 'i': 
	case 'o': 
	case 'u':
		return true;
	default:
		return false;
	}
}

void find_password(int pre, int dep) {
	if (dep == d) {
		if (cons >= 1 && coll >= 2) cout << result << '\n';
		return;
	}
	else {
		bool is_cons = false;
		for (int i = pre; i < n; i++) {
			if (figure_cons(mat[i])) {
				cons++;
				is_cons = true;
			} else coll++;
			result.push_back(mat[i]);
			
			find_password(i+1, dep+1);
			
			result.pop_back();
			if (is_cons) {
				cons--;
				is_cons = false;
			} else coll--;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> d >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
	sort(mat, mat + n);

	find_password(0, 0);

	return 0;
}