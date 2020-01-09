#include <iostream>
#include <algorithm>
using namespace std;

int n;
int stair[300];
int flo[300];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	/* 1층부터 3층까지의 최대값 초기화 */
	flo[0] = stair[0];
	flo[1] = stair[0] + stair[1];
	flo[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	/* 4층부터 가능한 최대 값을 찾음 */
	for (int i = 3; i < n; i++)
		/* 세번 연속해서 같은 수만큼 올라갈 수 없으므로 섞어서 어느것이 최대값인지 파악 */
		flo[i] = max({ flo[i - 3] + stair[i - 1] + stair[i],flo[i - 2] + stair[i] });

	/* 꼭대기 층의 최대값을 출력 */
	cout << flo[n - 1] << '\n';
	return 0;
}