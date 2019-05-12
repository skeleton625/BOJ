#include <iostream>
using namespace std;

int p[3][2];

int main() {
	int s;
	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++)
		cin >> p[i][0] >> p[i][1];

	/* p1, p2와 p2, p3 선분 외적을 통해 전체 방향을 파악 */
	s = (p[1][0] - p[0][0]) * (p[2][1] - p[0][1]) - (p[2][0] - p[0][0]) * (p[1][1] - p[0][1]);
	
	/* 외적을 통해 두 선분의 단위 백터가 가리키는 방향이 어느 방향인지 파악함 */
	
	if (s > 0) cout << 1;
	else if (s < 0) cout << -1;
	else cout << 0;

	return 0;
}