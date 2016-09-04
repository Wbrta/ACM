#include <cstdio>
using namespace std;
const int maxn = 30000 + 10;
int pre[maxn];
void init(){
    for(int i = 1; i < maxn; ++i) pre[i] = i;
}
int findFather(int x){
    if(pre[x] == x){
        return x;
    }else{
        return pre[x] = findFather(pre[x]);
    }
}
void join(int x, int y){
    int fx = findFather(x);
    int fy = findFather(y);
    if(fx != fy){
        if(fx == 0) pre[fy] = fx;
        else if(fy == 0) pre[fx] = fy;
        else pre[fy] = fx;
    }
}
int main()
{
    int n, m, k, tmp, val;
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        init();
        for(int i = 0; i < m; ++i){
            scanf("%d", &k);
            scanf("%d", &val);
            for(int j = 1; j < k; ++j){
                scanf("%d", &tmp);
                join(val, tmp);
            }
        }
        
        int ans = 1;
        for(int i = 1; i < n; ++i){
            if(findFather(i) == findFather(0)) ++ans;
            //printf("pre[%d] = %d\n", i, pre[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}