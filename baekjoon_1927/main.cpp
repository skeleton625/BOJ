#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, c;
vector<int> mat;

void input_heap() {
	int chi = c - 1, par = (chi-1)/2;
	while (chi > 0) {
		if (mat[par] > mat[chi]) swap(mat[par], mat[chi]);
		chi = par;
		par = (chi - 1) / 2;
	}
}

void delete_heap(int par) {
	int left = 2*par+1, right = 2*par+2;
	if (mat[left] > mat[right] && mat[right] != 0) {
		if (mat[par] > mat[right]) {
			swap(mat[par], mat[right]);
			delete_heap(right);
		}
	} else if(mat[left] != 0){
		if (mat[par] > mat[left]) {
			swap(mat[par], mat[left]);
			delete_heap(left);
		}
	}
}

int main() {
	int num;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int len = ceil(log2(n));
	mat = vector<int>(1 << len, 0);
	while (n--) {
		cin >> num;
		if (num == 0) {
			if(c == 0) cout << 0 << '\n';
			else {
				cout << mat[0] << '\n';
				mat[0] = mat[c - 1];
				mat[c - 1] = 0;
				delete_heap(0);
				c--;
			}
		} else {
			mat[c] = num;
			c++;
			input_heap();
		}
	}

	return 0;
}