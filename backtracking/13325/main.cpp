#include <iostream>
#include <vector>
#define abs(a, b) ( a - b < 0 ? b - a : a - b);
#define max(a, b) ( a < b ? b : a);
using namespace std;

int len, result;
vector<int> path;

/* 트리 탐색 dfs 함수 */
int dfs(int num) {
	/* 현재 노드의 자식이 없을 경우 -> 배열 크기를 넘어감 */
	if (2 * num >= len) {
		/* 현재 위치의 가중치를 더해줌 */
		result += path[num];
		return path[num];
	} 
	/* 자식 노드가 존재할 경우 */
	else {
		/* 자식들의 가중치 합을 가져옴 */
		int left = dfs(2 * num);
		int right = dfs(2 * num + 1);
		/* 
			현재 위치의 가중치를 더해줌(자식들의 차이만큼 추가로 더해줌)
			두 자식까지 가는 크기가 같아야 하기 때문에 최종 가중치에 더함
		*/
		result += path[num] + abs(left, right);
		/* 현재까지 자식으로 가는 가중치는 같으므로 최대값(최소로 맞춰야할 값) 반환 */
		return path[num] + max(left, right);
	}
}

int main() {
	int dep;

	/* 트리의 깊이 입력 */
	cin >> dep;
	/* 깊이에 따른 포화 트리 노드 개수 정의 */
	len = (1 << (dep + 1)) - 1;
	/*
		노드 개수에 따라 트리 배열 정의
		배열 원소의 시작은 1번부터 이므로 한 칸 더 증가시켜 줌
		-> 배열에서 이진 트리를 사용하기 편리하게 하기 위함
	*/
	path = vector<int>(len+1, 0);
	/* 
		트리 간선의 가중치 입력
		간선의 개수는 루트 노드를 제외한 나머지 노드 수와 같으므로
		노드의 가중치로 생각하고 정의해도 됨
	*/
	for (int i = 2; i <= len; i++) cin >> path[i];

	/* 트리 순회 시작 */
	dfs(1);
	/* 트리 가중치합의 최소값 반환 */
	cout << result;
	return 0;
}