#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
const int maxn = 1000 + 10;

int path[maxn][maxn];
int n, m, a, b;
bool vis[maxn];
ifstream fin("bfs.in");
ofstream fout("bfs.out");

void bfs(int p){
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(p);
	vis[p] = 1;
	
	while(!q.empty()){
		int now = q.front();
		fout << now << " ";
		q.pop();
		
		for(int i = 1; i <= n; ++i){
			if(path[now][i] && !vis[i]){
				vis[i] = 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	//cout << "请输入有向图的点的个数：";
	fin >> n;
	//cout << "请输入有向图的边的个数："; 
	fin >> m;
	for(int i = 0; i < m; ++i){
		//cout << "请输入第 " << i + 1 << " 条边的信息(从a到b)：";
		fin >> a >> b;
		path[a][b] = 1;
	}
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	bfs(1);
	fout << endl;
	return 0;
}
