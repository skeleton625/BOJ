#include "iostream"
#include "string"
#include "map"
using namespace std;

char re[16];
string op;
string op_code[25] = {"ADD", "ADDC", "SUB", "SUBC", "MOV", "MOVC", "AND", 
						"ANDC", "OR", "ORC", "NOT", "", "MULT", "MULTC", "LSFTL",
						"LSFTLC", "LSFTR", "LSFTRC", "ASFTR", "ASFTRC", "RL", "RLC", 
						"RR", "RRC"};
int n1, n2, n3;
map<string, int> op_hash;

void trans_op() {
	int tmp;
	tmp = op_hash[op];
	for (int i = 4; i >= 0; i--) {
		re[i] = (tmp & 1) + 48;
		tmp >>= 1;
	}
	for (int i = 8; i >= 6; i--) {
		re[i] = (n1 & 1) + 48;
		n1 >>= 1;
	}
	if (op == "MOV" || op == "MOVC" || op == "NOT") {
		for (int i = 11; i >= 9; i--) re[i] = 48;
	} else {
		for (int i = 11; i >= 9; i--) {
			re[i] = (n2 & 1) + 48;
			n2 >>= 1;
		}
	}
	if (op.back() == 'C') {
		for (int i = 15; i >= 12; i--) {
			re[i] = (n3 & 1) + 48;
			n3 >>= 1;
		}
	} else {
		for (int i = 14; i >= 12; i--) {
			re[i] = (n3 & 1) + 48;
			n3 >>= 1;
		}
		re[15] = '0';
	}
	cout << re << '\n';
}

int main() {
	int c;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> c;
	re[5] = '0';
	for (int i = 0; i < 25; i++)
		op_hash.insert(make_pair(op_code[i], i));
	while (c--) {
		cin >> op >> n1 >> n2 >> n3;
		trans_op();
	}
	return 0;
}