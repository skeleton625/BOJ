#include <iostream>
#include <algorithm>
#include <vector>
#define DMAX 5000000
using namespace std;

typedef pair<int, int> ver;

int n, m;
vector<ver> mat[501];
vector<int> dist;

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ c, b });
	}

	dist = vector<int>(n + 1, DMAX);
	dist[1] = 0;

	int nn, nd;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < mat[j].size(); k++) {
				nn = mat[j][k].second, nd = dist[j]+mat[j][k].first;
				if (dist[j] != DMAX && dist[nn] > nd) {
					dist[nn] = nd;
					if (i == n) {
						cout << -1 << '\n';
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << (dist[i] != DMAX ? dist[i] : -1) << '\n';
	return 0;
}