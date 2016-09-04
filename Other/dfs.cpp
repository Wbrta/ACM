#include <cstring>
#include <fstream>
using namespace std;
const int maxn = 1000 + 10;

int path[maxn][maxn];
int n, m, a, b;
bool vis[maxn];
ifstream fin("dfs.in");
ofstream fout("dfs.out");
	
void dfs(int p){
	fout << p << " ";
	for(int i = 1; i <= n; ++i){
		if(path[p][i] && !vis[i]){
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main()
{
	//cout << "����������ͼ�ĵ�ĸ�����";
	fin >> n;
	//cout << "����������ͼ�ıߵĸ�����"; 
	fin >> m;
	for(int i = 0; i < m; ++i){
		//cout << "������� " << i + 1 << " ���ߵ���Ϣ(��a��b)��";
		fin >> a >> b;
		path[a][b] = 1;
	}
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dfs(1);
	fout << endl;
	return 0;
}
