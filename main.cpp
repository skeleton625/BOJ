#include <cstdio>
#include <map>

/* Ʈ�� ���� ��� ������ �ľ��ϱ� ���� map �ڷ��� */
std::map<int, int> m;
/* ���� pre order, ��� ��ġ �迭 ���� */
int pre[10000], pos[1000000];

void put_post_order(int is, int ie, int ps, int pe) {
	/* ��͸� ���� Ʈ���� ������ ��� ��� ��ȯ */
	if (is > ie || ps > pe) return;

	/* ���� ����� Ű ���� ���� */
	int root = pre[ps];

	/* post order ���� */
	put_post_order(is, pos[root] - 1, ps + 1, ps + pos[root] - is);
	put_post_order(pos[root] + 1, ie, ps + pos[root] - is + 1, pe);
	printf("%d\n", root);
}

int main() {
	int inp = 0, n = 0;

	/* map�� pre order �迭�� pre order �����͸� �Է� */
	while (scanf_s("%d", &inp)) {
		pre[n++] = inp;
		m[inp] = 1;
	}

	/* map�� �Է��ص� ����� ��ġ�� �迭�� �Է����� */
	n = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		pos[it->first] = n++;

	put_post_order(0, n - 1, 0, n - 1);
	return 0;
}