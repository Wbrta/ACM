#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 10;
int l, m, n, a[maxn];

bool judge(int mid){
    int dis = 0, cnt = 0;
    for(int i = 0; i <= n; ++i){
        dis += a[i+1] - a[i];
        if(dis <= mid) {
            ++cnt;
        }else dis = 0;
    }
    if(cnt > m) return false;
    else return true;
}
int main(){
    while(~scanf("%d%d%d", &l, &n, &m)){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        a[0] = 0; a[n+1] = l;
        sort(a, a + n + 2);
        int mid, low = 0, high = l;

        while(low <= high){
            mid = (low + high) >> 1;
            if(judge(mid)) low = mid + 1;
            else high = mid - 1;
        }
        printf("%d\n", low);
    }
    return 0;
}