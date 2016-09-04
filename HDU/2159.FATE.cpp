#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int a[maxn], b[maxn], c[maxn];
int dpn[maxn], dpm[maxn];
int main()
{
	int N, M, K, S;
	while(~scanf("%d%d%d%d", &N, &M, &K, &S)){
		for(int i = 0; i < K; ++i){
			scanf("%d%d", &a[i], &b[i]);
			c[i] = M / b[i];
		}
		
		memset(dpn, 0, sizeof(dpn));
		memset(dpm, 0, sizeof(dpm));

		for(int i = 0; i < K; ++i){
			int t = 1;
			while(c[i]){
				if(c[i] < t){
					t = c[i];
				}
				c[i] -= t;
				
				for(int j = M; j >= t * b[i]; --j){
					if( dpn[j] < ( dpn[j - t * b[i]] + t * a[i] ) ){
						dpn[j] = dpn[j - t * b[i]] + t * a[i];
						dpm[j] = dpm[j - t * b[i]] + t;
					}
				}
				t <<= 1;
			}
		}

		if(dpn[M] < N){
			puts("-1");
		}else{
			bool flag = 1;
			for(int i = 0; i <= M; ++i){
				if(dpn[i] >= N && dpm[i] <= S){
					printf("%d\n", M - i);
					flag = 0;
					break;
				}
			}
			if(flag) puts("-1");
		}
	}
	return 0;
}
