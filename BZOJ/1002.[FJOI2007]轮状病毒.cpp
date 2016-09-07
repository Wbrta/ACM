#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef struct node {
    string num;
    void init(int val) {
        while (val) {
            num.push_back(val % 10 + '0');
            val /= 10;
        }
    }
    node operator * (int b) const {
        node a;
        int len = num.length();
        a.num.resize(len + 15, '0');
        for (int i = 0; i < len; ++i) {
            a.num[i] += (num[i] - '0') * b;
            a.num[i + 1] += (a.num[i] - '0') / 10;
            a.num[i] = (a.num[i] - '0') % 10 + '0';
        }
        return a;
    }
    node operator + (int b) const {
        node a; a.num = num;
        int len = num.length();
        a.num[0] += b; a.num.resize(len + 1, '0');
        for (int i = 0; i < len; ++i) {
            if (a.num[i] > '9') {
                a.num[i] -= 10;
                a.num[i + 1] += 1;
            }
        }
        return a;
    }
    node operator + (node b) const {
        node a; a.num = num;
        int len = b.num.length();
        if (len > (int)num.length()) a.num.resize(len + 1, '0');
        for (int i = 0; i < len; ++i) {
            a.num[i] = a.num[i] + b.num[i] - '0';
            if (a.num[i] > '9') {
                a.num[i] -= 10;
                a.num[i + 1] += 1;
            }
        }
        return a;
    }
    node operator - (node b) const {
        node a; a.num = num;
        int len = b.num.length();
        for (int i = 0; i < len; ++i) {
            if (num[i] > b.num[i]) a.num[i] = a.num[i] - b.num[i] + '0';
            else {
                a.num[i] = a.num[i] + 10 - (b.num[i] - '0');
                a.num[i+1] -= 1;
            }
        }
        return a;
    }
    void print() {
        int i, len = num.length();
        for (i = len - 1; num[i] == '0'; --i);
        while(i>= 0) {
            printf("%c", num[i]);
            --i;
        }
        puts("");
    }
}BigInteger;
 
BigInteger f[105];
int main() {
    f[1].init(1); f[2].init(5);
    for (int i = 3; i <= 100; ++i) {
        f[i] = f[i - 1] * 3 - f[i - 2] + 2;
    }
    int n;
    while (~scanf("%d", &n)) f[n].print();
    return 0;
}