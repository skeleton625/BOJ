#include "iostream"
#include "algorithm"
using namespace std;

int GCD(int a, int b)
{
	int rest;
	while (b > 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}
	return a;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, s;
	cin >> n >> s;

	int* inputs = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> inputs[i];

	sort(inputs, inputs + n);

	if (n == 1)
	{
		cout << abs(inputs[0] - s);
	}
	else
	{
		int preGCD = abs(inputs[0] - s);
		for (int i = 1; i < n; ++i)
		{
			preGCD = GCD(preGCD, abs(inputs[i] - s));
		}
		cout << preGCD;
	}

	return 0;
}