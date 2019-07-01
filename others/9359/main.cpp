#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long ll;
vector<ll> prime, divs;
map<ll, bool> m;

void eratos(int n) {
	// �����佺�׳׽��� ü �˰����� ���� ���� �迭 ����
	vector<bool> chk(n + 1, 1);
	// �������׳׽��� ü �˰��� ����
	for (int i = 2; i <= n; i++) {
		if (chk[i]) {
			chk[i] = 0;
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) chk[j] = 0;
		}
	}
}

ll cnt_prime_num(ll a, ll b, ll n) {
	// ������ ���μ� �迭 �ʱ�ȭ
	divs.clear();
	m.clear();
	// ���μ� ���� ���� ������ ���� �÷��� ����
	bool flag;
	// �Էµ� ���� n�� ���μ� ���� ����
	while (n > 1) {
		flag = true;
		// �Ҽ��� ���ؼ� ���� n�� ���μ� ���� ��
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
	// ���μ� ���ذ� ���� ���� ���, 10�� ������ �Ҽ���� ������ �Է�
	if (n != 1) m[n] = true;

	// ���� n�� ���μ��� divs �迭�� �Է�
	// �� ���� �Է����� ���� ������ ���� ���μ� ���� �˰��򿡼� �ߺ����� ���� �� �� �ֱ� ����
	for (auto i : m)
		divs.push_back(i.first);

	// ���� ���� ���� ���� ����
	ll exp_cnt = 0;
	// ���� ���� �˰����� ���� ��Ʈ ����
	ll cas = 1 << divs.size();
	// ���� ���� �˰��� ����
	for (int i = 1; i < cas; i++) {
		ll cnt = 0, sum = 1;
		for (int j = 0; j < divs.size(); j++) {
			// ���� ���� �������� ���õ� ���ڰ� �ƴ� ��� ����
			if (!(i & (1 << j))) continue;
			++cnt, sum *= divs[j];
		}

		// ���� a������ �Ҽ� ���� ����
		ll fir = (a + sum - 1) / sum;
		// ���� b������ �Ҽ� ���� ����
		ll sec = b / sum;
		// ���� a�� �Ҽ� ������ ���� b�� �Ҽ� ������ �ѱ�� ��찡 ���� �� �ֱ� ������ �ش� ���� ����ó����.
		if (fir > sec) continue;
		// ���õ� ���� ������ Ȧ���� ���
		// ������ ���� ������ ���Խ��� ��
		if (cnt & 1) exp_cnt += sec - fir + 1;
		// ���õ� ���� ������ ¦���� ���
		// �ߺ��� �ܿ찡 �����ϹǷ� ������ ��
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
	// 10������ ������ �Ҽ��� ã����.
	eratos(100000);
	// ���̽��� ���� ���μ� ã�� ���α׷� ����
	for (int i = 1; i <= t; i++) {
		cin >> a >> b >> n;
		cout << "Case #" << i << ": " << cnt_prime_num(a, b, n) << '\n';
	}
	return 0;
}