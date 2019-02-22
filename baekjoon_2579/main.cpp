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

	/* 1������ 3�������� �ִ밪 �ʱ�ȭ */
	flo[0] = stair[0];
	flo[1] = stair[0] + stair[1];
	flo[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	/* 4������ ������ �ִ� ���� ã�� */
	for (int i = 3; i < n; i++)
		/* ���� �����ؼ� ���� ����ŭ �ö� �� �����Ƿ� ��� ������� �ִ밪���� �ľ� */
		flo[i] = max({ flo[i - 3] + stair[i - 1] + stair[i],flo[i - 2] + stair[i] });

	/* ����� ���� �ִ밪�� ��� */
	cout << flo[n - 1] << '\n';
	return 0;
}