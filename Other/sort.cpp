#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000;
int num[maxn];
FILE *fin = fopen("insertSort.in", "r+");
FILE *fout = fopen("insertSort.out", "w+");
void insertSort(int len){
	for(int i = 1; i < len; ++i){
		int tmp = num[i], j;
		for(j = i - 1; j >= 0; --j){
			if(num[j] > tmp){
				num[j + 1] = num[j];
			}else break;
		}
		num[j + 1] = tmp;
		
		for(int i = 0; i < len; ++i){
			fprintf(fout, "%d ", num[i]);
		}
		fprintf(fout, "\n");
	}
}
int main()
{
	int len = 0;
	while(fscanf(fin, "%d", &num[len]) != EOF) ++len;
	fprintf(fout, "排序前：\n");
	for(int i = 0; i < len; ++i){
		fprintf(fout, "%d ", num[i]);
	}
	fprintf(fout, "\n\n");
	insertSort(len);
	//sort(num, num + len);
	fprintf(fout, "排序后：\n");
	for(int i = 0; i < len; ++i){
		fprintf(fout, "%d ", num[i]);
	}
	fprintf(fout, "\n");
	return 0;
}
