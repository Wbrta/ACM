#include <cstdio>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
	while(b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	LL n, k, c, lcm = 1;
	scanf("%I64d%I64d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%I64d", &c);
		
		lcm = (c * lcm) / gcd(lcm, c);
		lcm %= k;
	}
	if(lcm == 0) printf("Yes\n");
	else printf("No\n");
	return 0;
}
