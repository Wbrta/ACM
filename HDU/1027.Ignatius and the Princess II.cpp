#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int num[maxn];
int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        int t = 0;
        for(int i = 0; i < n; ++i) num[i] = i + 1;
        do{
            ++t;
            if(t == m) break;
        }while(next_permutation(num, num + n));
        for(int i = 0; i < n; ++i){
            if(i) printf(" ");
            printf("%d", num[i]);
        }
        puts("");
    }
    return 0;
}