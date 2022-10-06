#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int count;
	cin >> count;
	
	int* inputs = new int[count];
	for (int i = 0; i < count; ++i)
		cin >> inputs[i];
	sort(inputs, inputs + count);

	int a, b, rest, preGCD = inputs[1] - inputs[0];
	for (int i = 1; i < count - 1; ++i)
	{
		a = preGCD;
		b = inputs[i + 1] - inputs[i];
		while (b != 0)
		{
			rest = a % b;
			a = b;
			b = rest;
		}
		preGCD = a;
	}

	for (int i = 2; i <= preGCD / 2; ++i)
	{
		if (preGCD % i == 0) cout << i << ' ';
	}
	cout << preGCD;
	return 0;
}