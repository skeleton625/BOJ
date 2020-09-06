#include <iostream>
#include <queue>
using namespace std;
#define vert pair<int, int>

int dir[4][2] = {{-1 , 0}, {1, 0}, {0, -1}, {0, 1}};

int solve(int n, int m, int k)
{
    int x, y;
    bool grid[51][51] = {0,};

    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        grid[x][y] = true;
    }

    queue<vert> que;

    int cnt = 0;
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < m; y++)
        {
            if(grid[x][y])
            {
                que.push({x, y});
                while(!que.empty())
                {
                    vert pv = que.front();
                    que.pop();
                    if(!grid[pv.first][pv.second])
                        continue;
                    grid[pv.first][pv.second] = false;

                    int nx, ny;
                    for(int i = 0; i < 4; i++)
                    {
                        nx = pv.first + dir[i][0],
                        ny = pv.second + dir[i][1];

                        if(nx < 0 || nx >= n ||
                           ny < 0 || ny >= m) continue;

                        que.push({nx, ny});
                    }
                }

                ++cnt;
            }
        }
    }

    return cnt;
}

int main()
{
    int t, n, m, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }

    return 0;
}