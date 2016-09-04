#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		bool flag = false;
		for(int i = -9999; !flag && i < 10000; ++i){
			if(i * (n - i) == m){
				flag = true;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
} 
