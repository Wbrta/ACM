//优先队列 + 邻接矩阵写法O(nlogn)
//time 		memery
//15MS		1688K
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100 + 5;

struct edge{
	int to;
	int w;
	edge(){}
	edge(int a, int b){
		to = a;
		w = b;
	}
	bool operator < (const edge &t) const{
		if(w == t.w)
			return to < t.to;
		else
			return w < t.w;
	}
};

int dis[maxn];
vector<edge> G[maxn];

int main()
{
	int n, m, a, b, c;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; ++i) G[i].clear();
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			
			--a; --b;
			G[a].push_back(edge(b, c));
			G[b].push_back(edge(a, c));
		}
		
		priority_queue<edge> q;
		while(!q.empty()) q.pop();
		q.push(edge(0,0));
		
		for(int i = 0; i < n; ++i) dis[i] = INF;
		dis[0] = 0;
		
		while(!q.empty()){
			edge p = q.top();
			q.pop();
			
			for(int i = 0; i < G[p.to].size(); ++i){
				edge t = G[p.to][i];
				if(p.w + t.w < dis[t.to]){
					dis[t.to] = p.w + t.w;
					q.push(edge(t.to, dis[t.to]));
				}
			}
		}
		
		printf("%d\n", dis[n-1]);
	}
	return 0;
}

/*
//邻接矩阵O(n^2)写法
//time		memery
//15MS		1448K 
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100 + 5;
bool vis[maxn];
int path[maxn][maxn], dis[maxn];
int main()
{
	int n, m, a, b, c;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				path[i][j] = (i == j ? 0 : INF);
			}
		}
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			--a; --b;
			path[a][b] = path[b][a] = c;
		}
		
		memset(dis, 0, sizeof(dis));
		memset(vis, false, sizeof(vis));
		
		vis[0] = true;
		for(int i = 0; i < n; ++i) dis[i] = path[0][i];
		
		int k;
		for(int i = 1; i < n; ++i){
			int mm = INF;
			for(int j = 0; j < n; ++j){
				if(!vis[j] && dis[j] < mm){
					mm = dis[j];
					k = j;
				}
			}
			vis[k] = true;
			for(int j = 0; j < n; ++j){
				if(!vis[j] && dis[k] + path[k][j] < dis[j]){
					dis[j] = dis[k] + path[k][j];
				}
			}
		}
		printf("%d\n", dis[n-1]);
	}
	return 0;
}
*/
