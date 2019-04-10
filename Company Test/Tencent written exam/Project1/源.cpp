//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	string s;
//	cin >> n;
//	cin >> s;
//	bool has = 1;
//	while (has)
//	{
//		string::iterator cur = s.begin();
//		string::iterator next = cur + 1;
//		
//		while (next != s.end())
//		{
//			has = false;
//			if ((*next == '0'&&*cur == '1') || (*next == '1'&&*cur == '0'))
//			{
//				has = true;
//				cur = s.erase(cur);//删除位置的新元素
//				s.erase(cur);
//				if (s.size() >= 2)
//				{
//					cur = s.begin();
//					next = cur + 1;
//				}
//				else
//				{
//					cout << s.size() << endl;
//					return 0;
//				}
//			}
//			else
//				cur++, next++;
//		}
//	}
//	cout << s.size() << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> fight(N);
	vector<int> money(N);
	for (int i = 0; i < N; i++)
		cin >> fight[i];
	for (int i = 0; i < N; i++)
		cin >> money[i];

	int less = money[0];//第一个怪兽必须贿赂
	int niu = fight[0];
	for (int i = 1; i < N; i++)
	{
		//从第一只怪兽开始
		if (fight[i]>niu)
		{
			less += money[i];
			niu += fight[i];
		}
		else
		{
			if (i + 1 < N)
			{
				if (niu + fight[i] > fight[i + 1] && money[i] < money[i + 1])
				{
					less += money[i];
					niu += fight[i];
				}
			}
		}
	}
	cout << less << endl;
	system("pause");
}