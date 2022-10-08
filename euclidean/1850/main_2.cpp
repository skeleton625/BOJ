#include "iostream";
#include "string";
#define ll long long
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	ll a, b;
	cin >> a >> b;
	
	ll rest;
	while (b > 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}

	string result = "";
	for (int i = 0; i < a; ++i) result += '1';
	cout << result;
	return 0;
}