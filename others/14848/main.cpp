#include <iostream>
using namespace std;

typedef unsigned long long ll;

int num[15];

ll gcd(ll a, ll b) {
	int tmp;
	while (a) {
		tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

int main() {
	ll n, k;
	cin.tie(0);
	ios::sync_with_stdio(false);

	// 숫자열 끝과 배열 A의 원소 개수 입력
	cin >> n >> k;
	// 배열 A의 원소 입력
	for (int i = 0; i < k; i++)
		cin >> num[i];

	// 배열 원소들의 모든 경우의 수를 표현하기 위한 이진수 변수 x
	// 삭제할 숫자의 개수 변수 sum 정의
	ll x = (1 << k), sum = 0;
	// 배열 A 원소들에 대해 삭제할 숫자 개수 탐색 실행
	for (int i = 0; i < x; i++) {
		// 현재 시점에서 삭제할 숫자 개수  변수 cnt
		// 현재 시점에서 선택된 배열 A의 숫자들에 대한 최소공배수 변수 gap 정의
		ll cnt = 0, gap = 0;
		for (int j = 0; j < k; j++) {
			// 이진수의 숫자 자리를 통해 배열A의 선택 여부를 판단함
			if (i & (1 << j)) {
				// 선택된 숫자의 개수 파악
				++cnt;
				// 변수 gap이 정의되지 않은 상태일 경우, 초기화 해줌
				if (gap == 0) {
					gap = num[j];
				}
				else {
					// 이전에 구한 최소공배수 gap과 현재 숫자에 대한 최소공배수를 구함
					// 배열 A에서 선택된 모든 숫자들에 대한 최소공배수를 구해 삭제할 숫자를 파악
					gap = gap * num[j] / gcd(num[j], gap);
				}
			}
		}
		// 선택된 숫자가 있을 경우
		if (cnt) {
			// 선택된 숫자들의 최소공배수를 통해 삭제할 숫자의 개수 파악 
			ll p = n / gap;
			// 만약 선택된 숫자의 개수가 짝수일 경우
			// 삭제할 숫자들이 중복으로 추가되기 때문에 중복 중 하나는 제거해야 함
			if (cnt % 2 == 0) sum -= p;
			// 그렇지 않은 경우, 이전 과정에서 중복을 2번 이상 제거했기 때문에
			// 그에 대한 삭제할 숫자를 추가해 줌.
			else sum += p;
		}
	}
	// 삭제할 숫자 개수를 통해 삭제되고 남은 숫자 개수를 출력
	cout << n - sum;
	return 0;
}