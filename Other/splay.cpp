#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define INF 0x3f3f3f3f
#define MAXN 100005

using namespace std;

int cnt=1, rt=0;

struct Tree
{
    int key, size, fa, son[2], num;
    void set(int _key, int _size, int _fa, int _num)
    {
        key=_key;
        size=_size;
        fa=_fa;
        son[0]=son[1]=0;
        num=_num;
    }
}T[MAXN];

inline void PushUp(int x)
{
    T[x].size=T[T[x].son[0]].size+T[T[x].son[1]].size+1;
}

inline void Rotate(int x, int p) //0左旋 1右旋
{
    int y=T[x].fa;
    T[y].son[!p]=T[x].son[p];
    T[T[x].son[p]].fa=y;
    T[x].fa=T[y].fa;
    if(T[x].fa)
        T[T[x].fa].son[T[T[x].fa].son[1] == y]=x;
    T[x].son[p]=y;
    T[y].fa=x;
    PushUp(y);
    PushUp(x);
}

void Splay(int x, int To) //将x节点插入到To的子节点中
{
    while(T[x].fa != To)
    {
        if(T[T[x].fa].fa == To)
            Rotate(x, T[T[x].fa].son[0] == x);
        else
        {
            int y=T[x].fa, z=T[y].fa;
            int p=(T[z].son[0] == y);
            if(T[y].son[p] == x)
                Rotate(x, !p), Rotate(x, p); //之字旋
            else
                Rotate(y, p), Rotate(x, p);    //一字旋
        }
    }
    if(To == 0) rt=x;
}

int find(int key) //返回值为key的节点 若无返回0 若有将其转移到根处
{
    int x=rt;
    while(x && T[x].key != key)
        x=T[x].son[key > T[x].key];
    if(x) Splay(x, 0);
    return x;
}

int prev() //返回比根值小的最大值 若无返回0 若有将其转移到根处
{
    int x=T[rt].son[0];
    if(!x) return 0;
    while(T[x].son[1])
        x=T[x].son[1];
    Splay(x, 0);
    return x;
}

int succ() //返回比根值大的最小值 若无返回0 若有将其转移到根处
{
    int x=T[rt].son[1];
    if(!x) return 0;
    while(T[x].son[0])
        x=T[x].son[0];
    Splay(x, 0);
    return x;
}

void Insert(int key, int num) //插入key 并且将该节点转移到根处
{
    if(!rt)
        T[rt = cnt++].set(key, 1, 0, num);
    else
    {
        int x=rt, y=0;
        while(x)
        {
            y=x;
            x=T[x].son[key > T[x].key];
        }
        T[x = cnt++].set(key, 1, y, num);
        T[y].son[key > T[y].key]=x;
        Splay(x, 0);
    }
}

void Delete(int key) //删除值为key的节点 若有重点只删其中一个 x的前驱移动到根处
{
    int x=find(key);
    if(!x) return;
    int y=T[x].son[0];
    while(T[y].son[1])
        y=T[y].son[1];
    int z=T[x].son[1];
    while(T[z].son[0])
        z=T[z].son[0];
    if(!y && !z)
    {
        rt=0;
        return;
    }
    if(!y)
    {
        Splay(z, 0);
        T[z].son[0]=0;
        PushUp(z);
        return;
    }
    if(!z)
    {
        Splay(y, 0);
        T[y].son[1]=0;
        PushUp(y);
        return;
    }
    Splay(y, 0);
    Splay(z, y);
    T[z].son[0]=0;
    PushUp(z);
    PushUp(y);
}

int GetPth(int p) //获得第p小的节点 并将其转移到根处
{
    if(!rt) return 0;
    int x=rt, ret=0;
    while(x)
    {
        if(p == T[T[x].son[0]].size+1)
            break;
        if(p>T[T[x].son[0]].size+1)
        {
            p-=T[T[x].son[0]].size+1;
            x=T[x].son[1];
        }
        else
            x=T[x].son[0];
    }
    Splay(x, 0);
    return x;
}

int main ()
{
    int p, key, num, x;
    while(scanf("%d", &p) && p)
    {
        switch (p)
        {
            case 1:
                scanf("%d%d", &num, &key);
                Insert(key, num);
                break;
            case 2:
                x=GetPth(T[rt].size);
                if(x)
                {
                    printf("%d\n",T[x].num);
                    Delete(T[x].key);
                }
                else
                    printf("0\n");
                break;
            case 3:
                x=GetPth(1);
                if(x)
                {
                    printf("%d\n",T[x].num);
                    Delete(T[x].key);
                }
                else
                    printf("0\n");
        }
    }
    return 0;
}