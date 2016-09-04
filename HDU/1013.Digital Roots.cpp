#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    str.clear();
    while(cin >> str && str != "0"){
        int len = str.length();
        int sum = 0;
        for(int i = 0; i < len; ++i){
            sum += str[i] - '0';
        }
        
        if(sum < 10){
            cout << sum << endl;
        }else{
            int tmp = sum, ans = 0;
            while(tmp){
                ans += tmp % 10;
                tmp /= 10;
                
                if(tmp == 0){
                    if(ans < 10){
                        cout << ans << endl;
                        break;
                    }else{
                        tmp = ans;
                        ans = 0;
                    }
                }
            }
        }
    }
    return 0;
}