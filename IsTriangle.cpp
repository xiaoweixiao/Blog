#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a;
	vector<int> in;
	int i = 0;
	while (cin >> a)
	{
		i++;
		in.push_back(a);
		if (i % 3 == 0)//3	6	9
		{
			int c = in[i - 1], b = in[i - 2], a = in[i - 3];
			if (a + b > c&&a + c > b&&b + c > a)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}