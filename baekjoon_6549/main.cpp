#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
int nsize;

void init(vector<int> &arr, vector<int> &tree, int index, int start, int end) {
	if (start == end)
		tree[index] = start;
	else {
		int mid = (start + end) / 2;
		init(arr, tree, index * 2, start, mid);
		init(arr, tree, index * 2 + 1, mid + 1, end);
		if (arr[tree[index * 2]] <= arr[tree[index * 2 + 1]])
			tree[index] = tree[index * 2];
		else
			tree[index] = tree[index * 2 + 1];
	}
}

int query(vector<int> &arr, vector<int> &tree, int index, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return -1;
	}
	if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		int m1 = query(arr, tree, index * 2, start, mid, left, right);
		int m2 = query(arr, tree, index * 2 + 1, mid + 1, end, left, right);
		
		if (m1 == -1) {
			return m2;
		} else if (m2 == -1) {
			return m1;
		} else {
			if (arr[m1] <= arr[m2]) {
				return m1;
			}
			else
				return m2;
		}
	}
}

unsigned long long getMax(vector<int> &arr, vector<int> &tree, int start, int end) {
	int min_pos = query(arr, tree, 1, 0, nsize - 1, start, end);
	ll pre_max = (ll)arr[min_pos] * (ll)(end - start + 1);

	if (start <= min_pos - 1) {
		ll left = getMax(arr, tree, start, min_pos - 1);
		if (pre_max < left) pre_max = left;
	}
	if (min_pos + 1 <= end) {
		ll right = getMax(arr, tree, min_pos + 1, end);
		if (pre_max < right) pre_max = right;
	}
	return pre_max;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (1) {
		cin >> nsize;
		if (nsize == 0) break;
		int h = ceil(log2(nsize));
		vector<int> n(nsize);
		vector<int> tree(1 << (h + 1));
		for (int i = 0; i < nsize; i++)
			cin >> n[i];
		init(n, tree, 1, 0, nsize - 1);
		cout << getMax(n, tree, 0, nsize - 1) << '\n';
	}
	return 0;
}