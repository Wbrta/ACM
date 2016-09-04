#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1001 + 5;
int x[maxn], y[maxn];
int main()
{
	freopen("test.in", "r+", stdin);
	freopen("test.out", "w+", stdout);
	char op;
	int n, d, p, q;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
	}
	while(~scanf(" %c", op)){
		if(op == 'O'){
			scanf("%d", &p);
			
		}else if(op == 'S'){
			scanf("%d%d", &p, &q);
		}
	}
	return 0;
}