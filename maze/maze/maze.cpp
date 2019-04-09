//#include <iostream>
//#include <vector>
//using namespace std;
///*
//* ����˼�룺���͵��Թ����⣬DFS�������·�����ҳ�ʣ����������·��
//*/
//#define VISITED 2
//int m, n, P; // ����m��n��P
//int maze[10][10]; // �Թ���ͼ
//int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } }; // ���ң��ϣ����ƶ������磺{0, -1}
//int cost[4] = { -1, -1, -3, 0 }; // ���ң��ϣ����ƶ����������ģ����磺{0�� -1}��Ӧ-1
//int final_P = -200; // ʣ�������ֵ����ʼΪ��С��������֤final_P����ȷ����
//// �洢��������ݽṹ
//struct mazePoint {
//	mazePoint(int _x, int _y) : x(_x), y(_y) {}
//	int x, y;
//};
//// �洢ÿ�α�������·��
//vector<mazePoint> pathStack;
//// �洢���յ�����·��
//vector<mazePoint> minCostPath;
//// ��������ӡ·��
//void printPath(const vector<mazePoint>& path) {
//	for (int i = 0; i < path.size(); ++i) {
//		cout << "[" << path[i].x << "," << path[i].y << "]";
//		if (i < path.size() - 1) {
//			cout << ",";
//		}
//	}
//}
//// ������Ѱ������·��
//void search(int x, int y, int cur_P)
//{
//	// ����ǰ�����·�������ΪVISITED
//	pathStack.push_back(mazePoint(x, y));
//	maze[x][y] = VISITED;
//	// �����ǰ��Ϊ�����ҵ�ǰ����ֵ>=0�������final_P��minCostPath��������
//	if (x == 0 && y == m - 1 && cur_P >= 0)
//	{
//		if (cur_P > final_P)
//		{
//			final_P = cur_P;
//			minCostPath = pathStack;
//		}
//		pathStack.pop_back(); // Ϊ�˻�����֮ǰ�Ľڵ㣬����ǰ��㵯��
//		maze[x][y] = 1; // ע�⣺֮ǰmaze[x][y]�����ΪVISITED��ֵΪ2�������˺�Ӧ�ý��仹ԭ
//		return;
//	}
//	// �����ǰ�㲢�ǳ����ҵ�ǰ����ֵ>=0����ֱ������������ĸ�����̽������������Ӧ������
//	// ����µĵ��ڱ߽�����Ϊ�ɴ�㣬�ݹ����search����
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
//	pathStack.pop_back(); // Ϊ�˻�����֮ǰ�Ľڵ㣬����ǰ��㵯��
//	maze[x][y] = 1; // ע�⣺֮ǰmaze[x][y]�����ΪVISITED��ֵΪ2�������˺�Ӧ�ý��仹ԭΪ1
//}
//// ������
//int main()
//{
//	cin >> n >> m >> P;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//			cin >> maze[i][j];
//	}
//	search(0, 0, P);
//	if (final_P != -200) // ���final_P���¹����������·��
//		printPath(minCostPath);
//	else // ���final_PΪ��ʼֵ-200��������û�б����¹���Ҳ����ζ��û�п���·��
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

int go[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };//��������
int cost[4] = { -3, 0, -1, -1 };//�ϡ��¡�����

void Walk(int x, int y, int Cur_P)
{
	Path.push_back(Point(x, y));
	maze[x][y] = Went;

	if (x == 0 && y == m - 1 && Cur_P >= 0)//������ڣ�������
	{
		if (Cur_P > Left_P)//��ǰ��������Left_P
		{
			MinPowerPath = Path;
			Left_P = Cur_P;
		}
		Path.pop_back();
		maze[x][y] = 1;//�ɵ���
		return;
	}
	else if (Cur_P>0)
	{
		for (int i = 0; i < 4; i++)//����go���飬ģ�����Թ�
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