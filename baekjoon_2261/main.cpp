#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef pair<int, int> pai;
typedef unsigned long long ll;

pai dots[100000];
map<pai, int> comp_dots;
int n;

/* 점과 점 사이의 최소 거리를 구하는 함수 */
ll getDist(pai d1, pai d2) {
	int x = d2.first - d1.first;
	int y = d2.second - d1.second;
	return (ll)(y * y + x * x);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dots[i].first >> dots[i].second;
	/* 점들의 x값에 대해서 정렬 */
	sort(dots, dots + n);

	/* x축 기준으로 정렬했을 경우 dots 0, dots 1를 가장 가까운 점으로 지정 */
	comp_dots[{dots[0].second, dots[0].first}] = 1;
	comp_dots[{dots[1].second, dots[1].first}] = 1;

	/* 현재 지정된 두 점 사이의 길이를 최소 길이로 지정 */
	ll res_min = getDist(dots[0], dots[1]);

	/* 현재 점 위치와 가장 가까운 점 위치를 파악하기 위한 위치 변수 */
	int last = 0;
	
	/* dots 0, dots 1은 이미 지정한 상태이니 그 다음 번째 dots 부터 탐색 시작 */
	for (int i = 2; i < n; i++) {
		while (last < i) {
			ll x = dots[last].first - dots[i].first;
			/* x축으로 최소 길이보다 현재 점과 이전 점의 위치가 작거나 같을 경우 정지 -> 해당 위치를 최소로 선택 */
			if (x*x <= res_min) {
				break;
			}
			/* 그렇지 않을 경우 해당 값은 필요가 없으므로 비교 대상에서 제외시킴 */
			else {
				comp_dots.erase({ dots[last].second, dots[last].first });
				/* 비교할 이전 점의 위치를 이동시킴 */
				last++;
			}
		}

		/* y축 상에서 실제 길이로 최소 범위를 파악하기 위해 현재 최소 길이의 실제 길이를 구함 */
		int dist = sqrt(res_min);

		/* map에 저장되어 있는 점들 중에서 최소 실제 길이 내에 있는 점들을 파악하기 위해 lower, upper bound를 실행 */
		/* 여기서 x값의 경우 정수 절대값으로 10000을 넘지 않기 때문에 x의 범위로 설정 */
		auto lo = comp_dots.lower_bound({ dots[i].second - dist, -10000 });
		auto up = comp_dots.upper_bound({ dots[i].second + dist, 10000 });

		/* 최소 실제 길이 내에 존재하는 점들과 현재 점과의 거리를 계산, 최소 값을 결정해줌 */
		for (auto it = lo; it != up; it++)
			res_min = min(res_min, getDist({ it->first.second, it->first.first }, dots[i]));

		/* 현재 점이 최소 길이에 있는 점이므로 map에 추가해줌 */
		comp_dots[{dots[i].second, dots[i].first}] = 1;
	}

	cout << res_min;
	return 0;
}
