#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int>& a, vector<int>& b)
{
    sort(a.begin(), a.end());

    vector<int>::iterator low, upp;
    for(int i = 0; i < b.size(); i++)
    {
        low = lower_bound(a.begin(), a.end(), b[i]);
        upp = upper_bound(a.begin(), a.end(), b[i]);

        cout << upp - low << ' ';
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b;

    cin >> a;
    vector<int> inp_a = vector<int>(a, 0);
    for(int i = 0; i < a; i++)
        cin >> inp_a[i];

    cin >> b;
    vector<int> inp_b = vector<int>(b, 0);
    for(int i = 0; i < b; i++)
        cin >> inp_b[i];

    solve(inp_a, inp_b);
    return 0;
}