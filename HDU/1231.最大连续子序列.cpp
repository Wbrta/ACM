#include <cstdio>
using namespace std;
int main()
{
	int k, val;
	while(~scanf("%d", &k) && k){
		bool flag = true;
		int start, final; 
		int sum = 0, tmp = 0, begin = 0, end = 0, tmp_l = 0;
		for(int i = 0; i < k; ++i){
			scanf("%d", &val);
			
			if(i == 0) start = val;
			if(i == k - 1) final = val;
			
			if(val >= 0) flag = false;
			
			if(tmp_l == 0) tmp_l = val;
			tmp += val;
			if(tmp > sum){
				sum = tmp;
				begin = tmp_l;
				end = val;
			}
			
			if(tmp < 0){
				tmp = 0;
				tmp_l = 0;
			}
		}
		
		begin = (flag ? start : begin);
		end = (flag ? final : end);
		printf("%d %d %d\n", sum, begin, end);
	}
	return 0;
}
