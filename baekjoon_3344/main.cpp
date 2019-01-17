#include <cstdio>
#include <string>
using namespace std;

/* 
	https://en.wikipedia.org/wiki/Eight_queens_puzzle#Explicit_solutions 
	-> Existence of soultions
*/

int main() {
	int n;
	string result;
	
	scanf_s("%d", &n);
	bool isOdd = n % 2;
	if (isOdd) n--;
	if (n % 6 != 2) {
		for (int i = 1; i <= n / 2; i++)
			result.append(to_string(2 * i) + '\n');
		for (int i = 1; i <= n / 2; i++)
			result.append(to_string(2 * i-1) + '\n');
	} else if (n % 6 != 0) {
		int tmp = n / 2;
		for (int i = 1; i <= tmp; i++)
			result.append(to_string(1 + (2 * i + tmp - 3) % n) + '\n');
		for (int i = tmp; i >= 1; i--)
			result.append(to_string(n - (2 * i + tmp - 3) % n) + '\n');
		
	}
	if (isOdd) result.append(to_string(n + 1));
	puts(result.c_str());
	return 0;
}