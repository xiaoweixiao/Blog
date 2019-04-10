//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int Count(string&s, string&t)
//{
//	if (t.size() > s.size())
//		return 0;
//
//	map<char, int> smap;
//	map<char, int> tmap;
//	for (size_t i = 0; i < s.size(); i++)
//		smap[s[i]]++;
//	for (size_t i = 0; i < t.size(); i++)
//		tmap[t[i]]++;
//
//	map<char, int>::iterator it1 = tmap.begin();
//	map<char, int>::iterator it0 = smap.begin();
//	int ret = s.size();
//	while (it1 != tmap.end())
//	{
//		int times = 0;
//		while (it0 != smap.end())
//		{
//			if ((*it1).first == (*it0).first)
//				times = (*it0).second / (*it1).second;
//			it0++;
//		}
//		if (times < ret)
//			ret = times;
//		it1++;
//	}
//	return ret;
//}
//int main()
//{
//	string s, t;
//	while (cin >> s>> t)
//	{
//		int ret = Count(s, t);
//		cout << ret << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Count(string&s, string&t)
{
	if (t.size() > s.size())
		return 0;

	vector<int> s_count(256), t_count(256);
	for (size_t i = 0; i < s.size(); i++)
		s_count[s[i]]++;
	for (size_t i = 0; i < t.size(); i++)
		t_count[t[i]]++;

	int ret = s.size();
	int times = 0;
	for (size_t i = 0; i < t_count.size(); i++)
	{
		if (t_count[i] != 0)
		{
			times = s_count[i] / t_count[i];
			if (times < ret)
				ret = times;
		}
	}
	return ret;
}
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int ret = Count(s, t);
		cout << ret << endl;
	}
	return 0;
}