#include "iostream"
#include "algorithm"
#define ll long long
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int c;
		cin >> c;

		int* values = new int[c];
		for (int j = 0; j < c; ++j)
			cin >> values[j];

		sort(values, values + c);

		ll sum = 0;
		for (int j = 0; j < c; ++j)
		{
			for (int k = j + 1; k < c; ++k)
			{
				int a = values[j];
				int b = values[k], rest;
				while (b > 0)
				{
					rest = a % b;
					a = b;
					b = rest;
				}
				sum += a;
			}
		}
		cout << sum << '\n';
	}

	return 0;
}