#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
#define pb push_back

const int maxn = 30;

vector<int> ans, tot, vec[maxn];
int in[maxn], vis[maxn], tmp[maxn], cnt;

int toposort(int n){
    priority_queue<int, vector<int>, greater<int> > q;
    while(!q.empty()) q.pop();
    
    for(int i = 0; i < maxn; ++i) tmp[i] = in[i];
    
    int rec = 0;
    for(int i = 0; i < 26; ++i) 
        if(!tmp[i] && vis[i]) {
            q.push(i); 
            ++rec;
        }
    
    if(rec == 1) rec = 0;
    
    while(!q.empty()){
        int p = q.top();
        tot.pb(p); q.pop();
        
        int v, len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            --tmp[v];
            if(!tmp[v]) q.push(v), ++rec;
        }
        
        if(rec == 1) rec = 0;
    }
    
    if( !rec && tot.size() == n) return 1;
    else if( tot.size() == cnt ) return 0;
    else return -1;
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    char a, b;
    int n, m, x, y, res, flag;
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        
        cnt = 0; flag = 0;
        memset(in, 0, sizeof(in));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        
        for(int i = 1; i <= m; ++i) {
            scanf(" %c<%c", &a, &b);
            x = a - 'A';
            y = b - 'A';
            ++in[y];
            
            if(!vis[x]) ++cnt, vis[x] = 1;
            if(!vis[y]) ++cnt, vis[y] = 1;
            vec[x].pb(y);
            
            if(flag == 0){
                tot.clear();
                int k = toposort(n);
                if(k == 1) {
                    ans = tot;
                    flag = 1; res = i;
                }else if(k == -1){
                    flag = -1; res = i;
                }
            }
        }
        
        if(flag == 1){
            printf("Sorted sequence determined after %d relations: ", res);
            for(int i = 0; i < ans.size(); ++i){
                printf("%c", 'A'+ans[i]);
            }
            puts(".");
        }else if(flag == 0){
            printf("Sorted sequence cannot be determined.\n");
        }else{
            printf("Inconsistency found after %d relations.\n", res);
        }
    }
    return 0;
}