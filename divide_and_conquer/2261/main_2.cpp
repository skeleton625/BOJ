#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
struct point { int x, y; };

/* 비교 구조체 */
struct compare
{
    bool comp_type;
    compare(bool type) : comp_type(type){}
    bool operator()(point& p1, point& p2) { return comp_type ? p1.x < p2.x : p1.y < p2.y; }
};

/* 두 점(p1, p2)의 거리 측정 함수 */
ll dist(point& p1, point& p2)
{
    ll dist_x = p1.x - p2.x;
    ll dist_y = p1.y - p2.y;
    return dist_x * dist_x + dist_y * dist_y;
}

/* 두 점의 최단거리 계산 함수 (분할 정복) */
ll divide_conquer(vector<point>::iterator its, int len)
{
    /* 길이가 2 또는 3 일 경우, 각 점들에 대한 최단거리 값을 계산 */
    if(len == 2) return dist(its[0], its[1]);
    else if(len == 3) return min({dist(its[0], its[1]), dist(its[1], its[2]), dist(its[2], its[0])});

    int len_half = len / 2;
    /* 현재 iterator 중앙을 기준으로 왼쪽, 오른쪽으로 분할해(분할 정복) 최단거리 계산 */
    ll dist_min = min(divide_conquer(its, len_half), divide_conquer(its + len_half, len - len_half));

    /* 현재 iterator의 중앙 x 값을 기준으로 이전에 계산된 최단거리(dist_min) 내의 점들을 추려냄 */
    vector<point> points_mid;
    ll stand_x = (its[len_half - 1].x + its[len_half].x) / 2;
    for(int i = 0; i < len; i++)
    {
        ll dist_x = stand_x - its[i].x;
        if(dist_x * dist_x < dist_min)
            points_mid.push_back(its[i]);
    }

    /* 추려낸 점들은 y 값에 대해 정렬 */
    sort(points_mid.begin(), points_mid.end(), compare(false));

    /* 추려낸 점들을 모두 비교해 가장 가까운 두 점의 최단 거리를 계산 */
    /* 계산되는 각 점들의 y 값 거리에 대해 너무 멀 경우(dist_min과 비교해), 비교할 필요가 없으므로 제외 */
    int mid_size = points_mid.size();
    for(int i = 0; i < mid_size - 1; i++)
    {
        for(int j = i + 1; j < mid_size; j++)
        {
            ll dist_y = points_mid[j].y - points_mid[i].y;
            if(dist_y * dist_y >= dist_min)
                break;
            
            dist_min = min(dist_min, dist(points_mid[i], points_mid[j]));
        }
    }

    return dist_min;
}

int main()
{
    int n;

    /* 점 개수, 점의 좌표 입력 */
    cin >> n;
    vector<point> points_all(n);
    for(int i = 0; i < n; i++)
        cin >> points_all[i].x >> points_all[i].y;

    /* x 값을 기준으로 정렬 후, 분할 정복 진행 */
    sort(points_all.begin(), points_all.end(), compare(true));
    cout << divide_conquer(points_all.begin(), n) << '\n';
    
    system("PAUSE"); 
    return 0;
}