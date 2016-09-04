#include <map>
#include <set>
#include <stack> 
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
 
#define mod 1
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Clear(a) memset(a, 0, sizeof(a))
#define Max(a, b) ( (a) > (b) ? (a) : (b) )
#define Min(a, b) ( (a) < (b) ? (a) : (b) )
 
typedef long long LL;
typedef pair<int, int > pi;
 
const int maxn = 1000 + 5;
const int dr[4][2] = {1,0, -1,0, 0,1, 0,-1};
const int di[8][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};

int main()
{
	int t, s, x;
	while(~scanf("%d%d%d", &t, &s, &x)){
		if((x >= t) && ( (x - t) % s == 0 || ( (x - 1 - t) % s == 0 && (x - 1 - t) / s >= 1)) ){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}