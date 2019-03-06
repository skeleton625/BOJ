#include <iostream>
#include <vector>
#define abs(a, b) ( a - b < 0 ? b - a : a - b);
#define max(a, b) ( a < b ? b : a);
using namespace std;

int len, result;
vector<int> path;

/* Ʈ�� Ž�� dfs �Լ� */
int dfs(int num) {
	/* ���� ����� �ڽ��� ���� ��� -> �迭 ũ�⸦ �Ѿ */
	if (2 * num >= len) {
		/* ���� ��ġ�� ����ġ�� ������ */
		result += path[num];
		return path[num];
	} 
	/* �ڽ� ��尡 ������ ��� */
	else {
		/* �ڽĵ��� ����ġ ���� ������ */
		int left = dfs(2 * num);
		int right = dfs(2 * num + 1);
		/* 
			���� ��ġ�� ����ġ�� ������(�ڽĵ��� ���̸�ŭ �߰��� ������)
			�� �ڽı��� ���� ũ�Ⱑ ���ƾ� �ϱ� ������ ���� ����ġ�� ����
		*/
		result += path[num] + abs(left, right);
		/* ������� �ڽ����� ���� ����ġ�� �����Ƿ� �ִ밪(�ּҷ� ������� ��) ��ȯ */
		return path[num] + max(left, right);
	}
}

int main() {
	int dep;

	/* Ʈ���� ���� �Է� */
	cin >> dep;
	/* ���̿� ���� ��ȭ Ʈ�� ��� ���� ���� */
	len = (1 << (dep + 1)) - 1;
	/*
		��� ������ ���� Ʈ�� �迭 ����
		�迭 ������ ������ 1������ �̹Ƿ� �� ĭ �� �������� ��
		-> �迭���� ���� Ʈ���� ����ϱ� ���ϰ� �ϱ� ����
	*/
	path = vector<int>(len+1, 0);
	/* 
		Ʈ�� ������ ����ġ �Է�
		������ ������ ��Ʈ ��带 ������ ������ ��� ���� �����Ƿ�
		����� ����ġ�� �����ϰ� �����ص� ��
	*/
	for (int i = 2; i <= len; i++) cin >> path[i];

	/* Ʈ�� ��ȸ ���� */
	dfs(1);
	/* Ʈ�� ����ġ���� �ּҰ� ��ȯ */
	cout << result;
	return 0;
}