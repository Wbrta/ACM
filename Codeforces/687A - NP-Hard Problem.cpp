#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> G[maxn], a, b;
int n, m, flag;
int col[maxn];

bool bfs(int s) {  
    queue<int> p;  
    p.push(s);  
    col[s] = 1;  
    while(!p.empty()) {  
        int from = p.front();  
        p.pop();  
        
        int len = G[from].size();
        for(int i = 0; i < len; ++i) { 
        	int v = G[from][i];
            if(col[v] == -1) {  
                p.push(v);
                col[v] = !col[from];
            }  
            if(col[from] == col[v])
                return false;  
        }  
    }  
    return true;       
}  
int main()
{
	scanf("%d%d", &n, &m);
	a.clear(); b.clear();
	for(int i = 0; i <= n; ++i) G[i].clear();
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	flag = 0;
	memset(col, -1, sizeof(col));
	for(int i = 1; i <= n; i++)
        if(col[i] == -1 && !bfs(i)) {
            flag = true;  
            break;    
        }  
	if(flag){
		puts("-1");
	}else{
		for(int i = 1; i <= n; ++i){
			if(G[i].size() == 0) col[i] = -1;
			if(col[i] == 0){
				a.push_back(i);
			}else if(col[i] == 1){
				b.push_back(i);
			}
		}
		
		int len = a.size();
		printf("%d\n", len);
		for(int i = 0; i < len; ++i){
			if(i) printf(" ");
			printf("%d", a[i]);
		}
		len = b.size();
		printf("\n%d\n", len);
		for(int i = 0; i < len; ++i){
			if(i) printf(" ");
			printf("%d", b[i]);
		}
		puts("");
	}
	return 0;
}
