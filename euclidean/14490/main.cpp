#include <iostream>
#include <string.h>
#define MAX_LENGTH 19
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	char input[MAX_LENGTH];
	cin >> input;

	char* second = NULL;
	char* first = strtok_s(input, ":", &second); // baekjoon function : strtok_r(input, ":", &second);

	int n = atoi(first), m = atoi(second);

	int a, b;
	if (n < m)
	{
		a = m;
		b = n;
	}
	else
	{
		a = n;
		b = m;
	}

	int rest;
	while (b > 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}

	cout << (n / a) << ':' << (m / a);
	return 0;
}