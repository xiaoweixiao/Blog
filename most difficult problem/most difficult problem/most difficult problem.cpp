#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	string s;
	while (getline(cin, str) && str != "")
	{
		s.insert(s.end(), str.begin(), str.end());
		s += '3';
	}

	size_t begin = 0;
	size_t end = 1;
	while (end<s.size())
	{
		if (s[end] == '3')
		{
			str = s.substr(begin, end - begin);
			if (end + 1 < s.size())
			{
				begin = end + 1;
				end = begin + 1;
			}
			else
				break;
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i]>'E'&&str[i] <= 'Y')
					str[i] -= 5;
				else if (str[i] >= 'A'&&str[i] <= 'E')
					str[i] += 21;
			}
			cout << str << endl;
		}
		else
			end++;
	}
}