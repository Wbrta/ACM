#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
double ans = 1;
double CalFactorial(int a){
    if(a == 0) return ans;
    
    ans *= a;
    return ans;
}
int main()
{
    double res = 0;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for(int i = 0; i <= 9; ++i){
        cout << i << " ";
        res += 1 / CalFactorial(i);
        if(i <= 2){
            cout << res << endl;
        }else{
            printf("%.9lf\n", res);
        }
    }
    return 0;
}