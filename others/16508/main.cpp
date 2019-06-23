#include <iostream>
#include<cstring>
#include<string>
#define MIN(a, b) (a < b? a : b);
#define INF 1600000
using namespace std;

int n, cost, res = INF;
bool used[16];
int letter[26], cnt[26];
pair<int, int[26]> book[16];

void make_sent_by_book(int pos) {
	if (pos == n) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			if (!used[i]) continue;
			for (int j = 0; j < 26; j++)
				cnt[j] += book[i].second[j];
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] < letter[i]) return;
		}
		res = MIN(res, cost);
		return;
	}

	used[pos] = true;
	cost += book[pos].first;
	make_sent_by_book(pos + 1);

	used[pos] = false;
	cost -= book[pos].first;
	make_sent_by_book(pos + 1);
}

int main() {
	string word, title;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> word >> n;
	for (int i = 0; i < word.size(); i++)
		++letter[word[i] - 'A'];

	for (int i = 0; i < n; i++) {
		cin >> book[i].first >> title;
		for (int j = 0; j < title.size(); j++) {
			++book[i].second[title[j]-'A'];
		}
	}
	make_sent_by_book(0);
	if (res == INF) cout << -1;
	else cout << res;

	return 0;
}