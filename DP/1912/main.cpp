#include <iostream>
#include <algorithm>
#define NMAX 100000
using namespace std;

/* ������ �迭 */
int nsum[NMAX];

int main()
{
	int n, nums;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* ���� ���� �� �Է� �� ���� �� ù ��° �� �Է� */
	cin >> n >> nums;
	/* ù ��° ������ �ʱ�ȭ */
	nsum[0] = nums;
	for (int i = 1; i < n; i++)
	{
		cin >> nums;
		/* ���� �����հ� ���� �Էµ� ���� �� �ִ� ���� �����տ� �Է� */
		nsum[i] = max(nums, nsum[i - 1] + nums);
	}

	/* �Էµ� ������ ���� */
	sort(nsum, nsum + n);
	/* ������ �ִ밪 ��� */
	cout << nsum[n - 1];

	return 0;
}