#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxp = 10000;
const int maxn = 100000 + 5;
int pri[maxp], phi[maxn];
bool vis[maxn];

int init(){
	int p = 0;
	for(int i = 0; i < maxn; ++i){
		vis[i] = true;
		phi[i] = i;
	}
	vis[0] = vis[1] = false;
	for(int i = 2; i < maxn; ++i){
		if(vis[i]){
			pri[p++] = i;
			for(int j = 2 * i; j < maxn; j += i){
				vis[j] = false;
			}
		}
	}
	phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (vis[i]) {
            phi[i] = i - 1;
            continue;
        }
        for(int j = 0; j < p && pri[j] * pri[j] <= i; j++) {
            if (i % pri[j] == 0) {
                if (i / pri[j] % pri[j] == 0)
                    phi[i] = pri[j] * phi[i / pri[j]];
                else
                    phi[i] = (pri[j] - 1) * phi[i / pri[j]];
                break;
            }
        }
    }
	return p;
}
int main()
{
	const int pri_num = init();
	int n;
	while(~scanf("%d", &n)){
		int num = 0;
		LL ans = 0;
		for(int i = 0; pri[i] <= n; num = i++){
			int tmp = n / pri[i];
			ans += phi[tmp];
		}
		printf("%lld\n", 2 * ans - 1);
	}
	return 0;
}
