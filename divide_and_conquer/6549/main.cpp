#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ll;
int n;
vector<int> arr, tree;

// ���׸�Ʈ Ʈ�� �ʱ�ȭ �Լ�
void init(int node, int start, int end)
{
	// ���̻� �̵��� �� ���� ��� ���� ��ġ�� Ʈ�� ��忡 ����
	if (start == end)
		tree[node] = start;
	else
	{
		// ���� ������ �߰��� ���� ����� �ڽ�(����, ������) ���� �ʱ�ȭ ����
		int m = (start + end) / 2;
		int l = node * 2;
		int r = node * 2 + 1;
		init(l, start, m);
		init(r, m + 1, end);

		// �ڽ� ���� �� ���̰� ���� ����� ���� �θ� ����� ������ ��
		if (arr[tree[l]] <= arr[tree[r]])
			tree[node] = tree[l];
		else
			tree[node] = tree[r];
	}
}

int query(int node, int start, int end, int left, int right)
{
	// start, end�� ������ ��� ��� -1 ��ȯ
	if (start > right || end < left)
		return -1;
	// start, end�� ������ ����� ���� ��� �ش� ��� ���� ��ȣ�� ��ȯ
	if (start >= left && end <= right)
		return tree[node];

	// ���� �ڽ� ������ ���� ��ȣ�� ��ȯ
	int m = (start + end) / 2;
	int m1 = query(node * 2, start, m, left, right);
	int m2 = query(node * 2 + 1, m + 1, end, left, right);

	// ��, �� ���� �� ������ ����� ������ ���� ���, �ٸ� ������ ���� ��ȯ
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	// �� �� ���� ���� ���, �� ���� ���� ��ȯ
	else
	{
		if (arr[m1] <= arr[m2])
			return m1;
		else
			return m2;
	}
}


// start, end ������ �ִ� ���� ��ȯ �Լ�
ll max_square(int start, int end)
{
	// ���� ������ �ּ� ���̸� ����, ������ ���̸� ����
	int m = query(1, 0, n - 1, start, end);
	ll area = (ll)(end - start + 1) * (ll)arr[m];

	// �ּ� ���� ��ġ m���� ����, ������ ������ ������ ��� ���� �ش� ������ �ִ� ���̸� ����
	// �ִ� ���̸� ���� ��, ���� ���̿� ���� �ִ� ���̸� ��ȯ�ϵ��� ��
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
		// ���� �迭 ����
		arr = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		// ���� �迭 ũ�⿡ ���� ���׸�Ʈ Ʈ�� ����
		h = (int)(ceil(log2(n)) + 1e-9);
		s = (1 << (h + 1));
		tree = vector<int>(s);

		// ���׸�Ʈ Ʈ���� �ʱ�ȭ�� ��, ��ü �������� �ִ� �簢�� ���̸� ����
		init(1, 0, n - 1);
		cout << max_square(0, n - 1) << '\n';
		// �ݺ� ���� �Է�
		cin >> n;
	}

	return 0;
}