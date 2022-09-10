#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;
int t, i1, m, l;
int main() {
	scanf_s("%d", &t);
	while (t--){
		scanf_s("%d", &i1);
		if (i1 == 0) s.pop();
		else s.push(i1);
	}
	l = s.size();
	for (int i = 0; i < l; i++) {
		m += s.top();
		s.pop();
	}
	printf("%d", m);
}