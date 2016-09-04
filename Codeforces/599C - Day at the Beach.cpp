#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, tmp;
    vector<int> vec;
    vec.clear();
    scanf("%d", &n);
    vec.push_back(-1);
    for(int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        int v = (tmp > vec.back() ? tmp : vec.back());
        while(vec.back() > tmp) vec.pop_back();
        vec.push_back(v);
    }
    int ans = vec.size();
    printf("%d\n", ans - 1);
    return 0;
}