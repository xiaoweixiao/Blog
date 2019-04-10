#include<iostream>
#include<vector>
using namespace std;

vector<int> mode(80);

void Mode()
{
	mode[0] = 1;
	mode[1] = 1;
	for (int i = 2; i < 80; i++)
		mode[i] = mode[i - 1] + mode[i - 2];
}
int main()
{
	int from, to;
	Mode();
	while (cin >> from >> to)
	{
		int ret = 0;
		for (int i = from - 1; i < to; i++)
			ret += mode[i];
		cout << ret << endl;
	}

	return 0;
}