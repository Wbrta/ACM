#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
	char str[maxn] = {0};
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; ++i) {
		printf("%c", str[i]);
	}
	for(int i = len - 1; i >= 0; --i) {
		printf("%c", str[i]);
	}
	return 0;
}
