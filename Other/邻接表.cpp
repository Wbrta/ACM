#include <vector>
#include <fstream>
using namespace std;

ifstream fin("邻接表.in");
ofstream fout("邻接表.out");

int main()
{
	int n, m, a, b;
	fin >> n;
	fin >> m;
	vector<int > List[n + 1];
	for(int i = 0; i < m; ++i){
		fin >> a >> b;
		List[a].push_back(b);
	}
	for(int i = 1; i <= n; ++i){
		fout << "第 " << i << " 个点的邻接点有：";
		for(int j = 0; j < List[i].size(); ++j){
			fout << List[i][j] << " ";
		}
		fout << endl;
	}
	return 0;
}
