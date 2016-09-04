#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn = 1e5 + 5;
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
vector<edge> G[maxn];
int dist[maxn], dist2[maxn];

int main()
{
	int r, n, a, b, d;
	scanf("%d%d", &n, &r);
		for(int i = 0; i < n; ++i) G[i].clear();
		for(int i = 0; i < r; ++i){
			scanf("%d%d%d", &a, &b, &d);
			
			a -= 1; b -= 1;
			G[a].push_back(edge(b, d));
			G[b].push_back(edge(a, d));
		}
		
		priority_queue<edge> q;
		while(!q.empty()) q.pop();
		fill(dist, dist + n, INF);
		fill(dist2, dist2 + n, INF);
		dist[0] = 0;
		q.push(edge(0, 0));
		
		while(!q.empty()){
			edge p = q.top();
			q.pop();
			
			if(dist2[p.to] < p.w) continue;
			
			int len = G[p.to].size();
			for(int i = 0; i < len; ++i){
				edge t = G[p.to][i];
				
				int d2 = p.w + t.w;
				if(dist[t.to] > d2){
					dist[t.to] = d2;
					q.push(edge(t.to, dist[t.to]));
				}
				
				if(dist2[t.to] > d2 && dist[t.to] < d2){
					dist2[t.to] = d2;
					q.push(edge(t.to, dist2[t.to]));
				}
			}
		}
		
		printf("%d\n", dist2[n-1]);
	return 0;
}
