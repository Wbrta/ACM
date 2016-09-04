#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 5;
int next[maxn];
char w[maxn], t[maxn];

int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n;
	scanf("%d", &n);
	while(n--){
		memset(w, 0, sizeof(w));
		memset(t, 0, sizeof(t));
		memset(next, 0, sizeof(next));

		scanf(" %s", w + 1);
		scanf(" %s", t + 1);

		int len1 = strlen(w + 1);
		int len2 = strlen(t + 1);

		int i = 1, j = 0;
		next[1] = 0;
		while(i <= len1){
			if(j == 0 || w[i] == w[j]){
				++i; ++j;
				next[i] = j;
			}else j = next[j];
		}

		int ans = 0;
		i = 1; j = 1;
		while(i <= len2 && j <= len1){
			if(j == 0 || w[j] == t[i]){
				++i; ++j;
			}else j = next[j];
			if(j == len1 + 1){
				j = next[j];
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
