#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 8000 + 5;
int z1[maxn], z2[maxn];
int main()
{
	int a, b, c;
	while(~scanf("%d%d%d", &a, &b, &c)){
		if(a == 0 && b == 0 && c == 0) break;
		int sum = a + 2 * b + 5 * c;
		memset(z1, 0, sizeof(z1));
		memset(z2, 0, sizeof(z2));
		for(int i = 0; i <= a; ++i) z1[i] = 1;
		for(int i = 0; i <= sum; ++i){
			if(z1[i] == 0) continue;
			for(int j = 0; j <= 2 * b; j += 2){
				if(i + j <= sum){
					z2[i + j] += z1[i];
				}
			}
		}
		for(int i = 0; i <= sum; ++i){
			z1[i] = z2[i];
			z2[i] = 0;
		}
		for(int i = 0; i <= sum; ++i){
			for(int j = 0; j <= 5 * c; j += 5){
				if(i + j <= sum){
					z2[i + j] += z1[i];
				}
			}
		}
		for(int i = 0; i <= sum; ++i){
			z1[i] = z2[i];
			z2[i] = 0;
		}
		bool flag = true;
		for(int i = 1; i <= sum; ++i){
			if(!z1[i]){
				printf("%d\n", i);
				flag = false;
				break;
			}
		}
		if(flag) printf("%d\n", sum + 1);
	}
	return 0;
}
