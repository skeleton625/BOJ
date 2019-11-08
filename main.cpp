#include <iostream>
using namespace std;

int n;
/* 노드 번호의 위치, 포스트 오더 배열 선언 */
int pos[100001], post[100001];

void put_pre_order(int is, int ie, int ps, int pe) {
	/* 인오더, 포스트오더 시작이 끝을 초과할 경우 종료 */
	if (is > ie || ps > pe) return;

	/* 현재 위치의 루트 노드 출력 */
	int root = post[pe];
	cout << root << ' ';

	/*
		트리의 왼쪽, 오른쪽 노드  순회 시작
		인오더 왼쪽 노드 범위(is ~ pos[root] - 1), 오른쪽 노드 범위(pos[root] + 1, ie)
		포스트오더 왼쪽 노드 범위(ps ~ ps + pos[root] - is - 1), 오른쪽 노드 범위(ps + pos[root] - is, pe - 1)
	*/
	put_pre_order(is, pos[root] - 1, ps, ps + pos[root] - is - 1);
	put_pre_order(pos[root] + 1, ie, ps + pos[root] - is, pe - 1);
}

int main() {
	int in;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	/* 트리의 인오더 데이터 입력 */
	for (int i = 0; i < n; i++) {
		cin >> in;
		pos[in] = i;
	}

	/* 트리의 포스트오더 데이터 입력 */
	for (int i = 0; i < n; i++)
		cin >> post[i];

	/* 트리의 프리오더 출력 */
	put_pre_order(0, n - 1, 0, n - 1);
	return 0;
}