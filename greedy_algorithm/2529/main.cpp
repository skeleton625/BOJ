#include <iostream>
#include <algorithm>
#define NMAX 10
using namespace std;

int k;

// 주어준 숫자들과 부등호가 맞는지 파악하는 함수
bool valid(int* nums, char* ineq)
{
	for (int i = 0; i < k; i++)
	{
		// 현재 부등호와 관련된 숫자들이 맞을 경우 넘어감
		if (ineq[i] == '<' && nums[i] > nums[i + 1])
			// 틀릴 경우 거짓을 반환
			return false;
		if (ineq[i] == '>' && nums[i] < nums[i + 1])
			return false;
	}
	// 모든 부등호와 숫자가 맞을 경우 참을 반환
	return true;
}

int main()
{
	int minNum[NMAX], maxNum[NMAX];
	char ineq[NMAX];

	cin.tie(0);
	ios::sync_with_stdio(false);

	// 부등호 수, 부등호 입력
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> ineq[i];

	// 각각 최대 숫자열, 최소 숫자열을 초기화함
	for (int i = 0; i < NMAX; i++)
	{
		maxNum[i] = NMAX - 1 - i;
		minNum[i] = i;
	}

	// 부등호와 완전히 맞는 숫자열을 생성할 때까지 반복
	while (true)
	{
		// 현재 숫자열이 부등호와 맞을 경우 반복문을 나감
		if (valid(maxNum, ineq))
			break;
		// 현재 숫자 수열의 이전 숫자 수열을 구함
		// ex) 4321 -> 4312 -> 4231 -> 점점 작아짐
		prev_permutation(maxNum, maxNum + k + 1);
	}

	while (true)
	{
		if (valid(minNum, ineq))
			break;
		// 현재 숫자 수열의 다음 숫자 수열을 구함
		// ex) 1234 -> 1243 -> 1324 -> 점점 커짐
		next_permutation(minNum, minNum + k + 1);
	}

	// 각각 최대, 최소 k+1 자리 수의 숫자열 출력
	for (int i = 0; i <= k; i++)
		cout << maxNum[i];
	cout << '\n';
	for (int i = 0; i <= k; i++)
		cout << minNum[i];

	return 0;
}