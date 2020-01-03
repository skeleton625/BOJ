#include <string>
#include <iostream>
using namespace std;

string inp1, inp2;
string res;

int main()
{
	int len1, len2;
	int abo = 0;
	int c1, c2;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> inp1 >> inp2;
	// 문자열 순회를 끝에서부터 시작
	len1 = inp1.length()-1;
	len2 = inp2.length()-1;

	// 두 문자열 모두 끝까지 이동할 때까지 반복
	while (len1 > -1 || len2 > -1)
	{
		// 문자열이 끝나면 0을 그렇지 않으면 현재 숫자를 정의
		c1 = len1 >= 0 ? inp1[len1]-48 : 0;
		c2 = len2 >= 0 ? inp2[len2]-48 : 0;
		// 정의한 숫자를 더함
		abo += c1 + c2;
		// 정의한 숫자가 10보다 작은 숫자일때와 아닐때로 조건을 나눔
		if (abo > 9)
		{
			res = (char)(abo + 38) + res;
			abo = 1;
		}
		else
		{
			res = (char)(abo + 48) + res;
			abo = 0;
		}
		--len1;
		--len2;
	}
	// 마지막 올림 수가 있을 경우 추가
	if (abo)
		res = '1' + res;
	cout << res;

	return 0;
}