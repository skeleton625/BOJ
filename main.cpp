#include <iostream>
#include <algorithm>
using namespace std;

int n;
int mat[1000][3];
int pre_cost[3], next_cost[3];

int main() {
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 집 수와 각 집의 RGB 색의 비용을 입력 */
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i][0] >> mat[i][1] >> mat[i][2];

	/* 현재 각 RGB에 대한 비용 초기화 */
	pre_cost[0] = mat[0][0];
	pre_cost[1] = mat[0][1];
	pre_cost[2] = mat[0][2];

	/* 이전 집과 다음 집의 색이 같게 칠해지지 않도록 하면서 최소가 되도록 계산 */
	for (int i = 1; i < n; i++) {
		next_cost[0] = min(pre_cost[1], pre_cost[2]) + mat[i][0];
		next_cost[1] = min(pre_cost[0], pre_cost[2]) + mat[i][1];
		next_cost[2] = min(pre_cost[0], pre_cost[1]) + mat[i][2];
		for (int j = 0; j < 3; j++)
			pre_cost[j] = next_cost[j];
	}

	/* 최종 결과중 가장 작은 값을 출력 */
	cout << min({ pre_cost[0], pre_cost[1], pre_cost[2] });

	return 0;
}