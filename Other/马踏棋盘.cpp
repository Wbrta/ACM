#include <cstring>
#include <iostream> 
using namespace std;

const int dir[][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};
pair<int, int> path[70];
bool flag;
bool vis[10][10];


//O(2 ^ 48);
bool Judge(){
	for(int i = 1; i <= 5; ++i){
		for(int j = 1; j <= 5; ++j){
			if(!vis[i][j]) return false;
		}
	}
	return true;
}
void dfs(int row, int col, int step){
	if(Judge()) {
		flag = true;
		return;
	}
	if(flag) return;
	path[step] = make_pair(row, col);
	for(int i = 0; i < 8; ++i){
		int nx = row + dir[i][0];
		int ny = col + dir[i][1];
		
		if(nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && !vis[nx][ny]){
			vis[nx][ny] = step + 1;
			dfs(nx, ny, step + 1);
			vis[nx][ny] = 0;
		}
	}
}

int main()
{
	int x, y;
	cout << "请输入一个8 * 8 的棋盘的一个位置(输入x, y)：";
	cin >> x >> y;
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;
	dfs(x, y, 1);
	for(int i = 1; i <= 5; ++i){
		for(int j = 1; j <= 5; ++j){
			cout << vis[i][j] << " ";
		}
	}
	return 0;
}
