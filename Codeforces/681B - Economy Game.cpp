#include <cstdio>
using namespace std;
int main()
{
	int n, sum, flag = 0;
	scanf("%d", &n);
	int a = n / 1234567;
	int b = n / 123456;
	for(int i = 0; i <= a; ++i){
		for(int j = 0; j <= b; ++j){
			sum = i * 1234567 + j * 123456;
			//printf("i = %d, j = %d, sum = %d\n", i, j, sum);
			if(sum > n) break;
			if((n - sum) % 1234 == 0){
				flag = 1;
				break;
			}
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
