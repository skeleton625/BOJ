#include <iostream>
using namespace std;
// �Է� �ִ밪
#define NMAX 16
// �� �Ű������� ���� �ִ밪 ��ȯ ��ũ��
#define MAX(a, b) ( a < b ? b : a )

// ��¥ �� ����
int n, res;
// �� �Ͽ� ���� �ҿ� �ð��� ��� �迭
pair<int, int> dp[NMAX];

// ��¥ �Ű������� ���� �� ���� ���θ� �ľ��ϴ� ��� �Լ�
void tracking(int day, int money)
{
	// ���� ���� ��¥�� ��� ��¥ ������ ��� ������� ���� �ݾװ� �ִ� �ݾ��� ��
	if (day >= n + 1)
		res = MAX(res, money);
	// ���� ��� ��¥�� �ƴ� ���
	else
	{
		// ���� ��¥�� �� �� �ִ� ���� ��� ��¥ ������ �� �� �ִ� ���
		if (day + dp[day].first <= n + 1)
			// ������ ��¥�� �ݾ��� �Ű������� ����Լ� ����
			tracking(day + dp[day].first, money + dp[day].second);
		// ���� ��¥�� �� �� �ִ� ���� ���ϰ� ���� ���� �� ����� ����Լ� ����
		tracking(day + 1, money);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// �� ��¥ �� �Է�
	cin >> n;
	// �� �Ͽ� ���� �ҿ� �ð�, ����� �Է� 
	for (int i = 1; i <= n; i++)
		cin >> dp[i].first >> dp[i].second;

	// 1�Ϻ��� �ִ� �ݾ� �ľ� �Լ� ����
	tracking(1, 0);
	// �ִ� �ݾ� ���
	cout << res;
	return 0;
}