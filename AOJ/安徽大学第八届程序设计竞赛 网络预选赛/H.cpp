#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d", &n)){
		int ans = 2 * n * n;
		ans += 2 * n * (n - 2);
		ans += 2 * (n - 2) * (n - 2);
		
		if(n == 1) printf("1\n");
		else if(n == 2) printf("8\n");
		else printf("%d\n", ans);
	}
	return 0;
}
