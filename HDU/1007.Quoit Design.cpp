//time   memery
//1060ms 4572k
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1e18
const int maxn = 100000 + 10;
typedef struct{
    double x, y;
}Coord;
Coord p[maxn], tmp[maxn];
bool cmp1(Coord a, Coord b){
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
bool cmp2(Coord a, Coord b){
    if(a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}
inline double f(int x){
    return (x > 0 ? x : -x);
}
inline double Min(double a, double b){
    return (a < b ? a : b);
}
inline double Dist(Coord a, Coord b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double Cal_Closest(int left, int right){
    double d = INF;
    
    if(left == right){
        return d;
    }
    if(left + 1 == right){
        return Dist(p[left], p[right]);
    }
    
    int mid = (left + right) >> 1;
    double d1 = Cal_Closest(left, mid);
    double d2 = Cal_Closest(mid + 1, right);
    d = Min(d1, d2);
    
    int k = 0;
    for(int i = left; i <= right; ++i){
        if(f(p[mid].x - p[i].x) <= d){
            tmp[k++] = p[i];
        }
    }
    sort(tmp, tmp + k, cmp2);
    
    for(int i = 0; i < k; ++i){
        for(int j = i + 1; j < k && tmp[j].y - tmp[i].y < d; ++j){
            d = Min(d, Dist(tmp[i], tmp[j]));
        }
    }
    
    return d;
}
int main()
{
    int n;
    while(scanf("%d", &n) && n){
        memset(p, 0, sizeof(p));
        for(int i = 0; i < n; ++i){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        sort(p, p + n, cmp1);
        
        printf("%.2lf\n", Cal_Closest(0, n - 1) / 2);
    }
    return 0;
}