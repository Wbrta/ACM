#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
int n, cas = 1;
int pri[maxn], vec[30], vis[30];
//FILE *fout;
void init(){
    for(int i = 0; i < maxn; ++i) pri[i] = i;
    pri[1] = 0;
    for(int i = 2; i < maxn; ++i){
        if(pri[i]){
            for(int j = 2; i * j < maxn; ++j){
                pri[i * j] = 0;
            }
        }
    }
}
void Print(){
    for(int i = 1; i <= n; ++i){
        if(i != 1) printf(" ");
        printf("%d", vec[i]);
    }
    printf("\n");
}
void dfs(int num, int pos){
    vec[pos] = num;
    if(pos == n){
        if(pri[num+1]){
            Print();
        }else{
            return;
        }
    }
    
    for(int i = 2; i <= n; ++i){
        if(vis[i]) continue;
        if(pri[num + i]){
            vis[i] = 1;
            dfs(i, pos + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    init();
    while(~scanf("%d", &n)){
        printf("Case %d:\n", cas++);
        memset(vec, 0, sizeof(vec));
        memset(vis, 0, sizeof(vis));
        
        vis[1] = 1;
        dfs(1, 1);
        puts("");
    }
    return 0;
}