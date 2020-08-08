#include <iostream>
#include <string>
using namespace std;

char mat[64][64];
int n;

string quad_tree(int x, int y, int ex, int ey) {
	if (ex-x == 1 && ey-y == 1) {
		string str;
		if (mat[x][y] == mat[x][ey] && mat[x][ey] == mat[ex][y] && mat[ex][y] == mat[ex][ey]) {
			str.push_back(mat[x][y]);
			return str;
		}
		else {
			str.push_back('(');
			str.push_back(mat[x][y]);
			str.push_back(mat[x][ey]);
			str.push_back(mat[ex][y]);
			str.push_back(mat[ex][ey]);
			str.push_back(')');
			return str;
		}
	}
	else {
		int tex = (ex-x) / 2;
		int tey = (ey-y) / 2;
		string lu = quad_tree(x, y, tex+x, tey+y);
		string ru = quad_tree(x, ey-tey, tex+x, ey);
		string ld = quad_tree(ex-tex, y, ex, tey+y);
		string rd = quad_tree(ex - tex, ey - tey, ex, ey);
		if(lu == ru && ru == ld && ld == rd) {
			if (lu.front() == '(') return '(' + lu + ru + ld + rd + ')';
			else return lu;
		} else {
			return '(' + lu + ru + ld + rd + ')';
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	cout << quad_tree(0, 0, n-1, n-1);


	return 0;
}