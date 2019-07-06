#include <iostream>
#include <string>
#define SMAX 50
#define MAX(a, b) ( a < b ? b : a )
using namespace std;

int n, k, ans;
bool visited[26];
string word[SMAX];

void calcWordCount(int pre, int cnt) {
	// ���ĺ��� ��� ������ ���
	if (cnt == k) {
		int c = 0;
		bool flag;
		// �־��� ��� ���� �� ���� �˰��� ����
		for (int i = 0; i < n; i++) {
			flag = true;
			// ���� �ܾ �־��� ���ĺ��� ���� ���� �� �ִ��� �Ǵ�
			for (int j = 0; j < word[i].size(); j++) {
				if (!visited[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			// ���� �� ���� ���, Ƚ���� ���� ��
			if (flag) ++c;
		}
		// ���� �־��� ���ĺ����� ���� ���� �� �ִ� �ܾ��� ���� �ִ����� �Ǵ�
		ans = MAX(ans, c);
		// ���� ��Ȳ���� ������ ����
		return;
	}
	// ��Ʈ��ŷ �˰��� ����
	for (int i = pre; i < 26; i++) {
		// �߰����� ���� ���ĺ��� ���� ������ ��
		if (!visited[i]) {
			visited[i] = true;
			calcWordCount(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
	// ���� ��Ȳ���� ������ ����
	return;
}

int main() {
	string tmp;
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	// ���ؾ�� ����, ��� ������ ���ĺ� �� �Է�
	cin >> n >> k;
	k -= 5;
	// ���� ���ڰ� �̹� ��ϵ� ���ں��� ���� ��� 0�� ���
	if (k < 0) {
		cout << 0;
		return 0;
	}

	// �־��� ���ڸ�ŭ ���� �ܾ� �Է�
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		word[i] = tmp.substr(4, tmp.size() - 8);
	}

	// ��� �ܾ ����� ���ĺ��� ���� ���� ǥ��
	visited['a' - 'a'] =
		visited['c' - 'a'] =
		visited['i' - 'a'] =
		visited['n' - 'a'] =
		visited['t' - 'a'] = true;

	// ��Ʈ��ŷ �˰��� ����
	calcWordCount(0, 0);
	// ���� �� �ִ� �ܾ� ���� �ִ븦 ���
	cout << ans;
	return 0;
}