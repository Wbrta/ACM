#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 500 + 5;

int cnt;
struct EDGE{
    int to;
    int next;
}edge[maxn << 2];
int head[maxn];
int vertex[maxn];

void toposort(int n){
    priority_queue<int, vector<int>, greater<int> > q;
    while(!q.empty()) q.pop();
    
    for(int i = 1; i <= n; ++i){
        if(vertex[i] == 0){
            q.push(i);
            --vertex[i];
        }
    }
    
    int k = 1;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        
        printf("%d%c", u, k == n ? '\n' : ' '); ++k;
        for(int i = head[u]; i != -1; i = edge[i].next){
            EDGE tmp = edge[i];
            --vertex[tmp.to];
            if(vertex[tmp.to] == 0){
                q.push(tmp.to);
            }
        }
    }
}
int main()
{
    int n, m, x, y;
    while(~scanf("%d%d", &n, &m)){
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(vertex, 0, sizeof(vertex));
        
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
    }
    return 0;
}