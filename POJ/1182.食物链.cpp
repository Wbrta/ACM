#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50000 + 5;
int pre[maxn * 3];

void init(int n){

}

int main()
{
	int n, k, d, x, y;
	while(~scanf("%d%d", &n, &k)){
		int ans = 0;
		init(n);
		while(k--){
			scanf("%d%d%d", &d, &x, &y);
			if(x > n || y > n || x < 1 || y < 1){
				++ans;
				continue;
			}

			if(d == 1){

			}else{

			}
		}
	}
	return 0;
}