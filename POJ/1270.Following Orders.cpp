#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30;
const int maxs = 200;

int tol;
vector<int> vec[maxn];
int vis[maxn], tmp[maxn];
char aa[maxn], ans[maxn];

bool judge(int len){
    int v, k;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i <= len; ++i){
        k = vec[ ans[i] - 'a' ].size();
        for(int j = 0; j < k; ++j){
            v = vec[ ans[i] - 'a' ][j];
            ++tmp[v];
        }
        for(int j = i + 1; j <= len; ++j){
            if(tmp[ ans[j] - 'a' ]) return false;
        }
    }
    return true;
}
void dfs(int p, int num){
    ans[num] = aa[p];
    //printf("len = %d, ans = %s\n", num, ans);
    if(!judge(num)) return;
    if(num == tol - 1) {
        puts(ans);
        return;
    }
    
    for(int i = 0; i < tol; ++i){
        if(vis[i]) continue;
        vis[i] = 1; 
        dfs(i, num + 1);
        vis[i] = 0;
    }
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    int cas = 0, cnt, len;
    char str[maxs] = {0};
    while(fgets(str, maxs, stdin) != NULL){
        tol = 0;
        len = strlen(str);
        memset(aa, 0, sizeof(aa));
        for(int i = 0; i < len; ++i){
            if(str[i] >= 'a' && str[i] <= 'z')
                aa[tol++] = str[i];
        }
        
        memset(str, 0, sizeof(str));
        fgets(str, maxs, stdin);
        
        cnt = 0;
        len = strlen(str);
        int a, b;
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        for(int i = 0; i < len; ++i){
            if(str[i] >= 'a' && str[i] <= 'z'){
                cnt = (cnt + 1) % 2;
                if(cnt) a = str[i] - 'a';
                else {
                    b = str[i] - 'a';
                    vec[b].push_back(a);
                }
            }
        }
        
        memset(str, 0, sizeof(str));
        sort(aa, aa + tol);
        //puts(aa);
        
        if(cas++) puts("");
        for(int i = 0; i < tol; ++i){
            memset(ans, 0, sizeof(ans));
            memset(vis, 0, sizeof(vis));
            vis[i] = 1;
            dfs(i, 0);
        }
    }
    return 0;
}