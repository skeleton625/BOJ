#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int a, int b, vector<int>& inpA, vector<int>& inpB)
{
	sort(inpA.begin(), inpA.end());

	vector<int>::iterator search;
	for (int i = 0; i < b; i++)
	{
		search = lower_bound(inpA.begin(), inpA.end(), inpB[i]);
		if (inpA[search - inpA.begin()] == inpB[i]) cout << "1 ";
		else cout << "0 ";
	}

	cout << '\n';
}

int main()
{
	int a, b;

	cin >> a;
	vector<int> inpA = vector<int>(a, 0);
	for (int i = 0; i < a; i++)
		cin >> inpA[i];

	cin >> b;
	vector<int> inpB = vector<int>(b, 0);
	for (int i = 0; i < b; i++)
		cin >> inpB[i];

	solve(a, b, inpA, inpB);

	cin >> a;
	return 0;
}
