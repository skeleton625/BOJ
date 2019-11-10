#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ver;
int n;
ver mat[26];

void dfs_lr(int num) {

	cout << (char)(num + 'A');

	if (mat[num].first != 0)
		dfs_lr(mat[num].first);

	if (mat[num].second != 0)
		dfs_lr(mat[num].second);
}

void dfs_c(int num) {
	if (mat[num].first != 0)
		dfs_c(mat[num].first);

	cout << (char)(num + 'A');


	if (mat[num].second != 0)
		dfs_c(mat[num].second);
}

void dfs_rl(int num) {

	if (mat[num].first != 0)
		dfs_rl(mat[num].first);

	if (mat[num].second != 0)
		dfs_rl(mat[num].second);

	cout << (char)(num + 'A');
}

int main() {
	char p, c1, c2;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> c1 >> c2;
		if(c1 != '.') mat[p - 'A'].first = c1 - 'A';
		if(c2 != '.') mat[p - 'A'].second = c2 - 'A';
	}

	dfs_lr(0);
	cout << '\n';
	dfs_c(0);
	cout << '\n';
	dfs_rl(0);

	return 0;
}