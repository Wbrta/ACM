#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int next[maxn];
char str[maxn], t[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	while(~scanf(" %s", str + 1)){
		if(strcmp(str + 1, "#") == 0) break;
		scanf(" %s", t + 1);

		int len1 = strlen(str + 1);
		int len2 = strlen(t + 1);

		next[1] = 0;
		int i = 1, j = 0;
		while(i <= len2){
			if(j == 0 || t[i] == t[j]){
				++i; ++j;
				next[i] = j;
			}else j = next[j];
		}

		int ans = 0;
		i = 1; j = 1;
		while(i <= len1){
			if(j == 0 || t[j] == str[i]){
				++i; ++j;
			}else j = next[j];

			if(j == len2 + 1){
				j = 1;
				++ans;
			}
		}
		printf("%d\n", ans);

		memset(t, 0, sizeof(t));
		memset(str, 0, sizeof(str));
		memset(next, 0, sizeof(next));
	}
	return 0;
}
