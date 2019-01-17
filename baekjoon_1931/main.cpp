#include <cstdio>
#include <algorithm>
typedef std::pair<int, int> meet;

meet *m;
int n;

int main() {
	scanf_s("%d", &n);
	m = new meet[n];

	for (int i = 0; i < n; i++)
		scanf_s("%d %d", &m[i].second, &m[i].first);
	sort(m, m + n);
	
	int p = 0, c = 1;
	for (int i = 1; i < n; i++) {
		if (m[i].second >= m[p].first) {
			p = i;
			c++;
		}
	}
	printf("%d", c);
	return 0;
}