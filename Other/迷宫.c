#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 100 	//�洢�ռ��ʼ������
#define INCREMENT 10  	//�洢�ռ��������
#define MAXLEN 15		//�Թ���ǽ���������

int X,Y,Z,X1,Y1;
int i,j,n;

typedef int Status;
typedef struct{
	int x;				//ͨ��������λ�õġ��С�
	int y;				//ͨ��������λ�õġ��С�
}PosType;

typedef struct{
    int x;
    int y;
    int adr[MAXLEN][MAXLEN];
}MazeType;  			//�Թ�����

typedef struct{
	int ord;			//ͨ������·���ϵġ���š�
	PosType seat;		//ͨ������·���ϵġ�����λ�á�
	int di;				//�Ӵ�ͨ����������һͨ����ġ�����
}SElemType;

typedef struct node{
    SElemType data;
	struct node *next;
}Stack;
/*
��Ϊ������ȥ��д��ջ���Ҿ��Լ�����д��һ��������ĳ���Ҳ��Ӧ�������˸ı�
�Լ����ջ�Ķ�����Ҳ�޸��ˣ��ҿ���д��Ӧ����һ�������Ŀռ�洢��ջ�����ʱ���ұȽ��Ƽ�����ָ����ָ��ջ����ջ�� 
���ڱ�����˵���̶����ȵ�ջ�����Ǻܺ�,�Լ�������ĿҪ�����������͵� 
���޸ĵ�ʱ������������д�ģ����û�б���= =����ʵ���Ǿ�������дһ���ȽϿ��
��д��ջ�������¼�������
1.��ʼ��һ��ջ
2.�ж�ջ�Ƿ�Ϊ��
3.ѹջ
4.��ջ
5.����ջ
6.��ȡջ�� 
*/

Stack* InitStack(){
	Stack *sh = (Stack *)malloc(sizeof(Stack));
	if(sh == NULL){
		printf("�ڴ����ʧ�ܣ�\n");
		return sh;
	}
	
	PosType t = {0, 0};
	SElemType tmp = {0, t, 0};
	
	sh -> data = tmp;
	sh -> next = NULL;
	
	return sh;
}
int isEmpty(Stack* S){
	if(S -> next == NULL)
		return TRUE;
	return FALSE;
}
Stack* Push(Stack *S, SElemType data){
	Stack *p = (Stack *)malloc(sizeof(Stack));
	if(p == NULL) return S;
	p -> next = S -> next;
	S -> next = p;
	p -> data = data;
	return S;
}
Stack* Pop(Stack *S){
	if(isEmpty(S)) return S;
	Stack *p = S -> next;
	S -> next = p -> next;
	free(p);
	return S;
}
void Clear(Stack *S){
	Stack *p = S -> next, *q;
	while(p){
		q = p -> next;
		free(p);
		p = q;
	}
	free(S);
}
SElemType top(Stack *S){
	SElemType tmp = {0, 0, 0, 0};
	if(isEmpty(S)) return tmp;
	return S -> next -> data;
}

Status pass(MazeType maze, PosType curpos)
{
    if(maze.adr[curpos.x][curpos.y] == 0)
        return TRUE;
    return FALSE;
}//�ж��Ƿ����ͨ��

Status FootPrint(MazeType maze,PosType curpos)
{
    maze.adr[curpos.x][curpos.y]=2;
    return OK;
}
//�߹����ҿ���ͨ��

Status MarkPrint(MazeType maze,PosType curpos)
{
    maze.adr[curpos.x][curpos.y]=8;//"8"��ʾ���߹�����ͨ
    return OK;
}//���߹�����ͨ���±�ǲ�����OK

PosType NextPos(PosType cpos, int i)
{
    switch(i){        //1.2.3�ֱ��ʾ�ҡ��¡���
        case 1 : cpos.y += 1; break;
        case 2 : cpos.x += 1; break;
        case 3 : cpos.y -= 1; break;
        case 4 : cpos.x -= 1; break;
        default: exit(ERROR);
    }
    return cpos;
}////̽����һλ�ò�������һλ�õ�����

