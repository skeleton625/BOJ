#include "iostream"
#include "string"
using namespace std;

int n1, n2;
int **pre_maze;
char **maze;

void find_maze(int x, int y, int path, int count) {
	if (x < 0 || y < 0 || x >= n1 || y >= n2) { return; }
	else if (maze[x][y] == '0') { return; }
	else if (x == n1 - 1 && y == n2 - 1) {
		if (pre_maze[x][y] == -1 || 
			pre_maze[x][y] > count) pre_maze[x][y] = count;
		return;
	}
	else {
		if (pre_maze[x][y] >= 0) {
			if (pre_maze[x][y] > count) pre_maze[x][y] = count;
			else return;
		}
		else pre_maze[x][y] = count;
		if(path != 1) find_maze(x + 1, y, 3, count + 1);
		if(path != 2) find_maze(x, y + 1, 4, count + 1);
		if(path != 3) find_maze(x - 1, y, 1, count + 1);
		if(path != 4) find_maze(x, y - 1, 2, count + 1);
	}
}

void print_maze() {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			cout << pre_maze[i][j] << ' ';
		}
		cout << '\n';
	}
}

void main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n1 >> n2;

	maze = new char*[n1];
	pre_maze = new int*[n1];
	for (int i = 0; i < n1; i++) {
		maze[i] = new char[n2];
		pre_maze[i] = new int[n2];
		memset(pre_maze[i], -1, sizeof(int)*n2);
		cin >> maze[i];
	}

	find_maze(0, 0, 0, 0);
	cout << pre_maze[n1 - 1][n2 - 1] + 1 << '\n';
}