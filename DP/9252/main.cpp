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
	/* 최장 부분 수열의 길이를 구함 */
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) cnt[i][j] = cnt[i - 1][j - 1] + 1;
			else cnt[i][j] = MAX(cnt[i - 1][j], cnt[i][j - 1]);
		}
	}

	/* 최장 길이 파악 배열의 마지막 위치 정의 */
	int i = s1.size() - 1, j = s2.size() - 1;
	/* 최장 길이 출력 */
	cout << cnt[i][j] << '\n';
	/* 최장 부분 수열 원소들의 집합 문자열 정의 */
	string s = "";
	/* 최장 길이를 구할 때의 반대로 적용 */
	while (cnt[i][j] != 0) {
		/* 만약 왼쪽 배열 원소의 값과 현재 배열 원소 값이 같다면 왼쪽으로 이동 */
		if (cnt[i][j] == cnt[i][j - 1]) --j;
		/* 만약 위쪽 배열 원소의 값과 현재 배열 원소 값이 같다면 위쪽으로 이동 */
		else if (cnt[i][j] == cnt[i - 1][j]) --i;
		/* 만약 대각선 위 배열 원소의 값과 현재 배열 원소 값이 1 차이가 난다면 */
		else if (cnt[i][j] - 1 == cnt[i - 1][j - 1]) {
			s = s2[j] + s;
			--i, --j;
		}
	}
	cout << s;
	return 0;
}