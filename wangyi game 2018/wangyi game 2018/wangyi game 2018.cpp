//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> in(n);
//		for (int i = 0; i < n; i++)
//			getline(cin, in[i]);
//
//		for (int i = 0; i < n; i++)
//		{
//			if (in[i][0] >= '0' && in[i][0] <= '2')
//			{
//
//			}
//			else
//			{
//
//			}
//		}
//	}
//}

#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<list<int>> in(n);
	for (int j = 0; j < n; j++)
	{
		int len;
		cin >> len;
		for (int i = 0; i < len; i++)
		{
			int tmp;
			cin >> tmp;
			in[j].push_back(tmp);
		}
	}
	for (int j = 0; j < n; j++)
	{
		reverse(in[j].begin(), in[j].end());//ÄæÖÃ
		//È¥ÖØ
		list<int>::iterator it1 = in[j].begin();
		while (it1 != in[j].end())
		{
			list<int>::iterator it2 = ++it1;
			it1--;
			while(it2 != in[j].end())
			{
				if (*it2 == *it1)
				{
					in[j].erase(it2);
					list<int>::iterator it2 = ++it1;
					it1--;
				}
				else
					it2++;
			}
			it1++;
		}

		list<int>::iterator it = in[j].begin();
		while (it != in[j].end())
		{
			cout << *it << ' ';
			it++;
		}
		cout << endl;
	}
	system("pause");
}

