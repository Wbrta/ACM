#include <cstdio>
#include <cstring>
using namespace std;
#define Max(a, b) ((a) > (b) ? (a) : (b))
const int maxn = 1e5 + 5;
int n, m, a[maxn];
bool Judge(int mid){
    int sum = 0, cnt = 1;
    for(int i = 0; i < n; ++i){
        if(sum + a[i] <= mid){
            sum += a[i];
        }else{
            sum = a[i];
            ++cnt;
        }
    }
    
    if(cnt > m) return false;
    else return true;
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        int mid, high = 0, low = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            high += a[i];
            low = Max(low, a[i]);
        }
        
        while(low <= high){
            mid = (low + high) >> 1;
            if(Judge(mid)) high = mid - 1;
            else low = mid + 1;
        }
        printf("%d\n", mid);
    }
    return 0;
}