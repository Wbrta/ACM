#include <cstdio>
#include <cstring>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)

const int maxn = 1e5 + 5;
typedef struct node{
    int l, r;
    int val;
    int cnt;
}TREE;
TREE t[maxn << 2];

void pushUp(int rt){
    t[rt].val = t[lson].val + t[rson].val;
}
void pushDown(int rt){
    if(t[rt].cnt){
        t[lson].cnt = t[rson].cnt = t[rt].cnt;
        t[lson].val = (t[lson].r - t[lson].l + 1) * t[rt].cnt;
        t[rson].val = (t[rson].r - t[rson].l + 1) * t[rt].cnt;
        t[rt].cnt = 0;
    }
}
void build(int rt, int l, int r){
    t[rt].l = l; t[rt].r = r;
    t[rt].cnt = 0;
    if(l == r){
        t[rt].val = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushUp(rt);
}
void update(int rt, int l, int r, int val){
    if(t[rt].l >= l && t[rt].r <= r){
        t[rt].val = (t[rt].r - t[rt].l + 1) * val;
        t[rt].cnt = val;
        return;
    }
    pushDown(rt);
    int mid = (t[rt].l + t[rt].r) >> 1;

    if(l <= mid)
        update(lson, l, r, val);
    if(r > mid)
        update(rson, l, r, val);
    pushUp(rt);
}
int main(){
    int tt, n, q, x, y, z;
    scanf("%d", &tt);
    for(int cas = 1; cas <= tt; ++cas){
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &q);
        while(q--){
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", cas, t[1].val);
    }
    return 0;
}
