#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int t[maxn], k[maxn];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d", &t[i]);
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &k[i]);
		}
	}
	return 0;
}
