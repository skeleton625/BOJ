#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int t;
string i1, s;
set<string> st;
// set container를 사용 -> type T에 따른 key 값을 배열로 가짐
// 각 key값은 중복되지 않음
// 각각의 값 접근엔 unordered_set 보다 느리지만 직접적인 추가, 삭제가 가능
vector<string> name;
int main() {
	cin >> t;
	while (t--) {
		cin >> i1 >> s;
		if (s[0] == 'e') st.insert(i1);
		else st.erase(i1);
	}
	for (auto it = st.begin(); it != st.end(); ++it) name.push_back(*it);
	// auto - 자동으로 데이터형을 추론하는 자료형
	// 현재 auto는 set<string>::iterator 자료형을 추론하고 있음.
	reverse(name.begin(), name.end());
	for (auto it = name.begin(); it != name.end(); ++it) cout << *it << '\n';
	// 현재 auto는 vector<string>::iterator 자료형을  추론하고 있음.
	/*
		endl은 개행문자를 출력할 뿐만 아니라 출력 버퍼를 비우는 역할까지 하기 때문에
		기본적으로 출력하는데 시간이 다른 함수에 비해 오래 걸린다. 그래서 보통은 endl
		을 사용하는 것 보다 개행문자'\n'을 사용하는 것이 좋다:.
	*/
	return 0;
}