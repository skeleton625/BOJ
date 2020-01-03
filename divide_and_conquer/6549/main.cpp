#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ll;
int n;
vector<int> arr, tree;

// 세그멘트 트리 초기화 함수
void init(int node, int start, int end)
{
	// 더이상 이동할 수 없을 경우 현재 위치를 트리 노드에 정의
	if (start == end)
		tree[node] = start;
	else
	{
		// 현재 범위의 중간과 현재 노드의 자식(왼쪽, 오른쪽) 노드로 초기화 진행
		int m = (start + end) / 2;
		int l = node * 2;
		int r = node * 2 + 1;
		init(l, start, m);
		init(r, m + 1, end);

		// 자식 노드들 중 높이가 작은 노드의 값을 부모 노드의 값으로 줌
		if (arr[tree[l]] <= arr[tree[r]])
			tree[node] = tree[l];
		else
			tree[node] = tree[r];
	}
}

int query(int node, int start, int end, int left, int right)
{
	// start, end가 범위를 벗어날 경우 -1 반환
	if (start > right || end < left)
		return -1;
	// start, end가 범위를 벗어나지 않을 경우 해당 노드 높이 번호를 반환
	if (start >= left && end <= right)
		return tree[node];

	// 현재 자식 노드들의 높이 번호를 반환
	int m = (start + end) / 2;
	int m1 = query(node * 2, start, m, left, right);
	int m2 = query(node * 2 + 1, m + 1, end, left, right);

	// 좌, 우 범위 중 범위를 벗어나는 범위가 있을 경우, 다른 범위의 값을 반환
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	// 둘 다 값이 있을 경우, 더 작은 값을 반환
	else
	{
		if (arr[m1] <= arr[m2])
			return m1;
		else
			return m2;
	}
}


// start, end 범위의 최대 넓이 반환 함수
ll max_square(int start, int end)
{
	// 현재 범위의 최소 높이를 구해, 범위의 넓이를 구함
	int m = query(1, 0, n - 1, start, end);
	ll area = (ll)(end - start + 1) * (ll)arr[m];

	// 최소 높이 위치 m에서 왼쪽, 오른쪽 범위가 존재할 경우 각각 해당 범위의 최대 넓이를 구함
	// 최대 넓이를 구한 뒤, 현재 넓이와 비교해 최대 넓이를 반환하도록 함
	if (start <= m - 1)
	{
		ll tmp = max_square(start, m - 1);
		if (tmp > area)
			area = tmp;
	}
	if (m + 1 <= end)
	{
		ll tmp = max_square(m + 1, end);
		if (tmp > area)
			area = tmp;
	}
	return area;
}

int main()
{
	int h, s;
	cin.tie(0);
	
	cin >> n;
	while (n)
	{
		// 높이 배열 정의
		arr = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		// 높이 배열 크기에 따른 세그멘트 트리 정의
		h = (int)(ceil(log2(n)) + 1e-9);
		s = (1 << (h + 1));
		tree = vector<int>(s);

		// 세그먼트 트리를 초기화한 뒤, 전체 영역에서 최대 사각형 넓이를 구함
		init(1, 0, n - 1);
		cout << max_square(0, n - 1) << '\n';
		// 반복 여부 입력
		cin >> n;
	}

	return 0;
}