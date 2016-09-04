#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int maxn = 200 + 5;

int res[maxn];
int n, m, in[maxn];
int vis[maxn][maxn];
vector<int> ans, vec[maxn];

bool toposort(){
    int p, v, len;
    
    priority_queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; ++i){
        if(!in[i]) q.push(i);
    }
    
    while(!q.empty()){
        p = q.top();
        ans.push_back(p);
        q.pop();
        
        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            --in[v];
            if(!in[v]) q.push(v);
        }
    }
    
    if(ans.size() == n) return true;
    else return false;
}
int main()
{
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        
        memset(in, 0, sizeof(in));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i <= n; ++i) vec[i].clear();
        
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &a, &b);
            if(!vis[b][a]){
                vec[b].push_back(a);
                vis[b][a] = 1;
                ++in[a];
            }
        }
        
        ans.clear();
        if(toposort()) {
            int len = ans.size();
            for(int i = 0, j = n; i < len; ++i, --j){
                res[ans[i]] = j;
            }
            for(int i = 1; i <= n; ++i){
                printf("%d%c", res[i], (i == n ? '\n' : ' '));
            }
        }else puts("-1");
    }
    return 0;
}