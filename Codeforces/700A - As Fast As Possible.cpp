#include <cstdio>
using namespace std;
int main(){
    int n, l, v1, v2, k;
    scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
    double tmp = (n + k - 1) / k;
    double ans = (tmp * l) / ((tmp - 1) * v1 + v2);
    printf("%.8f\n", ans);
    return 0;
}
