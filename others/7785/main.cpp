#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int t;
string i1, s;
set<string> st;
// set container�� ��� -> type T�� ���� key ���� �迭�� ����
// �� key���� �ߺ����� ����
// ������ �� ���ٿ� unordered_set ���� �������� �������� �߰�, ������ ����
vector<string> name;
int main() {
	cin >> t;
	while (t--) {
		cin >> i1 >> s;
		if (s[0] == 'e') st.insert(i1);
		else st.erase(i1);
	}
	for (auto it = st.begin(); it != st.end(); ++it) name.push_back(*it);
	// auto - �ڵ����� ���������� �߷��ϴ� �ڷ���
	// ���� auto�� set<string>::iterator �ڷ����� �߷��ϰ� ����.
	reverse(name.begin(), name.end());
	for (auto it = name.begin(); it != name.end(); ++it) cout << *it << '\n';
	// ���� auto�� vector<string>::iterator �ڷ�����  �߷��ϰ� ����.
	/*
		endl�� ���๮�ڸ� ����� �Ӹ� �ƴ϶� ��� ���۸� ���� ���ұ��� �ϱ� ������
		�⺻������ ����ϴµ� �ð��� �ٸ� �Լ��� ���� ���� �ɸ���. �׷��� ������ endl
		�� ����ϴ� �� ���� ���๮��'\n'�� ����ϴ� ���� ����:.
	*/
	return 0;
}