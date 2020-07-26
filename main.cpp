#include <iostream>
using namespace std;

int mat[5][5];
int re[5][5];
int tmp[5][5], sum;
int n;
unsigned long long b;

void pow_matrix(int mat1[5][5], int mat2[5][5]) {
	tmp[5][5] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int k = 0; k < n; k++) {
				sum = (sum + (mat1[i][k] * mat2[k][j]) % 1000) % 1000;
			}
			tmp[i][j] = sum;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
		re[i][i] = 1;
	}
	while (b) {
		if (b & 1) {
			pow_matrix(re, mat);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					re[i][j] = tmp[i][j];
			}
		}
		b >>= 1;
		if (b == 0) break;
		pow_matrix(mat, mat);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				mat[i][j] = tmp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << re[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}