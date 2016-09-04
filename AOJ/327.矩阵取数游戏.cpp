#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 80 + 3;
int num[maxn][maxn];
int main()
{
	freopen("test.in", "r+", stdin);
	freopen("test.out", "w+", stdout);
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &num[i][j]);
			}
		}

		for(int i = 0; i < m; ++i){

		}
	}
	return 0;
}