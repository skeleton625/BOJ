#include <iostream>
#include <string>
#include <map>
#define swap(a, b) { string t = a; a = b; b = t; }
using namespace std;

typedef map<string, string> m;
typedef map<string, int> r;

int t, n;

string find(string a, m &m1) {
	if (a == m1[a]) return a;
	return m1[a] = find(m1[a], m1);
}

string merge(string a, string b, m &m1, r &prank, r &cnt) {
	string s1 = find(a, m1), s2 = find(b, m1);

	if (s1 == s2) return s1;
	
	if (prank[s1] > prank[s2]) swap(s1, s2);
	m1[s1] = s2;
	/* 
		���� Union Find ���� �߰��� �κ�
		�� ������ �θ� ��� ���ҿ� �� ������ ��� ������ ����
		�պ��� �� �պ��Ǵ� ���� �θ� ��忡 ���� ���� ��� ������ �߰�
	*/
	cnt[s2] += cnt[s1];

	if (prank[s1] == prank[s2]) ++prank[s2];

	return s2;
}

int main() {
	string a, b, res;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	/* �׽�Ʈ ���̽���ŭ �˰��� ���� */
	while (t--) {
		m inp;		/* ��Ʈ��ũ ���� �� ���� */
		r ran, cnt;	/* �� ��Ʈ��ũ�� ����, ��� ���� �� ���� */
		/* ���� ���� �Է� */
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			/* 
				���� ó�� �Էµ� �̸��� ��� �ʱ�ȭ�� ����
				�ش� ����� �θ� ���� �ڱ� �ڽ��̰� �ش� ������ ��� ������ 1
			*/
			if (inp[a] == "") {
				inp[a] = a;
				cnt[a] = 1;
			}
			if (inp[b] == "") {
				inp[b] = b;
				cnt[b] = 1;
			}
			/* ������ �պ��� ������ ���� �ش� ��Ʈ��ũ�� ��� ���� ��� */
			cout << cnt[merge(a, b, inp, ran, cnt)] << '\n';
		}
	}
	return 0;
}