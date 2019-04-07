//7 2
//111
//https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string out, s = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;

	bool flag = false;//默认不是负数
	if (M < 0)
	{
		flag = true;
		M = -M;
	}
	while (M)
	{
		out += s[M%N];
		M /= N;
	}

	if (flag)
		out += '-';
	reverse(out.begin(), out.end());
	cout << out << endl;
	return 0;
}
