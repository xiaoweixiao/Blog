//#include <iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string s, table = "0123456789ABCDEF";
//	int m, n;
//	cin >> m >> n;
//	bool flag = false;
//		// ����Ǹ�������ת�������������һ��
//	if (m < 0)
//	{
//		m = 0 - m;
//		flag = true;
//	}
//	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s
//	while (m)
//	{
//		s += table[m%n];
//		m /= n;
//	}
//	if (flag)
//		s += '-';
//	reverse(s.begin(), s.end());
//	cout << s << endl;
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string mode = "0123456789ABCDEF";
	string ret;
	int num, w;//��numת����w����
	cin >> num >> w;
	bool minus = false;//�Ƿ�Ϊ����
	if (num < 0)
	{
		num = -num;
		minus = true;
	}
	while (num)
	{
		ret = mode[num%w] + ret;//�ɵ�λ���λ
		num /= w;
	}
	if (minus)
		ret = '-' + ret;
	cout << ret << endl;
	return 0;
}