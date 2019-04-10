#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<size_t> in;
	vector<int> mode;
	mode.push_back(1);//下标是0
	mode.push_back(2);

	while (cin >> n&&n!=0)
		in.push_back(n);

	for (size_t i = 0; i < in.size(); i++)
	{
		if (in[i]>mode.size())//in[i]个斐波那契数的下标是in[i]-1，mode的最后一个元素是mode.size()-1
		{
			for (int j = mode.size();mode.size()!=in[i]; j++)
			{
				int num = mode[j - 1] + mode[j - 2];
				mode.push_back(num);
			}
		}
		cout << mode[in[i] - 1] << endl;
	}
	system("pause");
}