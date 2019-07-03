#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> comms;
bool mat[21];

void select_calc(string comm, int n) {
	switch (comms[comm]) {
	case 0:
		mat[n] = true;
		break;
	case 1:
		mat[n] = false;
		break;
	case 2:
		cout << (mat[n] ? 1 : 0) << '\n';
		break;
	case 3:
		if (mat[n]) mat[n] = false;
		else mat[n] = true;
		break;
	case 4:
		for (int i = 1; i < 21; i++) mat[i] = true;
		break;
	case 5:
		for (int i = 1; i < 21; i++) mat[i] = false;
		break;
	}
}

int main() {
	int n, num;
	string comm;
	cin.tie(0);
	ios::sync_with_stdio(false);
	comms["add"] = 0;
	comms["remove"] = 1;
	comms["check"] = 2;
	comms["toggle"] = 3;
	comms["all"] = 4;
	comms["empty"] = 5;

	cin >> n;
	while (n--) {
		cin >> comm;
		if (comms[comm] < 4) cin >> num;
		select_calc(comm, num);
	}
	return 0;
}