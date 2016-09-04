#include <cstdio>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
typedef long long LL;
const int maxn = 100000 + 5;
typedef struct node{
    int l, r;
    LL val;
    LL cnt;
}TREE;
TREE t[maxn << 2];

void pushUp(int rt){
    t[rt].val = t[lson].val + t[rson].val;
}
void pushDown(int rt){
    if(t[rt].cnt){
        t[lson].cnt += t[rt].cnt;
        t[rson].cnt += t[rt].cnt;
        t[lson].val += (t[lson].r - t[lson].l + 1) * t[rt].cnt;
        t[rson].val += (t[rson].r - t[rson].l + 1) * t[rt].cnt;
        t[rt].cnt = 0;
    }
}
void build(int rt, int l, int r){
    t[rt].l = l; t[rt].r = r; t[rt].cnt = 0;
    if(l == r){
        scanf("%lld", &t[rt].val);
        return;
    }

    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushUp(rt);
}
void update(int rt, int l, int r, int val){
    if(t[rt].l >= l && t[rt].r <= r){
        t[rt].cnt += val;
        t[rt].val += (LL)(t[rt].r - t[rt].l + 1) * val;
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
LL query(int rt, int l, int r){
    if(t[rt].l >= l && t[rt].r <= r){
        return t[rt].val;
    }
    pushDown(rt);

    int mid = (t[rt].l + t[rt].r) >> 1;
    LL ret = 0;
    if(l <= mid) ret += query(lson, l, r);
    if(r > mid) ret += query(rson, l, r);
    return ret;
}
int main(){
    char op;
    int n, q, a, b, c;
    while(~scanf("%d%d", &n, &q)){
        build(1, 1, n);
        while(q--){
            scanf(" %c", &op);
            if(op == 'Q'){
                scanf("%d%d", &a, &b);
                printf("%lld\n", query(1, a, b));
            }else if(op == 'C'){
                scanf("%d%d%d", &a, &b, &c);
                update(1, a, b, c);
            }
        }
    }
    return 0;
}
