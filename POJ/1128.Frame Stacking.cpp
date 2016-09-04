#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

typedef struct node{
    int up, down, left, right;
}Range;
const int maxn = 30;

int tol, h, w;
Range r[maxn];
vector<int> vec[maxn], pre[maxn][maxn];
char aa[maxn], m[maxn][maxn], ans[maxn];
int vis[maxn], tmp[maxn], pat[maxn][maxn];

bool judge(int len){
    int v, k;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i <= len; ++i){
        k = vec[ ans[i] - 'A' ].size();
        for(int j = 0; j < k; ++j){
            v = vec[ ans[i] - 'A' ][j];
            ++tmp[v];
        }
        for(int j = i + 1; j <= len; ++j){
            if(tmp[ ans[j] - 'A' ]) return false;
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
void init(){
    int v, val, len;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(m[i][j] >= 'A' && m[i][j] <= 'Z'){
                val = m[i][j] - 'A';
                if(!vis[val]){
                    vis[val] = 1;
                    aa[tol++] = m[i][j];
                    r[val].up = i; r[val].left = j;
                    r[val].down = i; r[val].right = j;
                }else{
                    r[val].left = min(r[val].left, j);
                    r[val].down = max(r[val].down, i);
                    r[val].right = max(r[val].right, j);
                }
            }
        }
    }
    for(int i = 0; i < maxn; ++i){
        for(int j = 0; j < maxn; ++j)
            pre[i][j].clear();
    }
    for(int i = 0; i < tol; ++i){
        val = aa[i] - 'A';
        
        int a = r[val].left, b = r[val].right, c = r[val].up, d = r[val].down;
        for(int j = a; j <= b; ++j){
            pre[c][j].push_back(val);
            pre[d][j].push_back(val);
        }
        for(int j = c + 1; j < d; ++j){
            pre[j][a].push_back(val);
            pre[j][b].push_back(val);
        }
    }
    
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(m[i][j] >= 'A' && m[i][j] <= 'Z'){
                val = m[i][j] - 'A';
                len = pre[i][j].size();
                for(int k = 0; k < len; ++k){
                    v = pre[i][j][k];
                    if(val != v && !pat[val][v]){
                        pat[val][v] = 1;
                        vec[val].push_back(v);
                    }
                }
            }
        }
    }
    sort(aa, aa + tol);
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d", &h)){
        scanf("%d", &w);
        
        memset(m, 0, sizeof(m));
        memset(r, 0, sizeof(r));
        memset(aa, 0, sizeof(aa));
        memset(vis, 0, sizeof(vis));
        memset(pat, 0, sizeof(pat));
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                scanf(" %c", &m[i][j]);
            }
        }
        
        tol = 0;
        init();
        for(int i = 0; i < tol; ++i){
            memset(vis, 0, sizeof(vis));
            memset(ans, 0, sizeof(ans));
            vis[i] = 1;
            dfs(i, 0);
        }
    }
    return 0;
}