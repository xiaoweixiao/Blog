#include<iostream>
#include<vector>
using namespace std;
bool IsSu(int i)
{
	for (int j = 2; j < i; j++)
	{
		if (i%j == 0)
			return false;
	}
	return true;
}
int Count(int n)
{
	int ret = 0;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0 && IsSu(i))
			ret++;
	}
	return ret;
}
int main()
{
	int tmp;
	vector<int> in;
	while (cin >> tmp)
		in.push_back(tmp);

	for (size_t i = 0; i < in.size(); i++)
		cout << Count(in[i]) << endl;

	return 0;
}