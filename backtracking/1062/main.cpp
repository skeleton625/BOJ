#include <iostream>
#include <string>
#define SMAX 50
#define MAX(a, b) ( a < b ? b : a )
using namespace std;

int n, k, ans;
bool visited[26];
string word[SMAX];

void calcWordCount(int pre, int cnt) {
	// 알파벳을 모두 선택한 경우
	if (cnt == k) {
		int c = 0;
		bool flag;
		// 주어진 모든 남극 언어에 대해 알고리즘 진행
		for (int i = 0; i < n; i++) {
			flag = true;
			// 현재 단어를 주어진 알파벳을 통해 만들 수 있는지 판단
			for (int j = 0; j < word[i].size(); j++) {
				if (!visited[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			// 만들 수 있을 경우, 횟수를 세어 줌
			if (flag) ++c;
		}
		// 현재 주어진 알파벳들을 통해 만들 수 있는 단어의 수가 최대인지 판단
		ans = MAX(ans, c);
		// 현재 상황에서 진행을 종료
		return;
	}
	// 백트래킹 알고리즘 실행
	for (int i = pre; i < 26; i++) {
		// 추가되지 않은 알파벳에 한해 진행해 줌
		if (!visited[i]) {
			visited[i] = true;
			calcWordCount(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
	// 현재 상황에서 진행을 종료
	return;
}

int main() {
	string tmp;
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	// 남극언어 숫자, 사용 가능한 알파벳 수 입력
	cin >> n >> k;
	k -= 5;
	// 문자 숫자가 이미 등록된 숫자보다 적을 경우 0을 출력
	if (k < 0) {
		cout << 0;
		return 0;
	}

	// 주어진 숫자만큼 남극 단어 입력
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		word[i] = tmp.substr(4, tmp.size() - 8);
	}

	// 모든 단어에 공통된 알파벳에 대해 참을 표시
	visited['a' - 'a'] =
		visited['c' - 'a'] =
		visited['i' - 'a'] =
		visited['n' - 'a'] =
		visited['t' - 'a'] = true;

	// 백트래킹 알고리즘 실행
	calcWordCount(0, 0);
	// 만들 수 있는 단어 수의 최대를 출력
	cout << ans;
	return 0;
}