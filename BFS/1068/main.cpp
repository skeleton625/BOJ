#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Ʈ���� ��� ����ü ���� */
struct node {
	int par;
	vector<int> chi;
};

/* Ʈ���� ��ȸ�� bfs �˰��� �Լ� */
int bfs(int start, vector<node> &tree) {
	queue<int> que;
	que.push(start); /* ��Ʈ ��� ��ȣ �Է� */

	int cur, cnt = 0;
	/* 
		bfs �˰��� ����
		Ʈ������ �湮�ߴ� ��带 ��湮�� ��찡 �����Ƿ� �湮 üũ�� ���ص� ��
	*/
	while (!que.empty()) {
		cur = que.front(); que.pop();

		/* ���� ����� �ڽ��� �������� ���� ��� ���� ��� */
		if (tree[cur].chi.empty()) {
			cnt++;
			continue;
		}

		/* ����� ��� ��带 ť�� �Է� */
		for (int i = 0; i < tree[cur].chi.size(); i++)
			que.push(tree[cur].chi[i]);
	}

	return cnt;
}

int main() {
	int n, p, d, root;
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* Ʈ���� ��� ���� �Է�, Ʈ�� �迭 ���� */
	cin >> n;
	vector<node> tree(n, { 0, vector<int>(0,0) });
	/* Ʈ���� ���� �Է� */
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == -1) {	/* �Է��� -1�� ��� ���� ��ġ�� ��Ʈ ����� */
			root = i;
		} else {
			/* 
				�θ� ��忡 ���� ��� ��ȣ�� �Է�
				��带 �ڸ��� ���� ����� �θ� ��� ��ȣ�� ���� �Է�
			*/
			tree[i].par = p;
			tree[p].chi.push_back(i);
		}
	}
	/* �ڸ� ��� ��ȣ �Է� */
	cin >> d;

	/* �ڸ� ��尡 ��Ʈ ����� ��� 0�� ��� */
	if (d == root) {
		cout << 0;
	}
	else { 
		/* 
			�׷��� ���� ���
			�ڸ� ��� ��ȣ�� �ش��ϴ� �θ� ��忡��
			����� �ڽĵ� ��, �ڸ� ��� ��ȣ�� ����
		*/
		p = tree[d].par;
		for (int i = 0; i < tree[p].chi.size(); i++) {
			if (tree[p].chi[i] == d) {
				/* vector�� erase�� ���� -> (vector ������ ����) */
				tree[p].chi.erase(tree[p].chi.begin() + i);
				break;
			}
		}

		/* bfs �Լ��� ������ Ʈ���� ��ȸ�ϸ� ���� ��� ������ �ľ� */
		cout << bfs(root, tree);
	}

	return 0;
}