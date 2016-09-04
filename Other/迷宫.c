#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 100 	//存储空间初始分配量
#define INCREMENT 10  	//存储空间分配增量
#define MAXLEN 15		//迷宫外墙最大行列数

int X,Y,Z,X1,Y1;
int i,j,n;

typedef int Status;
typedef struct{
	int x;				//通道块坐标位置的“行”
	int y;				//通道块坐标位置的“列”
}PosType;

typedef struct{
    int x;
    int y;
    int adr[MAXLEN][MAXLEN];
}MazeType;  			//迷宫类型

typedef struct{
	int ord;			//通道块在路径上的“序号”
	PosType seat;		//通道块在路径上的“坐标位置”
	int di;				//从此通道块走向下一通道块的“方向”
}SElemType;

typedef struct node{
    SElemType data;
	struct node *next;
}Stack;
/*
因为看不下去你写的栈，我就自己重新写了一个，后面的程序也相应的做出了改变
以及你的栈的定义我也修改了，我看你写的应该是一个连续的空间存储的栈，这个时候我比较推荐不用指针来指向栈顶和栈底 
对于本题来说，固定长度的栈并不是很好,以及看了题目要求是链表类型的 
我修改的时候尽量保持了你写的，如果没有保持= =嘛其实我是觉得我重写一个比较快的
我写的栈包括以下几个功能
1.初始化一个栈
2.判断栈是否为空
3.压栈
4.出栈
5.清理栈
6.获取栈首 
*/

Stack* InitStack(){
	Stack *sh = (Stack *)malloc(sizeof(Stack));
	if(sh == NULL){
		printf("内存分配失败！\n");
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
}//判断是否可以通过

Status FootPrint(MazeType maze,PosType curpos)
{
    maze.adr[curpos.x][curpos.y]=2;
    return OK;
}
//走过并且可以通过

Status MarkPrint(MazeType maze,PosType curpos)
{
    maze.adr[curpos.x][curpos.y]=8;//"8"表示曾走过但不通
    return OK;
}//曾走过但不通留下标记并返回OK

PosType NextPos(PosType cpos, int i)
{
    switch(i){        //1.2.3分别表示右、下、左
        case 1 : cpos.y += 1; break;
        case 2 : cpos.x += 1; break;
        case 3 : cpos.y -= 1; break;
        case 4 : cpos.x -= 1; break;
        default: exit(ERROR);
    }
    return cpos;
}////探索下一位置并返回下一位置的坐标

Status MazePath(MazeType maze, PosType start, PosType end){
    //迷宫maze存在从入口start到end的通道则求得一条存放在栈中
    Stack *S;
    
    PosType curpos;
    int curstep = 1;
    int vis[MAXLEN][MAXLEN] = {0};
    
	SElemType e;
    /*	ord;	//通道块在路径上的“序号”
    	seat;	//通道块在路径上的“坐标位置”
    	di;		//从此通道块走向下一通道块的“方向”
	*/
    S = InitStack();
    curpos = start; //设置"当前位置"为"入口位置
    
    e.ord = curstep;
	e.seat = curpos;
	e.di = 1;//当前数字1.2.3.4分别表示右、下、左、上
	Push(S,e);              //加入路径
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
            curpos = NextPos(curpos, e.di); //下一位置是当前位置的右邻
            if(pass(maze,curpos))
            {
				FootPrint(maze,curpos);
                Push(S,e);
				curstep++;
                break;
			}
            //探索下一步
            else if(curpos.x == end.x && curpos.y == end.y)
				return TRUE;//到达出口
            else{
            	Pop(S);
			}
        }
	}while(curpos.x != end.x && curpos.y != end.y);
    return OK;
}//MazePath

void PrintMaze(MazeType maze){ //
    int i,j;
    printf("用2代表迷宫的从入口到出口的一条路径\n");
   	printf("用1代表墙和不通的地方用8代表曾走过的通道块但不通\n");
   	printf("用0代表可以通过的通道块\n");
   	printf("以下为迷宫：\n");
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++)
            printf("%4d",maze.adr[i][j]);//输出迷宫
        printf("\n\n");
    }
}
void Printpath(MazeType maze){
   	printf("通道块坐标：");
   	for(i=0;i<X;i++)
    	for(j=0;j<Y;j++)
     		if(maze.adr[i][j]==2)
      			printf("(%d,%d)",i,j);
}//PrintMaze
void main(){     //主函数
    MazeType maze;
    PosType start,end;

	printf("请输入迷宫的行数与列数：\n");
	scanf("%d,%d", &X, &Y);
    maze.x = X; maze.y = Y; //迷宫行和列数
    
	for(i = 0; i < Y; i ++){//迷宫行外墙
        maze.adr[0][i] = 1;
        maze.adr[X-1][i] = 1;
    }
    for(i = 0; i < X; i++){//迷宫列外墙
        maze.adr[i][0] = 1;
        maze.adr[i][Y-1] = 1;
    }
    for(i = 1; i < X - 1; i++)
        for(j = 1; j < Y - 1; j++)
            maze.adr[i][j] = 0;//初始化迷宫
  //设定通道块上的不通的路块
	
	printf("请输入迷宫中的障碍数目：\n");
	scanf("%d", &Z);
	for (n = 0; n < Z; n++)
	{
		printf("请输入迷宫中障碍物所在位置的坐标x,y(坐标从1开始)：\n");
		scanf("%d,%d", &X1, &Y1);
		maze.adr[X1][Y1] = 1;
	}
	PrintMaze(maze);
	
	int a,b,c,d;
	printf("请输入一组起点和终点(a,b)(c,d)\n");
	scanf(" (%d,%d)(%d,%d)",&a,&b,&c,&d);
	
	start.x = a; start.y = b;
	end.x = c; end.y = d;
	system("pause");
	
	MazePath(maze, start, end);
	
	system("pause");
	PrintMaze(maze);
	
	system("pause");
	Printpath(maze);//打印路径
}
