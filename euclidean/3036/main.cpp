#include "iostream"
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	
	int c;
	cin >> c;
	for (int i = 1; i < t; ++i)
	{
		int r;
		cin >> r;

		int a, b;
		if (c > r)
		{
			a = c;
			b = r;
		}
		else
		{
			a = r;
			b = c;
		}

		int rest;
		while (b > 0)
		{
			rest = a % b;
			a = b;
			b = rest;
		}
		cout << (c / a) << '/' << (r / a) << '\n';
	}
	return 0;
}