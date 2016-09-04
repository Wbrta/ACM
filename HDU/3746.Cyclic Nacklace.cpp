#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int next[maxn];
char str[maxn];
int getNext(int len){
	int i = 1, j = 0;
	while(i <= len){
		if(j == 0 || t[i] == t[j]){
			++i; ++j;
			next[i] = j;
		}else j = next[i];
	}
}
int kmp(){

}
int main()
{
	freopen("test.in", "r+", stdin);
	freopen("test.out", "w+", stdout);

	while(~scanf(" %s", str)){
		
	}
	return 0;
}