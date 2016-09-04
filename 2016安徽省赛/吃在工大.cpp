#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 5000 + 10;

int k, cnt;
struct EDGE{
    int to;
    int next;
}edge[maxn];
int head[maxn];
int vertex[maxn];
int ans[maxn];

void toposort(int n){
    priority_queue<int> q;
    while(!q.empty()) q.pop();
    
    for(int i = 1; i <= n; ++i){
        if(vertex[i] == 0){
            q.push(i);
            --vertex[i];
        }
    }
    
    k = 1;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        
        //printf("%d: %d\n", k, u);
        ans[k++] = u;
        for(int i = head[u]; i != -1; i = edge[i].next){
            --vertex[edge[i].to];
            if(vertex[edge[i].to] == 0){
                q.push(edge[i].to);
                //--vertex[edge[i].to];
            }
        }
    }
}
int main()
{
    int t, n, m, x, y;
    scanf("%d", &t);
    while(t--){
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(vertex, 0, sizeof(vertex));
        
        scanf("%d%d", &n, &m);
        while(m--){
            int i;
            scanf("%d%d", &x, &y);
            for(i = head[x]; i != -1; i = edge[i].next){
                if(edge[i].to == y){
                    break;
                }
            }
            if(i == -1){
                ++vertex[y];
                edge[cnt].to = y;
                edge[cnt].next = head[x];
                head[x] = cnt++;
            }
        }
        toposort(n);
        if(k == n + 1){
            for(int i = 1; i <= n; ++i){
                if(i != 1) printf(" ");
                printf("%d", ans[i]);
            }
            puts("");
        }else{
            printf("-1\n");
        }
    }
    return 0;
}