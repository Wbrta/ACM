#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
typedef struct{
	int x, y;
	char val;
}Table;

bool cmp(Table a, Table b){
	if(a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}
int main()
{
	FILE *fin = fopen("Matric.in", "r+");
	FILE *fout = fopen("Matric-Fast.out", "w+");

	int len = 0, cur = 0, lenRow;
	char Matric[maxn][maxn] = {0};
	Table table[maxn * maxn] = {0};
	while(fscanf(fin, " %s", Matric[len]) != EOF){
		lenRow = (len == 0 ? strlen(Matric[0]) : lenRow);
		for(int i = 0; i < lenRow; ++i){
			if(Matric[len][i]){
				table[cur].x = len;
				table[cur].y = i;
				table[cur++].val = Matric[len][i];
			}
		}

		++len;
	}

	sort(table, table + cur, cmp);
	
	memset(Matric, 0, sizeof(Matric));
	for(int i = 0; i < cur; ++i){
		Matric[table[i].y][table[i].x] = table[i].val;
	}
	for(int i = 0; i < lenRow; ++i){
		for(int j = 0; j < len; ++j){
			fprintf(fout, "%c", Matric[i][j]);
		}
		fprintf(fout, "\n");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}