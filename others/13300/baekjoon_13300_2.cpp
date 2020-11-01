#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int k, vector<pair<int, int>> student)
{
    int* r = new int[student.size()];
    int rn = 0;

    sort(student.begin(), student.end());

    r[0] = 0;
    ++r[0];
    for(int i = 1; i < student.size(); i++)
    {
        if((student[i].first != student[i - 1].first) ||
           (student[i].second != student[i - 1].second) ||
           (r[rn] == k))
            {
                ++rn;
                r[rn] = 0;
            }

        ++r[rn];
    }

    return rn + 1;
}

int main()
{
    int n, k, s, a;
    cin >> n >> k;

    vector<pair<int, int>> student;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> a;
        student.push_back({a, s});
    }

    cout << solve(n, k, student) << '\n';
    cin >> n;
    return 0;
}