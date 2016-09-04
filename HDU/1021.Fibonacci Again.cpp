#include <iostream>
using namespace std;
const int maxn = 1000000 + 5;
int fib[maxn];
void init(){
    fib[0] = 7 % 3;
    fib[1] = 11 % 3;
    for(int i = 2; i < maxn; ++i){
        fib[i] = (fib[i-1] + fib[i-2]) % 3;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    init();
    while(cin >> n){
        if(fib[n] % 3 == 0){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}