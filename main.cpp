#include <cstdio>
#include <map>

/* 트리 내의 노드 순서를 파악하기 위한 map 자료형 */
std::map<int, int> m;
/* 각각 pre order, 노드 위치 배열 선언 */
int pre[10000], pos[1000000];

void put_post_order(int is, int ie, int ps, int pe) {
	/* 재귀를 통해 트리의 범위가 벗어난 경우 반환 */
	if (is > ie || ps > pe) return;

	/* 현재 노드의 키 값을 정의 */
	int root = pre[ps];

	/* post order 실행 */
	put_post_order(is, pos[root] - 1, ps + 1, ps + pos[root] - is);
	put_post_order(pos[root] + 1, ie, ps + pos[root] - is + 1, pe);
	printf("%d\n", root);
}

int main() {
	int inp = 0, n = 0;

	/* map과 pre order 배열에 pre order 데이터를 입력 */
	while (scanf_s("%d", &inp)) {
		pre[n++] = inp;
		m[inp] = 1;
	}

	/* map에 입력해둔 노드의 위치를 배열에 입력해줌 */
	n = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		pos[it->first] = n++;

	put_post_order(0, n - 1, 0, n - 1);
	return 0;
}