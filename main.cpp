#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class stack {
private:
	int s;
	int list[10000];
public:
	void push(int n) { list[s++] = n; }
	int pop() { return !empty()? list[--s] : -1; }
	int top() { return !empty()? list[s-1] : -1; }
	int size() { return s; }
	bool empty() { return s == 0; }
};

int t;
char c[12], n[8];
stack s;

int main() {
	scanf_s("%d%*c", &t);
	while (t--) {
		gets_s(c, 12);
		if (c[0]=='p'&&c[1]=='u') {
			for (int i = 0; c[i + 4]; i++) n[i] = c[i + 4];
			s.push(atoi(n));
			memset(n, 0, 8);
		}
		else if (c[0] == 'p'&&c[1] == 'o') printf("%d\n", s.pop());
		else if (c[0] == 't') printf("%d\n", s.top());
		else if (c[0] == 'e') printf("%d\n", s.empty());
		else if (c[0] == 's') printf("%d\n", s.size());
	}
	return 0;
}

