#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10 + 2;
char val, in[maxn];
bool In[50];
int main()
{
    int n;
    while(~scanf("%d", &n)){
        stack<char> s;
        memset(in, 0, sizeof(in));
        memset(In, 0, sizeof(In));
        while(!s.empty()) s.pop();
        
        for(int i = 0; i < n; ++i){
            scanf(" %c", &in[i]);
        }
        
        int j = 0, k = 0;
        for(int i = 0; i < n; ++i){
            scanf(" %c", &val);
            
            if(!s.empty() && s.top() == val){
                In[k++] = 0;
                s.pop();
            }else{
                while(j < n && in[j] != val){
                    s.push(in[j]);
                    In[k++] = 1;
                    ++j;
                }
                if(j < n && in[j] == val){
                    In[k++] = 1;
                    In[k++] = 0;
                    ++j;
                }
            }
        }
        if(k == n << 1){
            printf("Yes.\n");
            for(int i = 0; i < k; ++i){
                printf("%s\n", In[i] ? "in" : "out");
            }
        }else{
            printf("No.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}