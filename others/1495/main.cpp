#include <iostream>
using namespace std;

int vols[101][1001];
int n, s, m;

int main()
{
	int pre, plus, minus;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> pre;
		for (int j = 0; j <= m; j++)
		{
			/* 이전 볼륨이 아닌 볼륨은 건너 뜀 */
			if (!vols[i][j]) continue;
			/* 다음 볼륨의 증가 감소를 저장( 0~m 사이 ) */
			plus = pre + j;
			minus = pre - j;
			if (plus <= m) vols[i][plus] = true;
			if (minus >= 0) vols[i][minus] = true;
		}
	}

	/* 마지막 볼륨으로 계산된 값이 있을 경우 출력 */
	for (int i = m; i >= 0; i--)
	{
		if (vols[n][i]) {
			cout << i;
			return 0;
		}
	}
	/* 없을 경우 -1을 출력 */
	cout << -1;
	return 0;
}