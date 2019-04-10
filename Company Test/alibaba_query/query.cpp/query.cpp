#include<iostream>
#include<string>
using namespace std;
int main()
{
	string mode;
	string query;
	getline(cin, mode);
	getline(cin, query);

	string::iterator begin = mode.begin();
	string::iterator end = mode.begin();
	string::iterator cur = mode.begin();
	while (cur != mode.end())
	{
		if (*cur == '[')
		{
			begin = cur;
			while (*cur != '>')
				cur++;
			end = cur;
			mode.erase(begin, end);
		}
		else if (*cur == '<' || *cur == '>')
			mode.erase(cur);
		cur++;
	}

	size_t i = 0, j = 0;
	while (i<mode.size() && j<query.size())
	{
		if (mode[i] == query[j])
			i++, j++;
		else
		{
			for (size_t x = i; x < mode.size(); x++)
			{
				if (mode[x] == '|')
					i = x + 1;
				else
				{
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}
	cout << 1 << endl;
	return 0;
}