 // cnt是计数排序的辅助数组，k是第一关键字，id是第二关键字下标数组，r是以下标为第二关键字的新构数组，
 // w存放的是字符串信息。sa保存的是排第i的是谁，
 // #define rep(i,n) for(int i = 0;i < n; i++) ，
int *k = rk,*id = height,*r = res, *cnt = wa;//计数排序
rep(i,up) cnt[i] = 0;
rep(i,len) cnt[k[i] = w[i]]++;
rep(i,up) cnt[i+1] += cnt[i];
for(int i = len - 1; i >= 0; i--) {
	sa[--cnt[k[i]]] = i;
}