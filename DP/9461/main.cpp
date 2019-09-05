#include <iostream>
#define NMAX 101
using namespace std;

unsigned long long nums[NMAX] = { 0, 1, 1, 1, 2, 2 };

int main()
{
	int n, t, c = 6;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		cin >> n;
		if (nums[n] != 0)
			cout << nums[n] << '\n';
		else
		{
			for (int i = c; i <= n; i++)
			{
				nums[i] = nums[i - 1] + nums[i - 5];
			}
			cout << nums[n] << '\n';
			c = n;
		}
	}

	return 0;
}