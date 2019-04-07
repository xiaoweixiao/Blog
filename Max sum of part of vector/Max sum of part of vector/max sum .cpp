#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> in(n);
	for (int i = 0; i < n; i++)
		cin >> in[i];

	int max = in[0];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += in[i];
		if (sum>max)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << max << endl;
	return 0;
}