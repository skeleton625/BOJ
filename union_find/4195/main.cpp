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
		기존 Union Find 에서 추가된 부분
		각 집합의 부모 노드 원소에 그 집합의 노드 개수를 저장
		합병할 때 합병되는 집합 부모 노드에 이전 집합 노드 개수를 추가
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
	/* 테스트 케이스만큼 알고리즘 실행 */
	while (t--) {
		m inp;		/* 네트워크 집합 맵 선언 */
		r ran, cnt;	/* 각 네트워크의 깊이, 노드 개수 맵 선언 */
		/* 집합 관계 입력 */
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			/* 
				만약 처음 입력된 이름일 경우 초기화를 해줌
				해당 노드의 부모 노드는 자기 자신이고 해당 집합의 노드 개수는 1
			*/
			if (inp[a] == "") {
				inp[a] = a;
				cnt[a] = 1;
			}
			if (inp[b] == "") {
				inp[b] = b;
				cnt[b] = 1;
			}
			/* 집합의 합병을 실행한 다음 해당 네트워크의 노드 개수 출력 */
			cout << cnt[merge(a, b, inp, ran, cnt)] << '\n';
		}
	}
	return 0;
}