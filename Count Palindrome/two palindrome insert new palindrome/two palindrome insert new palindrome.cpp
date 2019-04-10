#include<iostream>
#include<string>
using namespace std;
bool IsPalindrome(string& add)
{
	int front = 0;
	int last = add.size() - 1;
	while (front <= last)
	{
		if (add[front] != add[last])
			return false;
		else
			front++, last--;
	}
	return true;
}
int main()
{
	int ret = 0;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (size_t i = 0; i <= s1.size(); i++)
	{
		string add(s1);
		add.insert(i, s2);
		if (IsPalindrome(add))
			ret++;
	}
	cout << ret << endl;
	system("pause");
}