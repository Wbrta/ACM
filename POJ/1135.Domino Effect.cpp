#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 500 + 5;
int n, m;
int vis[maxn], dist[maxn], path[maxn][maxn];

void dijkstra(){
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) dist[i] = path[1][i];
    
    vis[1] = 1;
    for(int i = 1; i < n; ++i){
        int k, mi = INF;
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && dist[j] < mi){
                k = j; mi = dist[j];
            }
        }
        vis[k] = 1;
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && dist[k] + path[k][j] < dist[j]){
                dist[j] = dist[k] + path[k][j];
            }
        }
    }
    
    int a, b, c;
    double mx1 = -1, mx2 = -1;
    for(int i = 1; i <= n; ++i){
        if(mx1 < dist[i]) mx1 = dist[i], c = i;
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(path[i][j] == INF) continue;
            
            double tmp = min(dist[i], dist[j]) + path[i][j] - max(dist[i], dist[j]);
            if(tmp > 0){
                tmp /= 2.0;
                if(mx2 < tmp + max(dist[i], dist[j])){
                    mx2 = tmp + max(dist[i], dist[j]);
                    a = min(i, j);
                    b = max(i, j);
                }
            }
        }
    }
    
    if(mx1 < mx2){
        printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", mx2, a, b);
    }else{
        printf("The last domino falls after %.1f seconds, at key domino %d.\n", mx1, c);
    }
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    int cas = 1;
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        if(n == 1){
            printf("System #%d\n", cas++);
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
            continue;
        }
        int a, b, l;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == j) path[i][j] = 0;
                else path[i][j] = INF;
            }
        }
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &a, &b, &l);
            path[a][b] = path[b][a] = l;
        }
        
        printf("System #%d\n", cas++);
        dijkstra();
        puts("");
    }
    return 0;
}