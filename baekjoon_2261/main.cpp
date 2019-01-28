#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> pai;
typedef unsigned long long ll;
int n;

/* 두 점간의 최소 길이의 제곱을 반환하는 함수 */
ll getDist(pai d1, pai d2) {
	int x = d2.first - d1.first;
	int y = d2.second - d1.second;
	return (ll)(x * x + y * y);
}

/* 각 점들 사이의 최소 길이를 비교해 가장 최소 길이의 제곱을 반환하는 함수 */
ll comp_dots(vector<pai>::iterator dots, int n) {
	/* 범위 안에 두 개의 점만 있을 경우 최소 길이를 계산해 반환 */
	if (n == 2)
		return getDist(dots[0], dots[1]);
	/* 범위 안에 세 개의 점만 있을 경우 최소 길이를 계산해 반환 */
	if (n == 3)
		return min({ getDist(dots[0], dots[1]), getDist(dots[1], dots[2]), getDist(dots[2],dots[0]) });

	/* x축을 중간 지점으로 나눴을 경우, 중간을 기준으로 이전, 이후에 있는 점의 중간 x 값을 구함 */
	int line = (dots[n/2-1].first + dots[n/2].first) / 2;
	/* 중간 지점으로 나눈 뒤, 이전과 이후 구간의 최소 길이를 구해 변수 d에 정의 */
	ll d = min(comp_dots(dots, n/2), comp_dots(dots+n/2,n-n/2));

	/* x축으로 정렬된 값 중 지정된 지점에 있는 점들을 y축으로 정렬시킬 vector 변수 */
	vector<pai> mid;

	/* 
		중간 지점을 기준으로 점들의 거리가 최소 길이 d보다 작을 경우 vector 변수 mid에 입력 
		입력할 때 x, y 값을 이전 vector 변수와 반대로 입력( x, y -> y, x )
	*/
	for (int i = 0; i < n; i++) {
		int t = line - dots[i].first;
		if ((ll)(t*t) < d)
			mid.push_back({dots[i].second, dots[i].first});
	}
	/* vector 변수 mid에 입력된 점들을 y축을 기준으로 정렬함 */
	sort(mid.begin(), mid.end());
	
	int mid_sz = mid.size();
	/* i -> 점 1, j -> 점 2 */
	/* 
		vector 변수 mid에 입력된 점들의 길이를 측정 
		해당 점들의 거리가 최소 길이를 벗어나지 않는 구간 내에서만 측정함
		즉, 해당 점들은 중간 지점에 최소 길이를 둔 점들 중 가장 작은 길이가 있는지 확인하기 위함
	*/
	for (int i = 0; i < mid_sz - 1; i++)
		for (int j = i + 1; j < mid_sz && mid[j].first - mid[i].first < d; j++)
			d = min(d, getDist(mid[i], mid[j]));
	
	return d;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	/* 점을 입력받아 둘 vector 변수 */
	vector<pai> dots(n);
	for (int i = 0; i < n; i++)
		cin >> dots[i].first >> dots[i].second;

	/* 입력받은 점들을 x축 기준으로 정렬 */
	sort(dots.begin(), dots.end());

	cout << comp_dots(dots.begin(), n);
	return 0;
}
