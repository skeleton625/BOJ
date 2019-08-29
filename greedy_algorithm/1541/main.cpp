#include <iostream>
#include <string>
#include <vector>
using namespace std;

string inp;
vector<char> arith;
vector<int> nums;

void distinguish()
{
	int fir = 0;
	for (int i = 0; i < inp.size(); i++)
	{
		if (inp[i] == '+' || inp[i] == '-')
		{
			nums.push_back(atoi(inp.substr(fir, i - fir).c_str()));
			arith.push_back(inp[i]);
			fir = i + 1;
		}
	}
	nums.push_back(atoi(inp.substr(fir, inp.size() - fir).c_str()));
}

void calcMin()
{
	int res, i = 0;
	while(i < arith.size())
	{
		if (arith[i] == '+') {
			res = nums[i] + nums[i + 1];
			nums[i] = res;
			arith.erase(arith.begin() + i);
			nums.erase(nums.begin() + i + 1);
			continue;
		}
		i++;
	}

	i = 0;
	res = nums[0];
	for (i = 1; i < nums.size(); i++)
	{
		res -= nums[i];
	}

	cout << res;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> inp;
	distinguish();
	calcMin();
	return 0;
}