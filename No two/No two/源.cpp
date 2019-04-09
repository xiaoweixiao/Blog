//#include<iostream>
//using namespace std;
//int a[1000][1000] = { 0 };
//int main()
//{
//	int w, h, res = 0;
//	cin >> w >> h;
//
//	for (int i = 0; i<w; i++)
//	{
//		for (int j = 0; j<h; j++)
//		{
//			if (a[i][j] == 0)
//			{
//				res++;
//				if ((i + 2)<w)
//					a[i + 2][j] = -1;
//				if ((j + 2)<h)
//					a[i][j + 2] = -1;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}
//


#include <iostream>
#include <vector>
using namespace std;
/*
* ����˼�룺���͵��Թ����⣬DFS�������·�����ҳ�ʣ����������·��
*/
#define VISITED 2
int m, n, P; // ����m��n��P
int maze[10][10]; // �Թ���ͼ
int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } }; // ���ң��ϣ����ƶ������磺{0, -1}
int cost[4] = { -1, -1, -3, 0 }; // ���ң��ϣ����ƶ����������ģ����磺{0�� -1}��Ӧ-1
int final_P = -200; // ʣ�������ֵ����ʼΪ��С��������֤final_P����ȷ����
// �洢��������ݽṹ
struct mazePoint {
	mazePoint(int _x, int _y) : x(_x), y(_y) {}
	int x, y;
};
// �洢ÿ�α�������·��
vector<mazePoint> pathStack;
// �洢���յ�����·��
vector<mazePoint> minCostPath;
// ��������ӡ·��
void printPath(const vector<mazePoint>& path) {
	for (int i = 0; i < path.size(); ++i) {
		cout << "[" << path[i].x << "," << path[i].y << "]";
		if (i < path.size() - 1) {
			cout << ",";
		}
	}
}
// ������Ѱ������·��
void search(int x, int y, int cur_P) 
{
	// ����ǰ�����·�������ΪVISITED
	pathStack.push_back(mazePoint(x, y));
	maze[x][y] = VISITED;
	// �����ǰ��Ϊ�����ҵ�ǰ����ֵ>=0�������final_P��minCostPath��������
	if (x == 0 && y == m - 1 && cur_P >= 0) 
	{
		if (cur_P > final_P) 
		{
			final_P = cur_P;
			minCostPath = pathStack;
		}
		pathStack.pop_back(); // Ϊ�˻�����֮ǰ�Ľڵ㣬����ǰ��㵯��
		maze[x][y] = 1; // ע�⣺֮ǰmaze[x][y]�����ΪVISITED��ֵΪ2�������˺�Ӧ�ý��仹ԭ
		return;
	}
	// �����ǰ�㲢�ǳ����ҵ�ǰ����ֵ>=0����ֱ������������ĸ�����̽������������Ӧ������
	// ����µĵ��ڱ߽�����Ϊ�ɴ�㣬�ݹ����search����
	if (cur_P > 0) 
	{
		for (int i = 0; i < 4; ++i) 
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nP = cur_P + cost[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1)
				search(nx, ny, nP);
		}
	}
	pathStack.pop_back(); // Ϊ�˻�����֮ǰ�Ľڵ㣬����ǰ��㵯��
	maze[x][y] = 1; // ע�⣺֮ǰmaze[x][y]�����ΪVISITED��ֵΪ2�������˺�Ӧ�ý��仹ԭΪ1
}
// ������
int main()
{
	cin >> n >> m >> P;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> maze[i][j];
	}
	search(0, 0, P);
	if (final_P != -200) // ���final_P���¹����������·��
		printPath(minCostPath);
	else // ���final_PΪ��ʼֵ-200��������û�б����¹���Ҳ����ζ��û�п���·��
		cout<<"Can not escape!";
	return 0;
}