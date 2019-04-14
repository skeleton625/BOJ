#include <iostream>
#include <string>
using namespace std;
#define SMAX 1001
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

int cnt[SMAX][SMAX];
string s1, s2;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	/* ���� �κ� ������ ���̸� ���� */
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) cnt[i][j] = cnt[i - 1][j - 1] + 1;
			else cnt[i][j] = MAX(cnt[i - 1][j], cnt[i][j - 1]);
		}
	}

	/* ���� ���� �ľ� �迭�� ������ ��ġ ���� */
	int i = s1.size() - 1, j = s2.size() - 1;
	/* ���� ���� ��� */
	cout << cnt[i][j] << '\n';
	/* ���� �κ� ���� ���ҵ��� ���� ���ڿ� ���� */
	string s = "";
	/* ���� ���̸� ���� ���� �ݴ�� ���� */
	while (cnt[i][j] != 0) {
		/* ���� ���� �迭 ������ ���� ���� �迭 ���� ���� ���ٸ� �������� �̵� */
		if (cnt[i][j] == cnt[i][j - 1]) --j;
		/* ���� ���� �迭 ������ ���� ���� �迭 ���� ���� ���ٸ� �������� �̵� */
		else if (cnt[i][j] == cnt[i - 1][j]) --i;
		/* ���� �밢�� �� �迭 ������ ���� ���� �迭 ���� ���� 1 ���̰� ���ٸ� */
		else if (cnt[i][j] - 1 == cnt[i - 1][j - 1]) {
			s = s2[j] + s;
			--i, --j;
		}
	}
	cout << s;
	return 0;
}