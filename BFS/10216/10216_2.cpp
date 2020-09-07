#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define distance(x1, y1, x2, y2) ( pow(x2 - x1, 2) + pow(y2 - y1, 2) )
#define ll long long

struct tower{ int x, y, r; };

void solve(int t)
{
    int n;
    tower enemy[3000];
    bool connect[3000];

    while(t--)
    {
        cin >> n;
        memset(connect, 0, sizeof(bool) * n);

        for(int i = 0; i < n; i++)
            cin >> enemy[i].x >> enemy[i].y >> enemy[i].r;
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!connect[i])
            {
                connect[i] = true;
                queue<tower> que;
                que.push(enemy[i]);

                while(!que.empty())
                {
                    tower preTower = que.front();
                    que.pop();

                    for(int j = 0; j < n; j++)
                    {
                        if(!connect[j])
                        {
                            ll r = pow(preTower.r + enemy[j].r, 2);
                            if(distance(preTower.x, preTower.y, enemy[j].x, enemy[j].y) <= r)
                            {
                                que.push(enemy[j]);
                                connect[j] = true;
                            }
                        }
                    }
                }
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    cin.tie(0);
    ios::sync_with_stdio(0);

    solve(t);
    return 0;
}