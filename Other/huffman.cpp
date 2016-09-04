#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef unsigned int ui;
typedef struct huffman{
	ui w;
	ui fat, lch, rch;
}Hfnode;
typedef char** huffmancode;
int select(Hfnode *hf, int end, int pos){
	ui _min = 0x7fffffff;
	for(int i = 1; i < end; ++i){
		if(hf[i].fat == 0 && hf[i].w < _min){
			_min = hf[i].w;
			pos = i;
		}
	}
	hf[pos].fat = end;
	return pos;
}
Hfnode* init_huffman(Hfnode *hf, int n, int w[]){
	hf = new Hfnode[2 * n];
	if(hf == NULL){
		cout << "�ڴ����ʧ�ܣ���������ԣ�" << endl;
		exit(-1);
	}
	int m = 2 * n - 1;
	for(int i = 1; i <= n; ++i){
		//system("pause");
		hf[i].w = w[i-1];
		hf[i].fat = hf[i].lch = hf[i].rch =  0;
	}
	for(int i = n + 1; i <= m; ++i){
		hf[i].w = hf[i].fat = hf[i].lch = hf[i].rch =  0;
	}
	for(int i = n + 1; i <= m; ++i){
		int s1 = select(hf, i, -1);
		int s2 = select(hf, i, -1);
		hf[i].w = hf[s1].w + hf[s2].w;
		hf[s1].fat = hf[s2].fat = i;
		hf[i].lch = s1;
		hf[i].rch = s2;
	}
	return hf;
}
huffmancode huffmanCode(Hfnode *hf, int n, huffmancode hmc){
	hmc = (huffmancode)malloc((n + 1) * sizeof(char *));
	char * cd = (char *)malloc(n * sizeof(char));
	cd[n-1] = '\0';
	for(int i = 1; i <= n; ++i){
		int start = n - 1;
		for(int c = i, f = hf[i].fat; f; c = f, f = hf[f].fat){
			if(hf[f].lch == c) cd[--start] = '0';
			else cd[--start] = '1';
		}

		hmc[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(hmc[i], &cd[start]);
	}
	free(cd);
	return hmc;
}
void huffmandecoding(int n, string code, Hfnode* hf, huffmancode hmc){
	int pos = 2 * n - 1;
	int len = code.length();
	for(int i = 0; i < len; ++i){
		if(code.at(i) == '0'){
			pos = hf[pos].lch;
		}else{
			pos = hf[pos].rch;
		}
	}
	
	if(pos <= n && pos >= 1){
		cout << "�������huffman���������Ϊ��" << hf[pos].w << endl;
	}else{
		cout << "�ܱ�Ǹ���������huffman���벻�Ϸ�����������ԣ�" << endl;
	}
}
int main()
{
	int w[6] = {8, 5, 2, 9, 6, 7};
	Hfnode *hf = NULL;
	hf = init_huffman(hf, 6, w);
	printf("  Ȩֵ ���ڵ� ���� �Һ���\n");
	for(int i = 1; i < 12; ++i){
		printf("%5d%7d%7d%7d\n", hf[i].w, hf[i].fat, hf[i].lch, hf[i].rch);
	}
	cout << "*****************************" << endl;
	huffmancode hmc = NULL;
	hmc = huffmanCode(hf, 6, hmc);
	for(int i = 1; i <= 6; ++i){
		cout << "ȨֵΪ��" << w[i-1] << "������huffman����Ϊ" << hmc[i] << endl;
	}
	cout << "*****************************" << endl;
	cout << "����������Ҫ���huffman����: ";
	string code;
	cin >> code;
	huffmandecoding(6, code, hf, hmc);
	return 0;
}