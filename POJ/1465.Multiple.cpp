#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 10;
typedef struct node{
    int pre;
    int mod;
    int digit;
}Queue;

int n, m;
int a[maxn];
int vis[maxn];
Queue q[maxn];

void print(Queue p){
    if(p.pre > -1) print(q[p.pre]);
    printf("%d", p.digit);
}
void bfs(){
    int front = 0, rear = 0;
    for(int i = 0; i < maxn; ++i){
        vis[i] = 0;
        q[i].pre = -1;
        q[i].mod = q[i].digit = 0;
    }
    for(int i = 0; i < m; ++i){
        if(!a[i]) continue;
        if(a[i] % n == 0) {
            printf("%d\n", a[i]);
            return;
        }
        if(!vis[ a[i] % n ]){
            vis[ a[i] % n ] = 1;
            q[rear].mod = a[i] % n;
            q[rear].digit = a[i];
            ++rear;
        }
    }
    
    while(front < rear){
        Queue tmp, p = q[front++];
        
        if(p.mod == 0){
            print(p);
            puts("");
            return;
        }
        
        for(int i = 0; i < m; ++i){
            tmp.mod = (p.mod * 10 + a[i]) % n;
            tmp.digit = a[i];
            tmp.pre = front - 1;
            
            if(!vis[tmp.mod]) {
                vis[tmp.mod] = 1;
                q[rear++] = tmp;
            }
        }
    }
    
    puts("0");
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    while(~scanf("%d", &n)){
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf("%d", &a[i]);
        }
        sort(a, a + m);
        if(n == 0) puts("0");
        else bfs();
    }
    return 0;
}