Status MazePath(MazeType maze, PosType start, PosType end){
    //�Թ�maze���ڴ����start��end��ͨ�������һ�������ջ��
    Stack *S;
    
    PosType curpos;
    int curstep = 1;
    int vis[MAXLEN][MAXLEN] = {0};
    
	SElemType e;
    /*	ord;	//ͨ������·���ϵġ���š�
    	seat;	//ͨ������·���ϵġ�����λ�á�
    	di;		//�Ӵ�ͨ����������һͨ����ġ�����
	*/
    S = InitStack();
    curpos = start; //����"��ǰλ��"Ϊ"���λ��
    
    e.ord = curstep;
	e.seat = curpos;
	e.di = 1;//��ǰ����1.2.3.4�ֱ��ʾ�ҡ��¡�����
	Push(S,e);              //����·��
    vis[start.x][start.y] = 1;
    
	while(isEmpty(S)){
    	e = top(S);
	    if(e.seat.x == end.x && e.seat.y == end.y) {
	    	Clear(S);
	    	return;
		}
	    
    	for( ; e.di <= 4; ++e.di){
    		curpos = NextPos(curpos, e.di);
    		if(pass(maze, curpos)){
    			
			}
		}
	}
    
	do{
        for( ; e.di <= 4; e.di++)
        {
            curpos = NextPos(curpos, e.di); //��һλ���ǵ�ǰλ�õ�����
            if(pass(maze,curpos))
            {
				FootPrint(maze,curpos);
                Push(S,e);
				curstep++;
                break;
			}
            //̽����һ��
            else if(curpos.x == end.x && curpos.y == end.y)
				return TRUE;//�������
            else{
            	Pop(S);
			}
        }
	}while(curpos.x != end.x && curpos.y != end.y);
    return OK;
}//MazePath

void PrintMaze(MazeType maze){ //
    int i,j;
    printf("��2�����Թ��Ĵ���ڵ����ڵ�һ��·��\n");
   	printf("��1����ǽ�Ͳ�ͨ�ĵط���8�������߹���ͨ���鵫��ͨ\n");
   	printf("��0�������ͨ����ͨ����\n");
   	printf("����Ϊ�Թ���\n");
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++)
            printf("%4d",maze.adr[i][j]);//����Թ�
        printf("\n\n");
    }
}
void Printpath(MazeType maze){
   	printf("ͨ�������꣺");
   	for(i=0;i<X;i++)
    	for(j=0;j<Y;j++)
     		if(maze.adr[i][j]==2)
      			printf("(%d,%d)",i,j);
}//PrintMaze
void main(){     //������
    MazeType maze;
    PosType start,end;

	printf("�������Թ���������������\n");
	scanf("%d,%d", &X, &Y);
    maze.x = X; maze.y = Y; //�Թ��к�����
    
	for(i = 0; i < Y; i ++){//�Թ�����ǽ
        maze.adr[0][i] = 1;
        maze.adr[X-1][i] = 1;
    }
    for(i = 0; i < X; i++){//�Թ�����ǽ
        maze.adr[i][0] = 1;
        maze.adr[i][Y-1] = 1;
    }
    for(i = 1; i < X - 1; i++)
        for(j = 1; j < Y - 1; j++)
            maze.adr[i][j] = 0;//��ʼ���Թ�
  //�趨ͨ�����ϵĲ�ͨ��·��
	
	printf("�������Թ��е��ϰ���Ŀ��\n");
	scanf("%d", &Z);
	for (n = 0; n < Z; n++)
	{
		printf("�������Թ����ϰ�������λ�õ�����x,y(�����1��ʼ)��\n");
		scanf("%d,%d", &X1, &Y1);
		maze.adr[X1][Y1] = 1;
	}
	PrintMaze(maze);
	
	int a,b,c,d;
	printf("������һ�������յ�(a,b)(c,d)\n");
	scanf(" (%d,%d)(%d,%d)",&a,&b,&c,&d);
	
	start.x = a; start.y = b;
	end.x = c; end.y = d;
	system("pause");
	
	MazePath(maze, start, end);
	
	system("pause");
	PrintMaze(maze);
	
	system("pause");
	Printpath(maze);//��ӡ·��
}
