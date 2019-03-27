#include <iostream>
/* ��� �ִ� ���� ���� */
#define NMAX 100001	
/* swap �Լ� ���� */
#define swap(a, b) { int t = a; a = b; b = t; }
using namespace std;

int g, p;			/* ���� ����Ʈ ����, ����� ���� ���� ���� */
int parent[NMAX];	/* ����Ʈ ��ȣ�� ���� ���� ��ŷ ������ ��ȣ �迭 ���� */

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int n1 = find(a), n2 = find(b);

	if (n1 == n2) return;
	/* 
		�ش� �˰��򿡼� ���� Ʈ���� ���̰� 1�̻� �þ ���� ���� ������ 
		Ʈ�� ���̸� ���̴� �˰����� ����
	*/
	parent[n1] = n2;
}

int main() {
	int a, f, cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> g >> p;
	/* ����Ʈ ��ȣ ���� �ʱ�ȭ */
	for (int i = 1; i <= g; i++)
		parent[i] = i;

	/* ������ ����Ⱑ ��ŷ�ϱ� ���ϴ� ����Ʈ ��ȣ �Է� */
	for (int i = 0; i < p; i++) {
		cin >> a;
		/* ���� ����Ⱑ ��ŷ�� �� �ִ� ����Ʈ ��ȣ ã�� */
		f = find(a);
		/* ����Ⱑ ��ŷ�� �� �մ� ����Ʈ�� ���� ��� �˰��� ���� */
		if (0 == f) break;
		else {
			/* 
				���� ����Ⱑ ��ŷ�� �� �ִ� ����Ʈ ��ȣ ���հ� �ٷ� ���� �ִ� ����Ʈ ��ȣ ������ ������
			*/
			merge(f, f - 1);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}