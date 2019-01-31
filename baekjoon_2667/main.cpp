#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos {
	int x, y;
};
char input[25][25];
bool visit[25][25];
int dir[4][2] = { {-1, 0}, {0, -1}, {1,0}, {0,1} };
int n, num;

int find_aprt(int fx, int fy) {
	int count = 1;
	
	queue<pos> que;
	visit[fx][fy] = 1;
	que.push({ fx, fy });

	while (!que.empty()) {
		pos cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++) {
			int rx = cur.x + dir[i][0], ry = cur.y + dir[i][1];
			if (rx < 0 || ry < 0 || rx > n - 1 || ry > n - 1)
				continue;
			else if (input[rx][ry] == '0')
				continue;
			else if(!visit[rx][ry]){
				visit[rx][ry] = 1;
				count++;
				que.push({ rx,ry });
			}
		}
	}
	return count;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> aprt_c;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (input[i][j] == '1' && !visit[i][j])
				aprt_c.push_back(find_aprt(i, j));
		}
	}

	sort(aprt_c.begin(), aprt_c.end());
	cout << aprt_c.size() << '\n';
	for (int i = 0; i < aprt_c.size(); i++)
		cout << aprt_c[i] << '\n';

	return 0;
}