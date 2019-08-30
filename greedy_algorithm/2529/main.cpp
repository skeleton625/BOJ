#include <iostream>
#include <algorithm>
#define NMAX 10
using namespace std;

int k;

// �־��� ���ڵ�� �ε�ȣ�� �´��� �ľ��ϴ� �Լ�
bool valid(int* nums, char* ineq)
{
	for (int i = 0; i < k; i++)
	{
		// ���� �ε�ȣ�� ���õ� ���ڵ��� ���� ��� �Ѿ
		if (ineq[i] == '<' && nums[i] > nums[i + 1])
			// Ʋ�� ��� ������ ��ȯ
			return false;
		if (ineq[i] == '>' && nums[i] < nums[i + 1])
			return false;
	}
	// ��� �ε�ȣ�� ���ڰ� ���� ��� ���� ��ȯ
	return true;
}

int main()
{
	int minNum[NMAX], maxNum[NMAX];
	char ineq[NMAX];

	cin.tie(0);
	ios::sync_with_stdio(false);

	// �ε�ȣ ��, �ε�ȣ �Է�
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> ineq[i];

	// ���� �ִ� ���ڿ�, �ּ� ���ڿ��� �ʱ�ȭ��
	for (int i = 0; i < NMAX; i++)
	{
		maxNum[i] = NMAX - 1 - i;
		minNum[i] = i;
	}

	// �ε�ȣ�� ������ �´� ���ڿ��� ������ ������ �ݺ�
	while (true)
	{
		// ���� ���ڿ��� �ε�ȣ�� ���� ��� �ݺ����� ����
		if (valid(maxNum, ineq))
			break;
		// ���� ���� ������ ���� ���� ������ ����
		// ex) 4321 -> 4312 -> 4231 -> ���� �۾���
		prev_permutation(maxNum, maxNum + k + 1);
	}

	while (true)
	{
		if (valid(minNum, ineq))
			break;
		// ���� ���� ������ ���� ���� ������ ����
		// ex) 1234 -> 1243 -> 1324 -> ���� Ŀ��
		next_permutation(minNum, minNum + k + 1);
	}

	// ���� �ִ�, �ּ� k+1 �ڸ� ���� ���ڿ� ���
	for (int i = 0; i <= k; i++)
		cout << maxNum[i];
	cout << '\n';
	for (int i = 0; i <= k; i++)
		cout << minNum[i];

	return 0;
}