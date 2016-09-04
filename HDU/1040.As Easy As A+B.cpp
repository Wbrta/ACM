#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int num[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
		sort(num, num + n);
		for(int i = 0; i < n; ++i) {
			if(i) printf(" ");
			printf("%d", num[i]);
		}
		puts("");
	}
	return 0;
}