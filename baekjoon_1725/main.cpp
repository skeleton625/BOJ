#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ll;
int n;

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
	} else if (left <= start && end <= right) {
		return tree[index];
	}

	int mid = (start + end) / 2;
	int m1 = query(arr, tree, index * 2, start, mid, left, right);
	int m2 = query(arr, tree, index * 2 + 1, mid + 1, end, left, right);
	if (m1 == -1) {
		return m2;
	} else if (m2 == -1) {
		return m1;
	} else if (arr[m1] <= arr[m2]) {
		return m1;
	} else {
		return m2;
	}
}

ll getMax(vector<int> &arr, vector<int> &tree, int start, int end) {
	if (start == end) {
		return arr[start];
	} else {
		int min_pos = query(arr, tree, 1, 0, n - 1, start, end);
		ll mh = (ll)(arr[min_pos])*(ll)(end - start + 1);
		if (start <= min_pos - 1) {
			ll left = getMax(arr, tree, start, min_pos - 1);
			if (left > mh)
				mh = left;
		}
		if (min_pos + 1 <= end) {
			ll right = getMax(arr, tree, min_pos + 1, end);
			if (right > mh)
				mh = right;
		}
		return mh;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int hsize = ceil(log2(n));
	vector<int> h(n);
	vector<int> tree(1 << (hsize + 1));
	for (int i = 0; i < n; i++) cin >> h[i];

	init(h, tree, 1, 0, n - 1);
	cout << getMax(h, tree, 0, n - 1);

	return 0;
}