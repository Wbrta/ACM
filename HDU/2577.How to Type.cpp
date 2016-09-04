#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int on[maxn], off[maxn];

inline int Min(int x, int y){
	return (x < y ? x : y);
}
int main()
{
	//freopen("test.in", "r+", stdin);
	//freopen("test.out", "w+", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		char str[maxn] = {0};
		scanf(" %s", str);
		int len = strlen(str);

		memset(on, 0, sizeof(on));
		memset(off, 0, sizeof(off));

		on[0] = 1;
		for(int i = 0; i < len; ++i){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				on[i + 1] = Min(on[i] + 1, off[i] + 2);
				off[i + 1] = Min(on[i] + 2, off[i] + 2);
			}else{
				on[i + 1] = Min(on[i] + 2, off[i] + 2);
				off[i + 1] = Min(on[i] + 2, off[i] + 1);
			}
		}
		on[len] += 1;
		printf("%d\n", Min(on[len], off[len]));
	}
	return 0;
}