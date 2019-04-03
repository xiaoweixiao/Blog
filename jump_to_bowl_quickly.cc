#include<iostream>
using namespace std;
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		double length = 2*3.14*r;
		if (length < n)
		{
			cout << "No" << endl;
			continue;
		}
		else
		{
			cout << "Yes" << endl;
			continue;
		}
	}
	system("pause");
	return 0;
}

