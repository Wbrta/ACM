#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10000 + 5;
const int INF = 0x3f3f3f3f;

typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;

vector<Edge> vec[maxn];
int dis[maxn], vis[maxn];

int spfa(int n){
    Edge v;
    int len, p;
    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i <= n; ++i){
        vis[i] = 0;
        dis[i] = INF;
    }
    dis[0] = 0;
    vis[0] = 1;
    q.push(0);

    while(!q.empty()){
        p = q.front(); q.pop();
        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            if(dis[v.to] > dis[p] + v.w){
                dis[v.to] = dis[p] + v.w;
                if(!vis[v.to]){
                    vis[v.to] = 1;
                    q.push(v.to);
                }
            }
        }
        vis[p] = 0;
    }

    return -dis[n];
}
int main(){
    int n, a, b;
    while(~scanf("%d", &n)){
        int e = 0;
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &a, &b);
            e = (e < b ? b : e);
            vec[a].push_back(Edge(b+1, -2));
        }
        for(int i = 0; i <= e; ++i){
            vec[i].push_back(Edge(i+1, 0));
            vec[i+1].push_back(Edge(i, 1));
        }
        printf("%d\n", spfa(e + 1));
    }
    return 0;
}