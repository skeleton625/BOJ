#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 트리의 노드 구조체 선언 */
struct node {
	int par;
	vector<int> chi;
};

/* 트리를 순회할 bfs 알고리즘 함수 */
int bfs(int start, vector<node> &tree) {
	queue<int> que;
	que.push(start); /* 루트 노드 번호 입력 */

	int cur, cnt = 0;
	/* 
		bfs 알고리즘 실행
		트리에선 방문했던 노드를 재방문할 경우가 없으므로 방문 체크는 안해도 됨
	*/
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* 현재 노드의 자식이 존재하지 않을 경우 리프 노드 */
		if (tree[cur].chi.empty()) {
			cnt++;
			continue;
		}

		/* 연결된 모든 노드를 큐에 입력 */
		for (int i = 0; i < tree[cur].chi.size(); i++)
			que.push(tree[cur].chi[i]);
	}

	return cnt;
}

int main() {
	int n, p, d, root;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 트리의 노드 개수 입력, 트리 배열 정의 */
	cin >> n;
	vector<node> tree(n, { 0, vector<int>(0,0) });
	/* 트리의 정보 입력 */
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == -1) {	/* 입력이 -1일 경우 현재 위치는 루트 노드임 */
			root = i;
		} else {
			/* 
				부모 노드에 현재 노드 번호를 입력
				노드를 자르는 것을 대비해 부모 노드 번호도 같이 입력
			*/
			tree[i].par = p;
			tree[p].chi.push_back(i);
		}
	}
	/* 자를 노드 번호 입력 */
	cin >> d;

	/* 자를 노드가 루트 노드일 경우 0을 출력 */
	if (d == root) {
		cout << 0;
	}
	else { 
		/* 
			그렇지 않을 경우
			자를 노드 번호에 해당하는 부모 노드에서
			연결된 자식들 중, 자를 노드 번호를 삭제
		*/
		p = tree[d].par;
		for (int i = 0; i < tree[p].chi.size(); i++) {
			if (tree[p].chi[i] == d) {
				/* vector의 erase의 인자 -> (vector 포인터 변수) */
				tree[p].chi.erase(tree[p].chi.begin() + i);
				break;
			}
		}

		/* bfs 함수를 실행해 트리를 순회하며 리프 노드 개수를 파악 */
		cout << bfs(root, tree);
	}

	return 0;
}