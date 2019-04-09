//#include <iostream>
//#include <vector>
//using namespace std;
///*
//* 基本思想：典型的迷宫问题，DFS穷举所有路径，找出剩余体力最多的路径
//*/
//#define VISITED 2
//int m, n, P; // 输入m，n，P
//int maze[10][10]; // 迷宫地图
//int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } }; // 左，右，上，下移动，例如：{0, -1}
//int cost[4] = { -1, -1, -3, 0 }; // 左，右，上，下移动的体力消耗，例如：{0， -1}对应-1
//int final_P = -200; // 剩余的体力值，初始为较小的数，保证final_P被正确更新
//// 存储各点的数据结构
//struct mazePoint {
//	mazePoint(int _x, int _y) : x(_x), y(_y) {}
//	int x, y;
//};
//// 存储每次遍历到的路径
//vector<mazePoint> pathStack;
//// 存储最终的最优路径
//vector<mazePoint> minCostPath;
//// 函数：打印路径
//void printPath(const vector<mazePoint>& path) {
//	for (int i = 0; i < path.size(); ++i) {
//		cout << "[" << path[i].x << "," << path[i].y << "]";
//		if (i < path.size() - 1) {
//			cout << ",";
//		}
//	}
//}
//// 函数：寻找最优路径
//void search(int x, int y, int cur_P)
//{
//	// 将当前点加入路径并标记为VISITED
//	pathStack.push_back(mazePoint(x, y));
//	maze[x][y] = VISITED;
//	// 如果当前点为出口且当前体力值>=0，则更新final_P与minCostPath，并返回
//	if (x == 0 && y == m - 1 && cur_P >= 0)
//	{
//		if (cur_P > final_P)
//		{
//			final_P = cur_P;
//			minCostPath = pathStack;
//		}
//		pathStack.pop_back(); // 为了回退至之前的节点，将当前结点弹出
//		maze[x][y] = 1; // 注意：之前maze[x][y]被标记为VISITED（值为2），回退后应该将其还原
//		return;
//	}
//	// 如果当前点并非出口且当前体力值>=0，则分别向左右上下四个方向探索，并计算相应的消耗
//	// 如果新的点在边界内且为可达点，递归调用search函数
//	if (cur_P > 0)
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			int nx = x + dir[i][0];
//			int ny = y + dir[i][1];
//			int nP = cur_P + cost[i];
//			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1)
//				search(nx, ny, nP);
//		}
//	}
//	pathStack.pop_back(); // 为了回退至之前的节点，将当前结点弹出
//	maze[x][y] = 1; // 注意：之前maze[x][y]被标记为VISITED（值为2），回退后应该将其还原为1
//}
//// 主函数
//int main()
//{
//	cin >> n >> m >> P;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//			cin >> maze[i][j];
//	}
//	search(0, 0, P);
//	if (final_P != -200) // 如果final_P更新过，输出最优路径
//		printPath(minCostPath);
//	else // 如果final_P为初始值-200，代表其没有被更新过，也就意味着没有可行路径
//		cout << "Can not escape!";
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

#define Went 2
int n, m, p;

struct Point{
	Point(int x_, int y_) :x(x_), y(y_){}
public:
	int x;
	int y;
};

vector<Point> MinPowerPath;
int Left_P = -2000;
vector<Point> Path;
int maze[10][10];

int go[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };//上下左右
int cost[4] = { -3, 0, -1, -1 };//上、下、左、右

void Walk(int x, int y, int Cur_P)
{
	Path.push_back(Point(x, y));
	maze[x][y] = Went;

	if (x == 0 && y == m - 1 && Cur_P >= 0)//到达出口，还活着
	{
		if (Cur_P > Left_P)//当前体力大于Left_P
		{
			MinPowerPath = Path;
			Left_P = Cur_P;
		}
		Path.pop_back();
		maze[x][y] = 1;//可到达
		return;
	}
	else if (Cur_P>0)
	{
		for (int i = 0; i < 4; i++)//遍历go数组，模拟走迷宫
		{
			int nx = x + go[i][0];
			int ny = y + go[i][1];
			int np = Cur_P + cost[i];
			if (nx >= 0 && nx < n&&ny >= 0 && ny <= m&&maze[nx][ny]==1)
				Walk(nx, ny, np);
		}
	}
	Path.pop_back();
	maze[x][y] = 1;
}

void Print(vector<Point> path)
{
	for (size_t i = 0; i < path.size(); i++)
	{
		cout << '[' << path[i].x << ',' << path[i].y << ']';
		if (i < path.size() - 1)
			cout << ',';
	}
}

int main()
{
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;j++)
			cin >> maze[i][j];
	}

	Walk(0, 0, p);
	if (Left_P != -2000)
		Print(MinPowerPath);
	else
		cout << "Can not escape!" << endl;
	return 0;
}