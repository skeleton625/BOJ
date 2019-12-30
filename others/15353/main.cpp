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
	// ���ڿ� ��ȸ�� ���������� ����
	len1 = inp1.length()-1;
	len2 = inp2.length()-1;

	// �� ���ڿ� ��� ������ �̵��� ������ �ݺ�
	while (len1 > -1 || len2 > -1)
	{
		// ���ڿ��� ������ 0�� �׷��� ������ ���� ���ڸ� ����
		c1 = len1 >= 0 ? inp1[len1]-48 : 0;
		c2 = len2 >= 0 ? inp2[len2]-48 : 0;
		// ������ ���ڸ� ����
		abo += c1 + c2;
		// ������ ���ڰ� 10���� ���� �����϶��� �ƴҶ��� ������ ����
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
	// ������ �ø� ���� ���� ��� �߰�
	if (abo)
		res = '1' + res;
	cout << res;

	return 0;
}