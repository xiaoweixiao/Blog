//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	/**
//	*  ����λ�϶�����������ż��λ�϶���ż��
//	*  ���룺����arr�����ȴ���2
//	*  len��arr�ĳ���
//	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
//	*/
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		int even = 0;
//		int odd = 1;
//		while (even<len&&odd<len)
//		{
//			if (arr[even] % 2 == 0)//ż��λ��ż��
//				even += 2;
//			if (arr[odd] % 2 == 1)//����λ������
//				odd += 2;
//			if (arr[even] % 2 == 1 && arr[odd] % 2 == 0)//ż��λ����������������λ��ż��
//			{
//				swap(arr[even], arr[odd]);
//				even += 2, odd += 2;
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> in{ 1, 2, 3, 4 };
//	s.oddInOddEvenInEven(in,4);
//}

#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n != 0)
	{
		int left = 0;
		int first = n / 5;
		while (n)
		{
			left += n % 5;
			n /= 5;
		}
		cout << first << ' ' << left << endl;
	}
}