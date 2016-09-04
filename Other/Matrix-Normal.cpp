#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100;
int main()
{
	FILE *fin = fopen("Matric.in", "r+");
	FILE *fout = fopen("Matric.out", "w+");

	int len = 0;
	char Matric[maxn][maxn] = {0}; 
	char temp[maxn][maxn] = {0};
	while(fscanf(fin, " %s", Matric[len++]) != EOF);
	int lenRow = strlen(Matric[0]);
	for(int i = 0; i < len; ++i){
		for(int j = 0; j < lenRow; ++j){
			temp[j][i] = Matric[i][j];
		}
	}
	for(int i = 0; i < lenRow; ++i){
		for(int j = 0; j < len; ++j){
			fprintf(fout, "%c", temp[i][j]);
		}
		fprintf(fout, "\n");
	}
	return 0;
}