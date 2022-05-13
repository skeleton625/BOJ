#include <cstdio>
#include <cstdlib>
#include <cstring>

class queue {
private:
	int s = 0, i = 0;
	int l[10000];
public:
	void push(int n) { l[i++] = n; }
	int pop(){ 
		if (!empty()) {
			int t = l[s];
			s++;
			return t;
		}
		return -1;
	}
	int front() { return !empty() ? l[s] : -1; }
	int back() { return !empty() ? l[i-1] : -1; }
	int size() { return i-s; }
	bool empty() { return i-s == 0; }
};

int s, t;
char i1[12], n[7];
queue q;
int main() {
	scanf_s("%d%*c", &t);
	while (t--) {
		gets_s(i1, 12);
		if (i1[0] == 'p'&&i1[1] == 'u') {
			for (int i = 0; i1[i + 4]; i++) n[i] = i1[i + 4];
			q.push(atoi(n));
			memset(n, 0, 7);
		} else if (i1[0] == 'p'&&i1[1] == 'o') printf("%d\n", q.pop());
		else if (i1[0] == 'f') printf("%d\n", q.front());
		else if (i1[0] == 'b') printf("%d\n", q.back());
		else if (i1[0] == 'e') printf("%d\n", q.empty());
		else if (i1[0] == 's') printf("%d\n", q.size());
	}
	return 0;
}