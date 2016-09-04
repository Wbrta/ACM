#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000;

void getNext(int *next, char *str){
	int i = 1, j = 0;
	next[1] = 0;
	while(str[i]){
		if(j == 0 || str[i] == str[j]){
			++i; ++j;
			next[i] = j;
		}else j = next[j];
	}
}
int kmp(char *str, char *t, int next[]){
	int i = 1, j = 1, lens = 0, lent = 0;
	
	while(str[i++]) ++lens;
	while(t[j++]) ++lent;

	i = j = 1;
	while(i <= lens && j <= lent){
		if(j == 0 || str[i] == t[j]){
			++i;
			++j;
		}else j = next[j];
	}
	cout << i << " " << j << endl;
	if(i > lens){
		return -1;
	}else{
		return i - lent;
	}
}
int main()
{
	FILE *fin = fopen("kmp.in", "r+");
	FILE *fout = fopen("kmp.out", "w+");

	int next[maxn] = {0};
	char str[maxn] = {0};
	char t[maxn] = {0};

	while(fscanf(fin, " %s", str + 1) != EOF){
		fscanf(fin, " %s", t + 1);
		getNext(next, t);
		
		fprintf(fout, "串 %s 第一次匹配到串 %s 在第 %d 个位置。\n", str, t, kmp(str, t, next));
		memset(next, 0, sizeof(next));
		memset(str, 0, sizeof(str));
		memset(t, 0, sizeof(t));
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}