#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;

const int INF = 0x3f3f3f3f;
const int maxn = 51000;

vector<Edge> vec[maxn];
int vis[maxn], dis[maxn];

int spfa(int s, int e){
    int p, len; Edge nxt;

    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i <= e; ++i){
        vis[i] = 0;
        dis[i] = INF;
    }

    q.push(s); vis[s] = 1; dis[s] = 0;
    while(!q.empty()){
        p = q.front();
        q.pop();

        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            nxt = vec[p][i];
            if(dis[p] + nxt.w < dis[nxt.to]){
                dis[nxt.to] = dis[p] + nxt.w;
                if(!vis[nxt.to]){
                    vis[nxt.to] = 1;
                    q.push(nxt.to);
                }
            }
        }
        vis[p] = 0;
    }
    return -dis[e];
}
int main(){
    int n, a, b, c;
    while(~scanf("%d", &n)){
        int be = INF, en = 0;
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        for(int i = 0; i < n; ++i){
            scanf("%d%d%d", &a, &b, &c);
            vec[a-1].push_back(Edge(b,-c));
            be = min(be, a);
            en = max(en, b);
        }
        for(int i = be - 1; i < en; ++i){
            vec[i].push_back(Edge(i+1, 0));
            vec[i+1].push_back(Edge(i, 1));
        }
        printf("%d\n", spfa(be - 1, en));
    }
    return 0;
}