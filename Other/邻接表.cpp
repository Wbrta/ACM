#include <vector>
#include <fstream>
using namespace std;

ifstream fin("�ڽӱ�.in");
ofstream fout("�ڽӱ�.out");

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
		fout << "�� " << i << " ������ڽӵ��У�";
		for(int j = 0; j < List[i].size(); ++j){
			fout << List[i][j] << " ";
		}
		fout << endl;
	}
	return 0;
}
