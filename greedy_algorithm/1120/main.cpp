#include <iostream>
#include <string>
using namespace std;
#define NMAX 51

int main() {
	int dis[NMAX], eql;
	string A, B;

	cin >> A >> B;
	int len = B.size() - A.size() + 1;
	for (int i = 0; i < len; i++) {
		eql = 0;
		for (int j = 0; j < A.size(); j++) {
			if (B[i + j] != A[j]) ++eql;
		}
		dis[i] = eql;
	}

	int minlen = NMAX;
	for (int i = 0; i < len; i++) {
		if (minlen > dis[i]) minlen = dis[i];
	}

	cout << minlen;
	return 0;
}