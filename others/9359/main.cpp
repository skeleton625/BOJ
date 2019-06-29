#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long ll;
vector<ll> prime, divs;
map<ll, bool> m;

void eratos(int n) {
	// 에라토스테네스의 체 알고리즘을 위한 숫자 배열 정의
	vector<bool> chk(n + 1, 1);
	// 에라스토테네스의 체 알고리즘 실행
	for (int i = 2; i <= n; i++) {
		if (chk[i]) {
			chk[i] = 0;
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) chk[j] = 0;
		}
	}
}

ll cnt_prime_num(ll a, ll b, ll n) {
	// 샤옹할 소인수 배열 초기화
	divs.clear();
	m.clear();
	// 소인수 분해 실행 유무에 대한 플래그 변수
	bool flag;
	// 입력된 숫자 n의 소인수 분해 실행
	while (n > 1) {
		flag = true;
		// 소수를 통해서 숫자 n을 소인수 분해 함
		for (auto i : prime) {
			if (!(n % i)) {
				n /= i;
				m[i] = true;
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	// 소인수 분해가 되지 않은 경우, 10만 이후의 소수라고 생각해 입력
	if (n != 1) m[n] = true;

	// 숫자 n의 소인수를 divs 배열에 입력
	// 한 번에 입력하지 못한 이유는 위의 소인수 분해 알고리즘에서 중복으로 값이 들어갈 수 있기 때문
	for (auto i : m)
		divs.push_back(i.first);

	// 제외 숫자 개수 변수 정의
	ll exp_cnt = 0;
	// 포함 배제 알고리즘을 위한 비트 정의
	ll cas = 1 << divs.size();
	// 포함 배제 알고리즘 실행
	for (int i = 1; i < cas; i++) {
		ll cnt = 0, sum = 1;
		for (int j = 0; j < divs.size(); j++) {
			// 만일 현재 시점에서 선택된 숫자가 아닐 경우 제외
			if (!(i & (1 << j))) continue;
			++cnt, sum *= divs[j];
		}

		// 숫자 a까지의 소수 개수 정의
		ll fir = (a + sum - 1) / sum;
		// 숫자 b까지의 소수 개수 정의
		ll sec = b / sum;
		// 숫자 a의 소수 개수가 숫자 b의 소수 개수를 넘기는 경우가 생길 수 있기 때문에 해당 경우는 예외처리함.
		if (fir > sec) continue;
		// 선택된 숫자 개수가 홀수일 경우
		// 제외할 숫자 개수를 포함시켜 줌
		if (cnt & 1) exp_cnt += sec - fir + 1;
		// 선택된 숫자 개수가 짝수일 경우
		// 중복된 겨우가 존재하므로 제거해 줌
		else exp_cnt -= sec - fir + 1;
	}
	return b-a-exp_cnt+1;
}

int main() {
	int t;
	ll a, b, n;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	// 10만개의 수에서 소수를 찾아줌.
	eratos(100000);
	// 케이스에 따른 서로소 찾기 프로그램 실행
	for (int i = 1; i <= t; i++) {
		cin >> a >> b >> n;
		cout << "Case #" << i << ": " << cnt_prime_num(a, b, n) << '\n';
	}
	return 0;
}