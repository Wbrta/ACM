#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[15];
char str[15];
bool cmp(const char a, const char b){
	return a > b;
}
int main(int argc, char const *argv[])
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n;
	while(~scanf("%d %s", &n, str)){
		if(n == 0 && strcmp(str, "END") == 0) break;
		int len = strlen(str);
		sort(str, str + len, cmp);
		for(int i = 0; i < len; ++i){
			num[i] = str[i] - 'A' + 1;
		}

		int sum, flag = 1;
		for(int a = 0; flag && a < len; ++a){
			for(int b = 0; flag && b < len; ++b){
				if(b == a) continue;
				for(int c = 0; flag && c < len; ++c){
					if(c == b || c == a) continue;
					for(int d = 0; flag && d < len; ++d){
						if(d == c || d == b || d == a) continue;
						for(int e = 0; flag && e < len; ++e){
							if(e == d || e == c || e == b || e == a) continue;
							sum = num[a] - num[b] * num[b] + num[c] * num[c] * num[c] - num[d] * num[d] * num[d] * num[d] + num[e] * num[e] * num[e] * num[e] * num[e];
							if(sum == n){
								flag = 0;
								printf("%c%c%c%c%c\n", str[a], str[b], str[c], str[d], str[e]);
							}
						}
					}
				}
			}
		}
		if(flag){
			printf("no solution\n");
		}
	}
	return 0;
}