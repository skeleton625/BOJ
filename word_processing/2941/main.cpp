#include <iostream>
#include <string>
using namespace std;

string words;
string kroaWords[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int isKroa(int pre)
{
	if (pre - 1 >= 0) {
		switch (words[pre])
		{
		case '-':
			if (words[pre - 1] == 'c' || words[pre - 1] == 'd')
				return 0;
		case '=':
			if (pre - 2 >= 0 && "dz=" == words.substr(pre - 2, 3))
				return 1;
			else if (words[pre - 1] == 'c' || words[pre - 1] == 's' || words[pre - 1] == 'z')
				return 0;
		case 'j':
			if (words[pre - 1] == 'l' || words[pre - 1] == 'n')
				return 0;
		default:
			return -1;
		}
	}
	else return -1;
}

int main()
{
	int cnt = 0, flag;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> words;
	for (int i = 0; i < words.size(); i++)
	{
		flag = isKroa(i);
		if (flag == -1) ++cnt;
		else cnt -= flag;
	}
	cout << cnt;
	return 0;
}